#include <iostream>
using namespace std;

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//2017-01-01 is Sunday

void dateOf2017(char date[5]) {
    cout << "2017-" << date << " is ";
    int month = (date[0] - '0') * 10 + date[1] - '0';
    int day = (date[3] - '0') * 10 + date[4] - '0';
    int delta = (day - 1);
    for (int i = 1; i < month; i++) {
        delta += days[i];
    }
    // cerr << delta << endl;
    cout << names[delta % 7] << endl;
}

int main() {
    cout << "Enter the date in 2017: ";
    char d[5];
    cin >> d;
    dateOf2017(d);
    return 0;
}