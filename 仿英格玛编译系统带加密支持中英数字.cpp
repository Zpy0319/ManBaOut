#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <random>

using namespace std;

class FixedTEA {
private:
    uint32_t key[4];
    static const int tea_round = 16;
    static const uint32_t delta = 0x9e3779b9;

    void deriveKey(const string& keyStr) {
        string expandedKey = keyStr;
        while (expandedKey.length() < 16) {
            expandedKey += keyStr;
        }
        
        for (int i = 0; i < 4; i++) {
            key[i] = 0;
            for (int j = 0; j < 4; j++) {
                size_t index = (i * 4 + j) % expandedKey.length();
                key[i] = (key[i] << 8) | static_cast<uint8_t>(expandedKey[index]);
            }
        }
    }

public:
    FixedTEA(const string& keyStr) {
        deriveKey(keyStr);
    }

    void tea_encrypt(uint32_t* v) {
        uint32_t v0 = v[0], v1 = v[1], sum = 0;
        uint32_t k0 = key[0], k1 = key[1], k2 = key[2], k3 = key[3];
        
        for (int i = 0; i < tea_round; i++) {
            sum += delta;
            v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        }
        v[0] = v0;
        v[1] = v1;
    }

    void tea_decrypt(uint32_t* v) {
        uint32_t v0 = v[0], v1 = v[1];
        uint32_t sum = tea_round * delta;
        uint32_t k0 = key[0], k1 = key[1], k2 = key[2], k3 = key[3];
        
        for (int i = 0; i < tea_round; i++) {
            v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
            v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            sum -= delta;
        }
        v[0] = v0;
        v[1] = v1;
    }

    vector<uint8_t> encryptData(const vector<uint8_t>& data) {
        const int block_size = 8;
        
        vector<uint8_t> data_with_length;
        uint32_t length = data.size();
        data_with_length.push_back((length >> 24) & 0xFF);
        data_with_length.push_back((length >> 16) & 0xFF);
        data_with_length.push_back((length >> 8) & 0xFF);
        data_with_length.push_back(length & 0xFF);
        data_with_length.insert(data_with_length.end(), data.begin(), data.end());
        
        int padding_len = block_size - (data_with_length.size() % block_size);
        if (padding_len == 0) padding_len = block_size;
        
        vector<uint8_t> padded_data = data_with_length;
        for (int i = 0; i < padding_len; i++) {
            padded_data.push_back(static_cast<uint8_t>(padding_len));
        }

        vector<uint8_t> result;
        for (size_t i = 0; i < padded_data.size(); i += block_size) {
            uint32_t v[2] = {0, 0};
            
            for (int j = 0; j < 4; j++) {
                v[0] = (v[0] << 8) | padded_data[i + j];
            }
            for (int j = 0; j < 4; j++) {
                v[1] = (v[1] << 8) | padded_data[i + 4 + j];
            }
            
            tea_encrypt(v);
            
            for (int j = 0; j < 2; j++) {
                for (int k = 3; k >= 0; k--) {
                    result.push_back(static_cast<uint8_t>((v[j] >> (k * 8)) & 0xFF));
                }
            }
        }
        return result;
    }

    vector<uint8_t> decryptData(const vector<uint8_t>& data) {
        const int block_size = 8;
        if (data.size() % block_size != 0) {
            return vector<uint8_t>();
        }

        vector<uint8_t> result;
        for (size_t i = 0; i < data.size(); i += block_size) {
            uint32_t v[2] = {0, 0};
            
            for (int j = 0; j < 4; j++) {
                v[0] = (v[0] << 8) | data[i + j];
            }
            for (int j = 0; j < 4; j++) {
                v[1] = (v[1] << 8) | data[i + 4 + j];
            }
            
            tea_decrypt(v);
            
            for (int j = 0; j < 2; j++) {
                for (int k = 3; k >= 0; k--) {
                    result.push_back(static_cast<uint8_t>((v[j] >> (k * 8)) & 0xFF));
                }
            }
        }
        
        if (result.size() < 5) return vector<uint8_t>();
        
        int padding_len = result.back();
        if (padding_len <= 0 || padding_len > block_size) {
            return vector<uint8_t>();
        }
        
        for (int i = 1; i <= padding_len; i++) {
            if (result[result.size() - i] != padding_len) {
                return vector<uint8_t>();
            }
        }
        
        result.resize(result.size() - padding_len);
        
        if (result.size() < 4) return vector<uint8_t>();
        uint32_t data_length = (result[0] << 24) | (result[1] << 16) | (result[2] << 8) | result[3];
        
        if (data_length > result.size() - 4) {
            return vector<uint8_t>();
        }
        
        return vector<uint8_t>(result.begin() + 4, result.begin() + 4 + data_length);
    }
};

