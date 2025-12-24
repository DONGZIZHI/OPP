#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    struct student {
        string name;
        double Chinese;
        double Math;
        double English;
    };

    student s[100];
    int t[100];
    double Average[100];

    for (int i = 0; i < n; i++) {
        cin >> s[i].name;
        cin >> s[i].Chinese;
        cin >> s[i].Math;
        cin >> s[i].English;

        Average[i] = (s[i].Chinese + s[i].English + s[i].Math) / 3.0;

        if (Average[i] >= 90.0) {
            t[i] = 1;
        }
        else {
            t[i] = 2;
        }
    }

    cout << left
        << setw(12) << "Name"
        << setw(10) << "Chinese"
        << setw(10) << "Math"
        << setw(10) << "English"
        << setw(10) << "Average"
        << "Remark" << endl;

    for (int i = 0; i < n; i++) {
        cout << left
            << setw(12) << s[i].name
            << setw(10) << fixed << setprecision(2) << s[i].Chinese
            << setw(10) << fixed << setprecision(2) << s[i].Math
            << setw(10) << fixed << setprecision(2) << s[i].English
            << setw(10) << fixed << setprecision(2) << Average[i];

        if (t[i] == 1) {
            cout << "Excellent";
        }

        cout << endl;
    }

    return 0;
}
