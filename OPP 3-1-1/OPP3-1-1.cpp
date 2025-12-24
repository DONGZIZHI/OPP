#include <iostream>
#include "Operations.h"
#include "Utility.h"

using namespace std;

static void showMenu() {
    cout << "\n====== 高校一卡通消费管理系统 ======\n";
    cout << "1. 账户录入/开户\n";
    cout << "2. 充值（默认手续费率）\n";
    cout << "3. 充值（自定义手续费率）\n";
    cout << "4. 消费（不带地点/重载1）\n";
    cout << "5. 消费（带地点/重载2）\n";
    cout << "6. 按学号查询（const引用+const指针）\n";
    cout << "7. 查询全部账户\n";
    cout << "8. 报表输出\n";
    cout << "0. 退出\n";
}

int main() {
    Card* cards = nullptr;
    int size = 0, cap = 0;
    Operations::init(cards, size, cap);

    while (true) {
        try {
            showMenu();
            int op = Utility::readInt("请选择：");

            if (op == 0) break;

            if (op == 1) {
                Operations::addCard(cards, size, cap);
            }
            else if (op == 2) {
                int id = Utility::readInt("输入学号：");
                double amt = Utility::readDouble("输入充值金额(元)：");
                Operations::recharge(cards, size, id, amt); // 默认手续费率
            }
            else if (op == 3) {
                int id = Utility::readInt("输入学号：");
                double amt = Utility::readDouble("输入充值金额(元)：");
                double feeRate = Utility::readDouble("输入手续费率(例如0.02表示2%)：");
                Operations::recharge(cards, size, id, amt, feeRate);
            }
            else if (op == 4) {
                int id = Utility::readInt("输入学号：");
                double amt = Utility::readDouble("输入消费金额(元)：");
                Operations::consume(cards, size, id, amt); // 重载1
            }
            else if (op == 5) {
                int id = Utility::readInt("输入学号：");
                double amt = Utility::readDouble("输入消费金额(元)：");
                string place = Utility::readString("输入地点(如Canteen/Store/Print)：");
                Operations::consume(cards, size, id, amt, place.c_str()); // 重载2
            }
            else if (op == 6) {
                int id = Utility::readInt("输入学号：");
                Operations::queryById(cards, size, id);
            }
            else if (op == 7) {
                Operations::queryAll(cards, size);
            }
            else if (op == 8) {
                Operations::report(cards, size);
            }
            else {
                cout << "无效选项。\n";
            }
        }
        catch (const InsufficientBalanceException& e) {
            cout << "[消费异常] " << e.what() << "\n";
        }
        catch (const InputException& e) {
            cout << "[输入异常] " << e.what() << "\n";
        }
        catch (const bad_alloc& e) {
            cout << "[内存异常] 内存分配失败：" << e.what() << "\n";
            break; // 内存都不够了，退出更安全
        }
        catch (const exception& e) {
            cout << "[未知异常] " << e.what() << "\n";
        }
    }

    Operations::destroy(cards, size, cap);
    cout << "已退出系统。\n";
    return 0;
}
