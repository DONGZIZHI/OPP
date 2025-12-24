#include <iostream>
using namespace std;

class base {
public:
    int a;
protected:
    int b;
private:
    int c;
    static int count;

public:
    base(int a_ = 0, int b_ = 0, int c_ = 0) : a(a_), b(b_), c(c_) { ++count; cout << "[base ctor]\n"; }
    base(const base& other) : a(other.a), b(other.b), c(other.c) { ++count; cout << "[base copy ctor]\n"; }
    virtual ~base() { cout << "[base dtor]\n"; }

    void input() {
        cin >> a >> b >> c;
    }

    void print() const {
        cout << "base: a=" << a << " b=" << b << " c=" << c << " count=" << count << endl;
    }

    static int Manage() {
        return count;
    }
};
int base::count = 0;

class derived1 : public base {
public:
    derived1() : base() { cout << "[derived1 ctor]\n"; }
    derived1(int a_, int b_, int c_) : base(a_, b_, c_) { cout << "[derived1 ctor]\n"; }
    ~derived1() override { cout << "[derived1 dtor]\n"; }

    void input() {
        base::input();
    }

    void showInside() {
        cout << "derived1 inside can access a and b; cannot access c directly\n";
        cout << "inside: a=" << a << " b=" << b << endl;
        print();
    }
};

class derived2 : protected base {
public:
    derived2() : base() { cout << "[derived2 ctor]\n"; }
    derived2(int a_, int b_, int c_) : base(a_, b_, c_) { cout << "[derived2 ctor]\n"; }
    ~derived2() override { cout << "[derived2 dtor]\n"; }

    void input() {
        base::input();
    }

    void showInside() {
        cout << "derived2 inside can access a and b; cannot access c directly\n";
        cout << "inside: a=" << a << " b=" << b << endl;
        print();
    }

    void showOutsideLike() const {
        cout << "derived2 expose via public wrapper:\n";
        print();
    }

    int getA() const { return a; }
};

class derived3 : private base {
public:
    derived3() : base() { cout << "[derived3 ctor]\n"; }
    derived3(int a_, int b_, int c_) : base(a_, b_, c_) { cout << "[derived3 ctor]\n"; }
    ~derived3() override { cout << "[derived3 dtor]\n"; }

    void input() {
        base::input();
    }

    void showInside() {
        cout << "derived3 inside can access a and b; cannot access c directly\n";
        cout << "inside: a=" << a << " b=" << b << endl;
        print();
    }

    void showOutsideLike() const {
        cout << "derived3 expose via public wrapper:\n";
        print();
    }

    int getA() const { return a; }
};

int main() {
    cout << "Input for derived1 (a b c): ";
    derived1 d1;
    d1.input();
    cout << "Output derived1:\n";
    d1.print();
    cout << "Outside access d1.a = " << d1.a << endl;
    d1.showInside();
    cout << "Manage = " << base::Manage() << endl;

    cout << "\nInput for derived2 (a b c): ";
    derived2 d2;
    d2.input();
    cout << "Output derived2:\n";
    d2.showOutsideLike();
    cout << "Outside cannot access d2.a directly; wrapper getA() = " << d2.getA() << endl;
    d2.showInside();
    cout << "Manage = " << base::Manage() << endl;

    cout << "\nInput for derived3 (a b c): ";
    derived3 d3;
    d3.input();
    cout << "Output derived3:\n";
    d3.showOutsideLike();
    cout << "Outside cannot access d3.a directly; wrapper getA() = " << d3.getA() << endl;
    d3.showInside();
    cout << "Manage = " << base::Manage() << endl;

    cout << "\nConstructor/Destructor order rule:\n";
    cout << "construct: base -> derived\n";
    cout << "destruct : derived -> base\n";

    return 0;
}
