#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int a, b, c;
    cout << "Enter the first side: " << endl;
    cin >> a;
    cout << "Enter the second side: " << endl;
    cin >> b;
    cout << "Enter the third side: " << endl;
    cin >> c;

    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << setprecision(2) << fixed;
    cout << "The area is: " << area << endl;
    
    return 0;
}