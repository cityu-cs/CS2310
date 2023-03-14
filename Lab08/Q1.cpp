#include <iostream>
#include <iomanip>
#include <cmath>

class Triangle {
    private:
        int side1, side2, side3;
        double area;
        void computeArea();
    public:
        Triangle() {
            side1 = 0;
            side2 = 0;
            side3 = 0;
            area = 0;
        }
        Triangle(int s1, int s2, int s3) {
            side1 = s1;
            side2 = s2;
            side3 = s3;
            area = 0;
        }
        void setSides(int, int, int);
        double getArea();
        void debug();
};

void Triangle::computeArea() {
    double s = (side1 + side2 + side3) / 2.0;
    area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    // std::cerr << "s: " << s << std::endl;
    // std::cerr << "Area: " << area << std::endl;
}

void Triangle::setSides(int s1, int s2, int s3) {
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

double Triangle::getArea() {
    computeArea();
    return area;
}
int main() {
    Triangle triangle1;
    std::cout << "Area of Triangle (i.e. triangle1): " << triangle1.getArea() << std::endl;
    Triangle triangle2(3, 4, 5);
    std::cout << "Area of Triangle (i.e. triangle2 with sides 3, 4 and 5): " << triangle2.getArea() << std::endl;
    int a, b, c;
    std::cout << "Enter New Sides for Triangle:" << std::endl;
    std::cin >> a >> b >> c;
    triangle1.setSides(a, b, c);
    std::cout << "Area of Triangle: " << triangle1.getArea() << std::endl;
    return 0;
}
