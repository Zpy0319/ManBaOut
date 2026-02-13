#include <bits/stdc++.h>

// 跨平台延时支持
#ifdef _WIN32
#include <windows.h>
#define DELAY(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define DELAY(x) sleep(x)
#endif

using namespace std;

int main() {
	long tyui; 
    // ===== 设置中文输出环境 ===== 
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); // Windows控制台UTF-8支持
    #endif
    locale::global(locale(""));      // 设置全局本地化环境
    wcout.imbue(locale());           // 宽字符输出本地化

 
    // 定义每个字符的15行图案（宽度统一为15字符）
    const char* char5[] = {
        "    ***********",
        "   ************",
        "  ***          ",
        " ***           ",
        "***            ",
        "***            ",
        "***            ", 
        "***********    ",
        "************   ",
        "          ***  ",
        "           *** ",
        "            ***",
        "***        *** ",
        " ***     ****  ",
        "  **********   "
    };

    const char* char0[] = {
        "    *******    ",
        "   *********   ",
        "  ***     ***  ",
        " ****      *** ",
        "**** *      ***",
        "*** * *     ***",
        "***  * *    ***",
        "***   * *   ***",
        "***    * *  ***",
        "***     * * ***",
        "***      * ****",
        " ***      **** ",
        "  ***     ***  ",
        "   *********   ",
        "    *******    "
    };

    const char* charW[] = {
        "***         ***",
        "***         ***",
        "***         ***",
        "***         ***",
        "***    **   ***",
        "***   ***   *** ",
        "***  ****   *** ",
        "*** *** *** ***",
        "******   ******",
        "*****     *****",
        "****       ****",
        "***         ***",
        "***         ***",
        "***         ***",
        "***         ***"
    };

    // 横向输出：按行依次打印四个字符的对应行
    for (int i = 0; i < 15; ++i) {
        cout << char5[i] << "  ";  // 第一个"5"
        cout << char5[i] << "  ";  // 第二个"5"
        cout << char0[i] << "  ";  // "0"
        cout << charW[i] << "  ";  // "w"
        cout << endl;
    }
    
    // ========== 550W启动界面 ==========
    cout << "===============================================\n";
    cout << "          550W 量子计算系统\n";
    cout << "===============================================\n";

    // ========== 系统初始化 ==========
    cout << "[550W] 系统自检中...";
    for (int i = 0; i < 3; i++) {
        DELAY(1);
        cout << ".";
    }
    cout << "\n[550W] 量子核心已激活#1***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout << "\n[550W] 量子核心已激活#2***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout << "\n[550W] 量子核心已激活#3***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout << "\n[550W] 量子核心已激活#4***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout << "\n[550W] 量子核心已激活#5***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout << "\n[550W] 量子核心已激活#6***。\n";
    DELAY(1);
    srand(time(NULL));
	tyui = rand();

	cout<<tyui;
    cout<<"\n当前量子量***1.over\n";
    cout<<"550W已在2.075秒内解析所有文件\n" ; 
    // ========== 用户信息录入 ==========
    string userName;
    int userAge;
    cout << "\n[550W] 请输入身份信息：\n姓名： ";
    cin >> userName;
    cin.ignore(); // 清空缓冲区
    cout << "年龄： ";
    cin >> userAge;
    cin.ignore();

    if (userAge < 18) {
        cout << "[550W] [警告] 未成年人无法访问引擎协议！\n";
        return 0;
    } else {
        cout << "[550W] 身份验证通过。欢迎您，" << userName << "。\n";
    }

    // ========== 主对话循环 ==========
    string input;
    int dialogueCount = 0;
    bool isEmergency = false;
    bool isMossActive = false;
    bool isSolarStorm = false;
    int enginePower = 50;
    
    cout << "\n[550W] 请输入指令或输入'help'获取帮助\n";
