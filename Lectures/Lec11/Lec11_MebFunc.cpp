#include <iostream>
using namespace std;

class Point {
    public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // equivalently:
    // Point(int x, int y) : x(x), y(y) {}
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    Point& setX(int x) {
        this->x = x;
        return *this;
    }
    Point& setY(int y) {
        this->y = y;
        return *this;
    }
    private:
    int x, y;
};

int main() {
    Point p(1, 2);
    p.print();
    p.setX(3).setY(4); // supports chaining
    p.print();
    return 0;
}