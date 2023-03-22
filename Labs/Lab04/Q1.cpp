#include <iostream>
using namespace std;

int main() {
    cout << "All output numbers are: " << endl;
    for (int a = 10; a <= 99; a++) {
        for (int b = 0; b <= 99; b++) {
            if ((a + b) * (a + b) == a * 100 + b) {
                cout << a * 100 + b << endl;
            }
        }
    }
    return 0;
}