#include "MyArray.h"

MyArray::MyArray() : p(nullptr), N(0) {}

MyArray::MyArray(int n, int init) : p(nullptr), N(0) {
    if (n <= 0) return;
    N = n;
    p = new int[N];
    for (int i = 0; i < N; ++i) p[i] = init;
}

MyArray::MyArray(const MyArray& other) : p(nullptr), N(0) {
    N = other.N;
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = other.p[i];
    }
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this == &other) return *this;
    delete[] p;
    p = nullptr;
    N = other.N;
    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = other.p[i];
    }
    return *this;
}

int MyArray::size() const {
    return N;
}

int MyArray::get(int index) const {
    if (index < 0 || index >= N) return 0;
    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) return;
    p[index] = value;
}

int& MyArray::operator[](int index) {
    return p[index];
}

const int& MyArray::operator[](int index) const {
    return p[index];
}

MyArray MyArray::merge(const MyArray& other) const {
    MyArray result(N + other.N, 0);
    for (int i = 0; i < N; ++i) result.p[i] = p[i];
    for (int j = 0; j < other.N; ++j) result.p[N + j] = other.p[j];
    return result;
}

static int maxInt(int a, int b) {
    return a > b ? a : b;
}

MyArray MyArray::add(const MyArray& other) const {
    int M = maxInt(N, other.N);
    MyArray result(M, 0);
    for (int i = 0; i < M; ++i) {
        int a = i < N ? p[i] : 0;
        int b = i < other.N ? other.p[i] : 0;
        result.p[i] = a + b;
    }
    return result;
}

MyArray MyArray::substract(const MyArray& other) const {
    int M = maxInt(N, other.N);
    MyArray result(M, 0);
    for (int i = 0; i < M; ++i) {
        int a = i < N ? p[i] : 0;
        int b = i < other.N ? other.p[i] : 0;
        result.p[i] = a - b;
    }
    return result;
}

MyArray MyArray::Multiply(const MyArray& other) const {
    int M = maxInt(N, other.N);
    MyArray result(M, 0);
    for (int i = 0; i < M; ++i) {
        int a = i < N ? p[i] : 0;
        int b = i < other.N ? other.p[i] : 0;
        result.p[i] = a * b;
    }
    return result;
}

MyArray MyArray::divide(const MyArray& other) const {
    int M = maxInt(N, other.N);
    MyArray result(M, 0);
    for (int i = 0; i < M; ++i) {
        int a = i < N ? p[i] : 0;
        int b = i < other.N ? other.p[i] : 0;
        result.p[i] = b == 0 ? 0 : a / b;
    }
    return result;
}

void MyArray::print() const {
    cout << "[";
    for (int i = 0; i < N; ++i) {
        cout << p[i];
        if (i != N - 1) cout << " ";
    }
    cout << "]" << endl;
}
