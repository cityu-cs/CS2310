#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// return a random integer between 1 and 10
int randInt() {
    int a = 1, b = 10;
    return rand() % (b - a + 1) + a;
}

// return a random float number between 0 and 1
double randDouble() {
    return rand() / (double)(RAND_MAX);
}

int main() {
    int num;
    double dou;
    srand((unsigned)time(0));

    // random within {-3, -2, -1, 0, 1}
    cout << "The value of x is: " << (rand() % 5) - 3 << endl;

    // random within {-1, 1}
    cout << "The value of x is: " << (rand() % 2) * 2 - 1 << endl;

    // random float-number within [4.5, 7.5]
    cout << setprecision(2) << fixed;
    cout << "The value of x is: " << (randDouble() * 3) + 4.5 << endl;
    
    return 0;
}
