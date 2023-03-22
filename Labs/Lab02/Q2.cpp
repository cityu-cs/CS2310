#include <iostream>
using namespace std;

int main() {
    cout << "Enter a number of four digits: " << endl;
    int num;
    cin >> num;
    int a = num / 1000;
    int b = (num / 100) % 10;
    int c = (num / 10) % 10;
    int d = num % 10;
    cout << "Sum of digits is: " << a * a + b * b + c * c + d * d << endl;
    return 0;
}