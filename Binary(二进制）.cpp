/* 
#include <iostream>
#include <bitset> // 用于将整数转换为二进制字符串
#include <string>

// 假设的函数，用于获取中文拼音的ASCII码值

int getPinyinASCII(const std::string& chinese) {
 
    return static_cast<int>(chinese[0]);
}

// 十进制转二进制
std::string decToBin(int n) {
    return std::bitset<32>(n).to_string(); // 转换为32位二进制字符串
}

int main() {
    int choice;
    std::cout << "请选择转换类型：\n1. 十进制转二进制\n2. 中文转拼音ASCII二进制\n(输入1或2)\n";
    std::cin >> choice;

    if (choice == 1) {
        int num;
        std::cout << "请输入一个十进制数：";
        std::cin >> num;
        std::string bin = decToBin(num);
        // 移除前导零
        bin.erase(0, bin.find_first_not_of('0'));
        std::cout << "二进制表示为：" << bin << std::endl;
    } else if (choice == 2) {
        std::string chinese;
        std::cout << "请输入一个中文汉字：";
        std::cin >> chinese;

        int asciiValue = getPinyinASCII(chinese);
        std::string bin = decToBin(asciiValue);
        // 移除前导零
        bin.erase(0, bin.find_first_not_of('0'));
        std::cout << "ASCII二进制表示为：" << bin << std::endl;
    } else {
        std::cout << "无效的选择" << std::endl;
    }

    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;
int getPinyinASCII(const std::string& chinese) {
 
    return static_cast<int>(chinese[0]);
}

// 十进制转二进制
std::string decToBin(int n) {
    return std::bitset<32>(n).to_string(); // 转换为32位二进制字符串
}

int main() {
	int ii;
	cout << "请选择转换类型：\n1. 十进制转二进制\n2. 英文单词的1ASCII二进制\n(输入1或2)\n";
	cin>>ii; 

    if(ii==1){

        int num;
        std::cout << "请输入一个十进制数：";
        std::cin >> num;
        std::string bin = decToBin(num);
        // 移除前导零
        bin.erase(0, bin.find_first_not_of('0'));
        std::cout << "二进制表示为：" << bin << std::endl;
    	}else if(ii==2){
		
    int decimalNumber;
   string englishSentence;

   
    // 输入一串英文句子并输出每个字符的ASCII码的二进制表示
    cout << "请输入一串英文单词: ";
cin>>englishSentence; // 这次直接读取整行
    for (double i = 0; i < englishSentence.length(); ++i) {
		char ch = englishSentence[i];
        bitset<8> binaryAscii(ch); // ASCII码是8位
        cout << "字符 '" << ch << "' 的ASCII码的二进制表示为: " << binaryAscii << endl;
    }
}/*else if(ii==114514){
	for (int i=1;i<=114514;i++){
		cout<<i<<".嘻嘻   ";
	}
}*/else{
	cout<<"请按规则";
} 
    return 0;
} 
