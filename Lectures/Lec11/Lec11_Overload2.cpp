#include <iostream>
using namespace std;

class Point{
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point& operator=(const Point& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3(5, 6);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    p1 = p2;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    p1 = p1 + p2;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    return 0;
}