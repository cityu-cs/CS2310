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

int largertriangle(Triangle t1, Triangle t2) {
    double s1 = t1.getArea();
    double s2 = t2.getArea();
    if (s1 > s2) {
        return 1;
    } else if (s1 < s2) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Triangle t1, t2;
    int a, b, c;
    std::cout << "Enter New Sides for Triangle 1:" << std::endl;
    std::cin >> a >> b >> c;
    t1.setSides(a, b, c);
    std::cout << "Enter New Sides for Triangle 2:" << std::endl;
    std::cin >> a >> b >> c;
    t2.setSides(a, b, c);

    int result = largertriangle(t1, t2);
    if (result == 1) {
        std::cout << "The Area " << t1.getArea() << " of Triangle 1 is larger than area " << t2.getArea() << " of Triangle 2." << std::endl;
    } else if (result == -1) {
        std::cout << "The Area " << t2.getArea() << " of Triangle 2 is larger than area " << t1.getArea() << " of Triangle 1." << std::endl;
    } else {
        std::cout << "The areas of the two triangle are identical." << std::endl;
    }
    return 0;
}
