#pragma once
#include <string>

struct Card {
    int id;                 // 学号/卡号
    std::string name;       // 姓名
    double balance;         // 余额（元）
    int tradeCount;         // 交易次数（充值+消费）

    Card() : id(0), name(""), balance(0.0), tradeCount(0) {}
    Card(int _id, const std::string& _name, double _bal)
        : id(_id), name(_name), balance(_bal), tradeCount(0) {}
};
