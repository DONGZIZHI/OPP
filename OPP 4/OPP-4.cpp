#include "MyArray.h"

int main() {
    MyArray a(5, 1);
    MyArray b(3, 2);

    a.set(2, 10);

    a.print();
    b.print();

    MyArray c(a);
    c.set(0, 99);

    a.print();
    c.print();

    MyArray m = a.merge(b);
    m.print();

    MyArray s = a.add(b);
    MyArray d = a.substract(b);
    MyArray p = a.Multiply(b);

    b.set(1, 0);
    MyArray q = a.divide(b);

    s.print();
    d.print();
    p.print();
    q.print();

    MyArray x;
    x = a;
    x.set(4, 777);

    a.print();
    x.print();

    return 0;
}
