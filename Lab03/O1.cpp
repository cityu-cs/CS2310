#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main () {
    cout << "Enter Value of each score:\n";
    int a[6];
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    sort(a, a + 6);
    cout << "The effective score is: " << static_cast<double>(a[2] + a[3]) / 2 << endl;
    return 0;
}