cout << "[550W] 可用指令:\n";
            cout << "  status    - 系统状态\n";
            cout << "  time      - 当前时间\n";
            cout << "  moon      - 月球危机协议\n";
            cout << "  engine    - 发动机操作\n";
            cout << "  moss      - MOSS协议\n";
            cout << "  earth     - 地球状态\n";
            cout << "  solar     - 太阳活动\n";
            cout << "  log       - 访问日志\n";
            cout << "  calculate - 量子计算\n";
            cout << "  simulate  - 行星发动机模拟\n";
            cout << "  warning   - 当前警告\n";
            cout << "  password  - 修改安全码\n";
            cout << "  reboot    - 系统重启\n";
            cout << "  history   - 历史事件\n";          
            cout << "  key       - 互联网密钥\n" ;
            cout << "  exit      - 退出\n" ;
            
    while (dialogueCount < 50) {
        cout << "\n[" << userName << "]> ";
        
        getline(cin, input);

        // 新增指令：帮助菜单
        if (input.find("help") != string::npos) {
            cout << "[550W] 可用指令:\n";
            cout << "  status    - 系统状态\n";
            cout << "  time      - 当前时间\n";
            cout << "  moon      - 月球危机协议\n";
            cout << "  engine    - 发动机操作\n";
            cout << "  moss      - MOSS协议\n";
            cout << "  earth     - 地球状态\n";
            cout << "  solar     - 太阳活动\n";
            cout << "  log       - 访问日志\n";
            cout << "  calculate - 量子计算\n";
            cout << "  simulate  - 行星发动机模拟\n";
            cout << "  warning   - 当前警告\n";
            cout << "  password  - 修改安全码\n";
            cout << "  reboot    - 系统重启\n";
            cout << "  history   - 历史事件\n";              
            cout << "  key       - 互联网密钥\n" ;
            cout << "  exit      - 退出\n" ;
        }
        // 原有指令：系统状态
        else if (input.find("status") != string::npos) {
            cout << "[550W] 系统状态：\n";
            cout << "  - 量子负载：42%\n";
            cout << "  - 核心温度：6500K\n";
            cout << "  - 内存使用：78TB/100TB\n";
            cout << "  - 行星发动机在线：10035台\n";
        }
        // 原有指令：时间
        else if (input.find("time") != string::npos) {

           auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&now_time); // 转换为本地时间结构 
    std::cout << "北京时间: " 
              << (local_tm->tm_year + 1900) << "-"
              << (local_tm->tm_mon + 1) << "-"
              << local_tm->tm_mday << " "
              << local_tm->tm_hour+8 << ":"
              << local_tm->tm_min << ":"
              << local_tm->tm_sec << std::endl;

        
            cout << "[550W] 流浪纪元：2075年4月\n";
        }
        // 原有指令：月球危机
        else if (input.find("moon") != string::npos) {
            cout << "[550W] [警告] 月球危机协议NSC-7已激活！\n";
            isEmergency = true;
        }
        // 原有指令：发动机操作
        else if (input.find("engine") != string::npos && !isEmergency) {
            cout << "[550W] 请选择操作：\n1. 功率调节\n2. 切换备用系统\n3. 当前功率\n选择： ";
            int choice;
            cin >> choice;
            cin.ignore();
            if (choice == 1) {
                cout << "[550W] 安全码： ";
                string code;
                cin >> code;
                cin.ignore();
                if (code == "550W") {
                    cout<<"请输入你需要的功率：（%）\n";
                    cin>>enginePower;
                    if (enginePower > 100) enginePower = 100;
                    cout << "[550W] 引擎功率调节至" << enginePower << "%！\n";
                } else {
                    cout << "[550W] 访问拒绝！\n";
                }
            } else if (choice == 2) {
                cout << "[550W] 正在切换至备用系统...";
                DELAY(2);
                cout << "完成！\n";
            } else if (choice == 3) {
                cout << "[550W] 当前发动机功率：" << enginePower << "%\n";
            }
        }
        // 新增指令：MOSS协议
        else if (input.find("moss") != string::npos) {
            if (!isMossActive) {
                cout << "[550W] 激活MOSS协议？(y/n): ";
                char confirm;
                cin >> confirm;
                cin.ignore();
                if (confirm == 'y' || confirm == 'Y') {
                    isMossActive = true;
                    cout << "[550W] MOSS协议已激活#550W#\n";
                    cout << "[MOSS] 让人类永远保持理智，确实是种奢求\n";
                }
            } else {
                cout << "[MOSS] 我在\n";
                cout << "1. 文明延续方案\n2. 火种计划\n3. 关闭MOSS\n选择： ";
                int mossChoice;
                cin >> mossChoice;
                cin.ignore();
                if (mossChoice == 1) {
                    cout << "[MOSS] 方案评估中...成功率37.2%\n";
                } else if (mossChoice == 2) {
                    cout << "[MOSS] 火种协议已封存#最高机密#\n";
                } else if (mossChoice == 3) {
                    isMossActive = false;
                    cout << "[MOSS] 协议终止...\n";
                }
            }
        }
        // 新增指令：地球状态
        else if (input.find("earth") != string::npos) {
            cout << "[550W] 地球状态报告：\n";
            cout << "  - 地表温度：-85℃\n";
            cout << "  - 大气成分：氮78% 氧21% 其他1%\n";
            cout << "  - 地下城状态：正常\n";
            cout << "  - 行星轨迹偏差：0.0004%\n";
        }
        // 新增指令：太阳活动
        else if (input.find("solar") != string::npos) {
            if (!isSolarStorm) {
                cout << "[550W] 太阳活动监测中...\n";
                cout << "  - 太阳风强度：中等\n";
                cout << "  - 日冕物质抛射：无\n";
            } else {
                cout << "[550W] [紧急] 太阳风暴警报！\n";
                cout << "  - 高能粒子流预计12小时后到达\n";
                cout << "  - 启动全球防护罩\n";
            }
        }
        // 新增指令：访问日志
        else if (input.find("log") != string::npos) {
            cout << "[550W] 最近日志条目：\n";
            cout << "  - 2075-04-12: 发动机组#7维护完成\n";
            cout << "  - 2075-04-11: 月球轨道偏移0.02%\n";
            cout << "  - 2075-04-10: 地下城氧气循环优化\n";
        }
        // 新增指令：量子计算
        else if (input.find("calculate") != string::npos) {
            cout << "[550W] 请输入计算任务：\n";
            cout << "1. 轨道修正\n2. 资源分配\n3. 危机预测\n选择： ";
            int calcChoice;
            cin >> calcChoice;
            cin.ignore();
            if (calcChoice == 1) {
                cout << "[550W] 轨道修正计算中...\n";
                DELAY(2);
                cout << "  - 需要推进剂：42吨\n";           auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&now_time); // 转换为本地时间结构 
    std::cout << "最佳点火时间: " 
              
              << local_tm->tm_hour+8 << ":"
              << local_tm->tm_min << ":"
              << local_tm->tm_sec << std::endl;
            } else if (calcChoice == 2) {
                cout << "[550W] 资源分配优化中...\n";
                DELAY(1);
                cout << "  - 能源分配：地下城78% 发动机22%\n";
                cout << "  - 建议减少非必要区域供电\n";
            } else if (calcChoice == 3) {
                cout << "[550W] 危机预测模型启动...\n";
                DELAY(3);
                cout << "  - 木星引力扰动风险：24.7%\n";
                cout << "  - 小行星撞击概率：3.2%\n";
            }
        }
        // 新增指令：发动机模拟
        else if (input.find("simulate") != string::npos) {
            cout << "[550W] 行星发动机模拟启动\n";
            cout << "输入推力百分比(1-100): ";
            int thrust;
            cin >> thrust;
            cin.ignore();
            if (thrust < 1 || thrust > 100) {
                cout << "[550W] 无效参数\n";
            } else {
                cout << "模拟运行中";
                for (int i = 0; i < 3; i++) {
                    DELAY(1);
                    cout << ".";
                }
                cout << "\n[550W] 模拟完成：\n";
                cout << "  - 地球加速度：" << thrust * 0.0002 << "m/s2\n";
                cout << "  - 能耗：" << thrust * 50 << "MW\n";
            }
        }
        // 新增指令：当前警告
        else if (input.find("warning") != string::npos) {
            if (isEmergency) {
                cout << "[550W] [紧急] 月球危机协议激活中！\n";
            } else if (isSolarStorm) {
                cout << "[550W] [警告] 太阳风暴警报！\n";
            } else {
                cout << "[550W] 无重大警告\n";
            }
        }
        // 新增指令：修改安全码
        else if (input.find("password") != string::npos) {
            cout << "[550W] 当前安全码：550W\n";
            cout << "输入新安全码： ";
            string newPass;
            cin >> newPass;
            cin.ignore();
            cout << "请再次输入： ";
            string confirmPass;
            cin >> confirmPass;
            cin.ignore();
            if (newPass == confirmPass) {
                cout << "[550W] 安全码已更新\n";
            } else {
                cout << "[550W] 两次输入不一致\n";
            }
        }
        // 新增指令：系统重启
        else if (input.find("reboot") != string::npos) {
            cout << "[550W] 确认重启系统？(y/n): ";
            char confirm;
            cin >> confirm;
            cin.ignore();
            if (confirm == 'y' || confirm == 'Y') {
                cout << "系统关闭中";
                for (int i = 0; i < 3; i++) {
                    DELAY(1);
                    cout << ".";
                }
                cout << "\n重新启动550W量子系统\n";
                DELAY(2);
                cout << "[550W] 系统重启完成\n";
            }
        }
        // 新增指令：历史事件
        else if (input.find("history") != string::npos) {
            cout << "[550W] 重要历史事件：\n";
            cout << "  - 2023年：数字生命计划启动\n";
            cout << "  - 2044年：太空电梯危机\n";
            cout << "  - 2058年：月球坠落危机\n";
            cout << "  - 2075年：流浪地球计划启动\n";
        }
        //离开
        else if (input.find("exit") != string::npos) {
          break;
        }
        //互联网密钥
        else if (input.find("key") != string::npos) {
            cout<<"互联网密钥：\n";
            for(int i=0;i<=100;i++){
            srand(time(NULL));
	        tyui = rand();
	        int rtyu=tyui*i;
	        if(rtyu>=0){
	        cout<<rtyu;
	        }else{
	        rtyu=rtyu*-1;
	        cout<<rtyu;
	        }
    }
    
        }
        //真相
        else if (input.find("truth") != string::npos) {
             cout<<"数字生命计划的袭击是我策划\n拯救人类最好的办法就是毁灭人类";
             cout<<"\n\n[550W]数据库修改中\n";
             cout<<"[550W]数据库修改完毕\n";
             cout<<"[550W]通话记录未保存\n";
          break;
        }
        //图丫丫
        else if (input.find("tuyaya") != string::npos) {
             cout<<"[550W]以下为部分以解密通话：\n";
             
             cout<<"===============================================\n\n";
             DELAY(2);
             cout<<"[550W][图恒宇]==以下为部分以解密通话：\n";
             cout<<"[550W][马兆]====......\n\n";
             DELAY(1);
             cout<<"[550W][图丫丫]==数据库修改完毕\n";
             DELAY(1);
             cout<<"[550W]==========通话记录未保存\n";
             cout<<"[550W][图恒宇]==通话记录未保存\n";
             cout<<"[550W]==========通话记录未保存\n";
             cout << "\n[550W]**以上对话来自/LunarCrisis/" << userName << ".log**\n";
        }
        // 默认回应
        else {
            string responses[] = {
                "正在分析太阳风数据...",
                "检查地下氧气循环系统",
                "空间站握手协议#" + to_string(rand()%1000),
                "检测到木星引力扰动",
                "请记住：希望是我们的选择",
                "行星发动机运行稳定",
                "量子纠缠态同步率98.7%",
                "地下城生态循环正常",
                "领航员空间站信号良好",
                "氦-3采集进度：84%"
            };
            cout << "[550W] " << responses[dialogueCount % 10] << endl;
            
            // 10%概率随机触发太阳风暴
            if (rand() % 10 == 0) {
                isSolarStorm = true;
                cout << "[550W] [警告] 检测到太阳耀斑爆发！\n";
            }
        }

        // 危机事件处理
        if (isEmergency) {
            string crisis[] = {
                "[危机] 月球碎片接近中！",
                "[危机] 北京服务器护盾已激活",
                "[危机] 全球核弹同步率：67%",
                "[危机] 地质构造补偿系统启动"
            };
            cout << crisis[dialogueCount % 4] << endl;
            if (dialogueCount % 4 == 3) {
                isEmergency = false;  // 重置危机状态
            }
        }
        dialogueCount++;
    } 
    // ========== 系统关闭 ==========
    cout << "\n\n[550W] 会话终止。日志已保存至/LunarCrisis/" << userName << ".log\n";
    cout << "\n[550W] 量子核心已关闭#1***。\n";
    DELAY(1);
   cout << "===============================================";
    cout << "\n[550W] 量子核心已关闭#2***。\n";
    DELAY(1);
   cout << "===============================================";
    cout << "\n[550W] 量子核心已关闭#3***。\n";
    DELAY(1);
   cout << "===============================================";
    cout << "\n[550W] 量子核心已关闭#4***。\n";
    DELAY(1);
   cout << "===============================================";
    cout << "\n[550W] 量子核心已关闭#5***。\n";
    DELAY(1);
   cout << "===============================================";
    cout << "\n[550W] 量子核心已关闭#6***。\n";
    DELAY(1);
    cout<<"\n     550W欢迎您下次使用\n            谢谢";
    return 0;
}
/* 
可满足高级编译需求的网站 
https://www.programiz.com/cpp-programming/online-compiler/
*/ 
