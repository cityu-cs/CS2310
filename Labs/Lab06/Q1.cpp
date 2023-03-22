#include <iostream>
using namespace std;

const string tens[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
const string ones[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

void print20to99(int n) {
    if (n % 10 == 0) {
        cout << tens[n / 10 - 2];
    } else {
        cout << tens[n / 10 - 2] << " " << ones[n % 10 - 1];
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the integer number: ";
    cin >> n;
    print20to99(n);
    return 0;
}