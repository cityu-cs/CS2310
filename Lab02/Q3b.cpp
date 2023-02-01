#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double celsius;
    cout << "Enter temperature in Centigrade: " << endl;
    cin >> celsius;
    cout << setprecision(2) << fixed;
    double fahren = celsius * 9 / 5 + 32;
    cout << "Temperature in Fahrenheit is: " << fahren << endl;
    cout << "Temperature in Kelvin is: " << (fahren + 459.67) * 5 / 9 << endl;
    return 0;
}