#pragma once
#include <string>
#include <stdexcept>

class InsufficientBalanceException : public std::runtime_error {
public:
    explicit InsufficientBalanceException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InputException : public std::runtime_error {
public:
    explicit InputException(const std::string& msg)
        : std::runtime_error(msg) {}
};

namespace Utility {
    // 元 -> 分（要求 static_cast<int>）
    int yuanToFen(double yuan);

    // 金额打印保留两位小数（报表格式化）
    void printMoney(double x);

    // 安全输入：读 int / double / string，做基本校验
    int readInt(const std::string& prompt);
    double readDouble(const std::string& prompt);
    std::string readString(const std::string& prompt);

    // 清理输入流（输入错误时用）
    void clearInputStream();
}