class StableCipher {
private:
    string currentKey;
    
public:
    StableCipher() {}
    
    bool setKey(const string& key) {
        if (key.length() != 6) {
            cout << "错误：密钥必须为6位" << endl;
            return false;
        }
        currentKey = key;
        return true;
    }
    
    vector<int> encryptNumbers(const vector<int>& numbers) {
        vector<uint8_t> data;
        for (int num : numbers) {
            if (num < 0 || num > 255) {
                num = 0;
            }
            data.push_back(static_cast<uint8_t>(num));
        }
        
        FixedTEA tea(currentKey);
        vector<uint8_t> encrypted = tea.encryptData(data);
        
        vector<int> result;
        for (uint8_t byte : encrypted) {
            result.push_back(static_cast<int>(byte));
        }
        
        return result;
    }
    
    vector<int> decryptNumbers(const vector<int>& numbers) {
        if (numbers.empty()) return vector<int>();
        
        vector<uint8_t> data;
        for (int num : numbers) {
            if (num < 0 || num > 255) {
                num = 0;
            }
            data.push_back(static_cast<uint8_t>(num));
        }
        
        FixedTEA tea(currentKey);
        vector<uint8_t> decrypted = tea.decryptData(data);
        
        if (decrypted.empty()) {
            return vector<int>();
        }
        
        vector<int> result;
        for (uint8_t byte : decrypted) {
            result.push_back(static_cast<int>(byte));
        }
        
        return result;
    }
};

class QilinLockSystem {
private:
    StableCipher cipher;
    
public:
    string encryptText(const string& key, const string& text) {
        if (!cipher.setKey(key)) {
            return "";
        }
        
        vector<int> encoded;
        for (unsigned char c : text) {
            encoded.push_back(static_cast<int>(c));
        }
        
        vector<int> encrypted = cipher.encryptNumbers(encoded);
        
        stringstream result;
        for (size_t i = 0; i < encrypted.size(); i++) {
            result << encrypted[i];
            if (i < encrypted.size() - 1) {
                result << " ";
            }
        }
        
        return result.str();
    }
    
    string decryptText(const string& key, const string& cipherText) {
        if (!cipher.setKey(key)) {
            return "错误：无效密钥";
        }
        
        vector<int> numbers;
        stringstream ss(cipherText);
        int num;
        
        while (ss >> num) {
            numbers.push_back(num);
        }
        
        vector<int> decryptedData = cipher.decryptNumbers(numbers);
        
        if (decryptedData.empty()) {
            return "错误：解密失败";
        }
        
        string result;
        for (int num : decryptedData) {
            if (num >= 0 && num <= 255) {
                result += static_cast<char>(num);
            } else {
                return "错误：无效字节值";
            }
        }
        
        return result;
    }
};

void runDefaultTest() {
    cout << "=== 稳定版加密系统测试 ===" << endl;
    
    QilinLockSystem system;
    string key = "123456";
    string testText = "测钟培源Hello123";
    
    cout << "测试密钥:****** "  << endl;
    cout << "测试文本:****** " << endl;
    
    string encrypted = system.encryptText(key, testText);
    cout << "加密结果:****** "  << endl;
    
    string decrypted = system.decryptText(key, encrypted);
    cout << "解密结果:****** " << endl;
    
    if (testText == decrypted) {
        cout << "? 测试通过!" << endl;
    } else {
        cout << "? 测试失败!" << endl;
        cout << "期望:****** "  << endl;
        cout << "实际:****** " << endl;
    }
}

void runCustomTest() {
    cout << "=== 自定义测试 ===" << endl;
    
    QilinLockSystem system;
    string key, testText;
    
    cout << "请输入6位验证码: ";
    getline(cin, key);
    
    if (key.length() != 6) {
        cout << "错误：验证码必须为6位" << endl;
        return;
    }
    
    cout << "请输入测试文本: ";
    getline(cin, testText);
    
    if (testText.empty()) {
        cout << "错误：测试文本不能为空" << endl;
        return;
    }
    
    cout << "测试密钥: " << key << endl;
    cout << "测试文本: " << testText << endl;
    
    string encrypted = system.encryptText(key, testText);
    if (encrypted.empty()) {
        cout << "加密失败" << endl;
        return;
    }
    
    cout << "加密结果: " << encrypted << endl;
    
    string decrypted = system.decryptText(key, encrypted);
    cout << "解密结果: " << decrypted << endl;
    
    if (testText == decrypted) {
        cout << "? 测试通过!" << endl;
    } else {
        cout << "? 测试失败!" << endl;
    }
}

