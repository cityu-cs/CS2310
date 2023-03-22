#include <iostream>
using namespace std;

int main() {
    int s;
    cout << "Please input the width of the treetop:" << endl;
    cin >> s;
    while (s % 2 == 0 || s < 5) {
        cout << "Invalid input!" << endl;
        cout << "Please input the width of the treetop:" << endl;
        cin >> s;
    }

    cout << "Please input the direction:" << endl;
    char d;
    cin >> d;
    
    if (d == 'U' || d == 'u') {
        for (int row = 1; row < s; row++) {
            int lspace = s - row - 1;
            int stars = 2 * row - 1;
            for (int col = 1; col <= lspace; col++) {
                cout << " ";
            }
            for (int col = 1; col <= stars; col++) {
                cout << "*";
            }
            cout << endl;
        }
        int lspace = (s + 1) / 2; // ((2s - 3) - (s - 4)) / 2
        int mspace = (s - 4) - 2;
        int height = (s + 1) / 2;
        for (int row = 1; row <= height; row++) {
            for (int col = 1; col <= lspace; col++) {
                cout << " ";
            }
            cout << "*";
            if (mspace > 0) {
                for (int col = 1; col <= mspace; col++) {
                    cout << " ";
                }
                cout << "*";
            }
            cout << endl;
        }
    } else { // inverse
        int lspace = (s + 1) / 2;
        int mspace = (s - 4) - 2;
        int height = (s + 1) / 2;
        for (int row = 1; row <= height; row++) {
            for (int col = 1; col <= lspace; col++) {
                cout << " ";
            }
            cout << "*";
            if (mspace > 0) {
                for (int col = 1; col <= mspace; col++) {
                    cout << " ";
                }
                cout << "*";
            }
            cout << endl;
        }
        for (int row = s - 1; row > 0; row--) {
            int _lspace = s - row - 1;
            int stars = 2 * row - 1;
            for (int col = 1; col <= _lspace; col++) {
                cout << " ";
            }
            for (int col = 1; col <= stars; col++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}