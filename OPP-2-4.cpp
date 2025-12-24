#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    swap(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}