void encryptText() {
    cout << "=== 文本加密 ===" << endl;
    
    QilinLockSystem system;
    string key, text;
    
    cout << "请输入6位验证码: ";
    getline(cin, key);
    
    if (key.length() != 6) {
        cout << "错误：验证码必须为6位" << endl;
        return;
    }
    
    cout << "请输入要加密的文本: ";
    getline(cin, text);
    
    if (text.empty()) {
        cout << "错误：文本不能为空" << endl;
        return;
    }
    
    string encrypted = system.encryptText(key, text);
    if (encrypted.empty()) {
        cout << "加密失败" << endl;
        return;
    }
    
    cout << "加密成功!" << endl;
    cout << "密文: " << encrypted << endl;
}

void decryptText() {
    cout << "=== 密文解密 ===" << endl;
    
    QilinLockSystem system;
    string key, cipherText;
    
    cout << "请输入6位验证码: ";
    getline(cin, key);
    
    if (key.length() != 6) {
        cout << "错误：验证码必须为6位" << endl;
        return;
    }
    
    cout << "请输入要解密的密文: ";
    getline(cin, cipherText);
    
    if (cipherText.empty()) {
        cout << "错误：密文不能为空" << endl;
        return;
    }
    
    string decrypted = system.decryptText(key, cipherText);
    cout << "解密结果: " << decrypted << endl;
}

void showMenu() {
    
    cout << "\n====================" << endl;
    cout << "   加密通信系统" << endl;
    cout << "====================" << endl;
    cout << "1. 输入文本和验证码，生成密文" << endl;
    cout << "2. 输入密文及验证码，生成文本" << endl;
    cout << "3. 自定义测试内容" << endl;
    cout << "4. 关闭程序" << endl;
    cout << "====================" << endl;
    cout << "请选择操作 (1-4): ";
}

int main() {
    cout <<"系统使用说明:"<<endl;
	cout<<"验证码为六位，可以是英文大小写和阿拉伯数字混搭"<<endl;
	cout<<"输入文本:允许中文字符，英文字符包括大小写，阿拉伯数字，中中文符号，英文符号，逗号，句号"<<endl<<endl;
    cout << "    加密通信系统" << endl;
    cout << "====================" << endl;
    
    // 运行默认测试
    runDefaultTest();
    
    cout << "\n=== Code Execution Successful ===" << endl;
    
    // 用户交互菜单
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区
        
        switch (choice) {
            case 1:
                encryptText();
                break;
            case 2:
                decryptText();
                break;
            case 3:
                runCustomTest();
                break;
            case 4:
                cout << "程序已关闭，感谢使用！" << endl;
                break;
            default:
                cout << "无效选择，请重新输入 (1-4)" << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}      
//https://www.programiz.com/cpp-programming/online-compiler/ 
//test:在当今数字化时代，信息安全至关重要。加密技术作为保护数据的核心手段，其发展历程可追溯至公元前400年的古希腊。现代加密算法如AES（Advanced Encryption Standard）已广泛应用于金融、军事及日常通信领域。测试一个加密系统时，需验证其能否正确处理混合字符集。例如，中文汉字如“安全”“协议”“密钥”需与英文术语如“Authentication”“Firewall”“Firewall”无缝兼容。同时，数字参数（如256位密钥、1024位RSA模数）和符号（如“@”、“#”、“+”）的编码一致性也不容忽视。
/*示例：
 验证码: 111111
请输入要加密的文本: 你好
加密成功!
密文: 14 234 39 124 130 69 18 3 143 236 252 10 132 94 246 77
222222
请输入要加密的文本: 你好
加密成功!
密文: 224 99 186 118 97 6 65 78 56 230 131 0 6 220 240 191
333333
请输入要加密的文本: 你好
加密成功!
密文: 139 170 94 85 173 45 126 137 90 126 217 135 48 136 56 170
444444
请输入要加密的文本: 你好
加密成功!
密文: 60 87 234 91 83 63 119 205 138 224 175 188 115 181 92 175
555555
请输入要加密的文本: 你好
加密成功!
密文: 40 172 110 110 144 190 137 26 85 131 19 130 152 22 108 52
666666
请输入要加密的文本: 你好
加密成功!
密文: 8 13 238 80 144 118 246 126 255 37 10 194 195 216 78 179
