#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int date;

    bool isLeap(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    int daysInMonth(int y, int m) const {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        if (m == 2) return isLeap(y) ? 29 : 28;
        return 0;
    }

public:
    void Init(int y, int m, int d) {
        if (m < 1 || m > 12) {
            year = y; month = 1; date = 1; return;
        }
        int lim = daysInMonth(y, m);
        if (d < 1 || d > lim) {
            year = y; month = m; date = 1; return;
        }
        year = y;
        month = m;
        date = d;
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDate() const { return date; }

    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDate(int d) { date = d; }

    void display() const {
        cout << year << "-";
        if (month < 10) cout << "0";
        cout << month << "-";
        if (date < 10) cout << "0";
        cout << date;
    }

    int calWeekday() const {
        int y = year;
        int m = month;
        int d = date;
        if (m == 1 || m == 2) {
            y -= 1;
            m += 12;
        }
        int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
        const char* s[7] = { "星期日","星期一","星期二","星期三","星期四","星期五","星期六" };
        cout << s[w];
        return w;
    }
};

int main() {
    Date d;
    int y, m, day;
    cin >> y >> m >> day;
    d.Init(y, m, day);
    d.display();
    cout << " ";
    d.calWeekday();
    cout << endl;
    return 0;
}
