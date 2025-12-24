#pragma once
#include "Card.h"

// Operations：账户与交易操作（动态数组管理、默认参数、重载、异常）
namespace Operations {

    // 动态数组初始化/释放
    void init(Card*& arr, int& size, int& cap);
    void destroy(Card*& arr, int& size, int& cap);

    // 账户录入与初始化（键盘输入：学号、姓名、初始余额）
    void addCard(Card*& arr, int& size, int& cap);

    // 充值：带默认参数的函数计算手续费
    // feeRate 默认 0.01 代表 1% 手续费（你也可以改成固定手续费）
    void recharge(Card*& arr, int size, int cardId, double amount, double feeRate = 0.01);

    // 消费：函数重载
    void consume(Card*& arr, int size, int cardId, double amount);                    // 纯金额
    void consume(Card*& arr, int size, int cardId, double amount, const char* place); // 带场景

    // 查询：const 引用 + 指向常量的指针（安全查询防误改）
    void queryById(const Card* arr, int size, int cardId);
    void queryAll(const Card* arr, int size);

    // 报表输出：余额与交易次数（对齐、两位小数）
    void report(const Card* arr, int size);

    // 工具：按 id 找下标（内部会用到）
    int findIndexById(const Card* arr, int size, int cardId);
}
