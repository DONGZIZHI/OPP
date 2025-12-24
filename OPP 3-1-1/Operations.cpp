#include "Operations.h"
#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <new> // bad_alloc

using namespace std;

namespace Operations {

    static void ensureCapacity(Card*& arr, int& cap, int size) {
        if (size < cap) return;
        int newCap = (cap == 0) ? 4 : cap * 2;

        // 内存分配异常捕获点：new[] 可能抛 bad_alloc
        Card* newArr = nullptr;
        try {
            newArr = new Card[newCap];
        }
        catch (const bad_alloc&) {
            throw; // 交给上层统一捕获
        }

        for (int i = 0; i < size; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

    void init(Card*& arr, int& size, int& cap) {
        arr = nullptr;
        size = 0;
        cap = 0;
    }

    void destroy(Card*& arr, int& size, int& cap) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        cap = 0;
    }

    int findIndexById(const Card* arr, int size, int cardId) {
        for (int i = 0; i < size; i++) {
            if (arr[i].id == cardId) return i;
        }
        return -1;
    }

    void addCard(Card*& arr, int& size, int& cap) {
        int id = Utility::readInt("输入学号(卡号)：");
        if (findIndexById(arr, size, id) != -1) {
            throw InputException("该学号已存在，无法重复开户。");
        }

        string name = Utility::readString("输入姓名：");
        double bal = Utility::readDouble("输入初始余额(元)：");
        if (bal < 0) throw InputException("初始余额不能为负。");

        ensureCapacity(arr, cap, size);
        arr[size] = Card(id, name, bal);
        size++;

        cout << "开户成功：[" << id << "] " << name << " 余额=";
        Utility::printMoney(bal);
        cout << "\n";
    }

    void recharge(Card*& arr, int size, int cardId, double amount, double feeRate) {
        if (amount <= 0) throw InputException("充值金额必须为正。");
        if (feeRate < 0 || feeRate >= 1) throw InputException("手续费率不合法（应在[0,1)）。");

        int idx = findIndexById(arr, size, cardId);
        if (idx == -1) throw InputException("未找到该账户。");

        double fee = amount * feeRate;
        double net = amount - fee;

        arr[idx].balance += net;
        arr[idx].tradeCount++;

        cout << "充值成功：原始金额="; Utility::printMoney(amount);
        cout << " 手续费="; Utility::printMoney(fee);
        cout << " 实到="; Utility::printMoney(net);
        cout << " 当前余额="; Utility::printMoney(arr[idx].balance);
        cout << "\n";
    }

    // consume 重载 1：不带地点
    void consume(Card*& arr, int size, int cardId, double amount) {
        consume(arr, size, cardId, amount, "Unknown");
    }

    // consume 重载 2：带地点
    void consume(Card*& arr, int size, int cardId, double amount, const char* place) {
        if (amount <= 0) throw InputException("消费金额必须为正。");

        int idx = findIndexById(arr, size, cardId);
        if (idx == -1) throw InputException("未找到该账户。");

        if (arr[idx].balance < amount) {
            // 要求：余额不足抛异常
            throw InsufficientBalanceException("余额不足，无法完成消费。");
        }

        arr[idx].balance -= amount;
        arr[idx].tradeCount++;

        cout << "消费成功：地点=" << place << " 消费=";
        Utility::printMoney(amount);
        cout << " 当前余额=";
        Utility::printMoney(arr[idx].balance);
        cout << "（换算为分=" << Utility::yuanToFen(amount) << "）\n"; // 要求：static_cast<int> 元->分
    }

    void queryById(const Card* arr, int size, int cardId) {
        // 要求：const 指针查询 + const 引用展示
        int idx = findIndexById(arr, size, cardId);
        if (idx == -1) throw InputException("未找到该账户。");

        const Card* p = &arr[idx];   // 指向常量的指针
        const Card& c = *p;          // 常引用

        cout << "查询结果：学号=" << c.id << " 姓名=" << c.name << " 余额=";
        Utility::printMoney(c.balance);
        cout << " 交易次数=" << c.tradeCount << "\n";
    }

    void queryAll(const Card* arr, int size) {
        cout << left << setw(12) << "CardID"
            << setw(12) << "Name"
            << right << setw(12) << "Balance"
            << right << setw(12) << "Trades" << "\n";
        cout << string(48, '-') << "\n";

        for (int i = 0; i < size; i++) {
            const Card& c = arr[i]; // const 引用
            cout << left << setw(12) << c.id
                << setw(12) << c.name
                << right << setw(12);
            Utility::printMoney(c.balance);
            cout << right << setw(12) << c.tradeCount << "\n";
        }
    }

    void report(const Card* arr, int size) {
        // 要求：表格形式输出所有账户余额与交易次数，格式对齐，两位小数
        cout << "\n===== 报表输出（余额 & 交易次数）=====\n";
        queryAll(arr, size);

        double sumBal = 0.0;
        int sumTrades = 0;
        for (int i = 0; i < size; i++) {
            sumBal += arr[i].balance;
            sumTrades += arr[i].tradeCount;
        }
        cout << string(48, '-') << "\n";
        cout << left << setw(24) << "TOTAL"
            << right << setw(12);
        Utility::printMoney(sumBal);
        cout << right << setw(12) << sumTrades << "\n\n";
    }
}
