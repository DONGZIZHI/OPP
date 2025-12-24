#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
private:
    double x, y;

public:
    Point2D() : x(0), y(0) {}
    Point2D(double x_, double y_) : x(x_), y(y_) {}
    Point2D(const Point2D& other) : x(other.x), y(other.y) {}
    virtual ~Point2D() {}

    Point2D& move(double dx, double dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void show() const {
        cout << "Point2D(" << x << ", " << y << ")" << endl;
    }

    void input() {
        cin >> x >> y;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    friend double distance(const Point2D& a, const Point2D& b);
};

double distance(const Point2D& a, const Point2D& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

class Point3D : public Point2D {
private:
    double z;

public:
    Point3D() : Point2D(), z(0) {}
    Point3D(double x_, double y_, double z_) : Point2D(x_, y_), z(z_) {}
    Point3D(const Point3D& other) : Point2D(other), z(other.z) {}
    ~Point3D() override {}

    Point3D& move(double dx, double dy, double dz) {
        Point2D::move(dx, dy);
        z += dz;
        return *this;
    }

    void show() const {
        cout << "Point3D(" << getX() << ", " << getY() << ", " << z << ")" << endl;
    }

    void input() {
        double x, y;
        cin >> x >> y >> z;
        Point2D::move(x - getX(), y - getY());
    }

    friend double distance(const Point3D& a, const Point3D& b);
};

double distance(const Point3D& a, const Point3D& b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    Point2D p1, p2;
    cout << "Input p1 (x y): ";
    p1.input();
    cout << "Input p2 (x y): ";
    p2.input();

    p1.show();
    p2.show();
    cout << "distance(p1, p2) = " << distance(p1, p2) << endl;

    double dx, dy;
    cout << "Move p1 by (dx dy): ";
    cin >> dx >> dy;
    p1.move(dx, dy);
    p1.show();
    cout << "distance(p1, p2) = " << distance(p1, p2) << endl;

    Point3D q1, q2;
    cout << "Input q1 (x y z): ";
    q1.input();
    cout << "Input q2 (x y z): ";
    q2.input();

    q1.show();
    q2.show();
    cout << "distance(q1, q2) = " << distance(q1, q2) << endl;

    double dx3, dy3, dz3;
    cout << "Move q2 by (dx dy dz): ";
    cin >> dx3 >> dy3 >> dz3;
    q2.move(dx3, dy3, dz3);
    q2.show();
    cout << "distance(q1, q2) = " << distance(q1, q2) << endl;

    return 0;
}
