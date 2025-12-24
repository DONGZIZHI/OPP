#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

namespace Utility {

    int yuanToFen(double yuan) {
        // 例如 12.34 元 -> 1234 分（四舍五入这里用 +0.5 简化）
        // 重点：static_cast<int>
        return static_cast<int>(yuan * 100 + 0.5);
    }

    void printMoney(double x) {
        cout << fixed << setprecision(2) << x;
    }

    void clearInputStream() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int readInt(const string& prompt) {
        cout << prompt;
        int v;
        if (!(cin >> v)) {
            clearInputStream();
            throw InputException("输入的整数不合法。");
        }
        return v;
    }

    double readDouble(const string& prompt) {
        cout << prompt;
        double v;
        if (!(cin >> v)) {
            clearInputStream();
            throw InputException("输入的数字不合法。");
        }
        return v;
    }

    string readString(const string& prompt) {
        cout << prompt;
        string s;
        if (!(cin >> s)) {
            clearInputStream();
            throw InputException("输入的字符串不合法。");
        }
        return s;
    }
}
