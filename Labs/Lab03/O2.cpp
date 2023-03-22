#include <iostream>
#include <cmath>
using namespace std;

const double _eps = 0.0001;

bool isClose(double a, double b) {
    return abs(a - b) < _eps;
}

int main() {
    double x0, y0, x1, y1;
    cout << "Enter the points on the first line:\n";
    cin >> x0 >> y0 >> x1 >> y1;
    double slope1 = 0;
    bool isVertical1 = false;
    if (isClose(x0, x1)) {
        isVertical1 = true;
    } else {
        slope1 = static_cast<double>(y1 - y0) / (x1 - x0);
    }

    cout << "Enter the points on the second line:\n";
    cin >> x0 >> y0 >> x1 >> y1;
    double slope2 = 0;
    bool isVertical2 = false;
    if (isClose(x0, x1)) {
        isVertical2 = true;
    } else {
        slope2 = static_cast<double>(y1 - y0) / (x1 - x0);
    }

    if ((isVertical1 && isVertical2) || (isClose(slope1, slope2))) {
        cout << "The two straight lines have no intersections.\n";
    } else {
        cout << "The two straight lines have an intersection.\n";
    }
}