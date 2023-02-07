#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    cout << "Enter the value of a, b and c for quadratic equation:\n";
    double a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(1) << fixed;

    double delta = b * b - 4 * a * c;
    double sym = -b / (2 * a);
    double diff = sqrt(abs(delta)) / (2 * a);
    if (delta < 0) {
        cout << "The Quadratic Equation has two Complex roots:\n";
        cout << sym << "+" << diff << "i\n";
        cout << sym << "-" << diff << "i\n";
    } else if (delta == 0) {
        cout << "The Quadratic Equation has two equal real roots: " << sym << endl;
    } else {
        cout << "The Quadratic Equation has two real roots: ";
        cout << sym + diff << " and " << sym - diff << endl;
    }

    return 0;
}