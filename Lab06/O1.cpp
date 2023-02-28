#include <iostream>
#include <cmath>
using namespace std;

void printBinary(double num) {
    if (num >= 1) {
        printBinary(floor(num / 2));
        cout << (int) fmod(num, 2); // this digit is lower
    } else if (num > 0) {
        cout << (int) (num * 2); // this digit is higher
        printBinary(num * 2 - floor(num * 2));
    }
}

int main() {
    cout << "Enter the decimal double number is: ";
    double num;
    cin >> num;
    cout << "The corresponding binary double is: ";
    double _int = floor(num);
    double _dec = num - _int;
    printBinary(_int);
    cout << ".";
    printBinary(_dec);
    cout << endl;
    return 0;
}