#include <iostream>
using namespace std;

int main () {
    int d0, h0, m0, s0, d1, h1, m1, s1;
    cout << "For start time, please enter the following information:" << endl;
    cout << "Enter the start day (a number in range from 1 to 31): " << endl;
    cin >> d0;
    cout << "Enter the start hour (a number in range from 0 to 23): " << endl;
    cin >> h0;
    cout << "Enter the start minute (a number in range from 0 to 59): " << endl;
    cin >> m0;
    cout << "Enter the start second (a number in range from 0 to 59): " << endl;
    cin >> s0;

    cout << "For end time, please also enter the similar information:" << endl;
    cout << "Enter the end day (a number in range from 1 to 31): " << endl;
    cin >> d1;
    cout << "Enter the end hour (a number in range from 0 to 23): " << endl;
    cin >> h1;
    cout << "Enter the end minute (a number in range from 0 to 59): " << endl;
    cin >> m1;
    cout << "Enter the end second (a number in range from 0 to 59): " << endl;
    cin >> s1;
    
    // cout << d1 << h1 << m1 << s1;
    int dd, hd, md, sd;
    dd = d1 - d0;
    if ((hd = h1 - h0) < 0) {
        hd += 24;
        dd -= 1;
    }
    if ((md = m1 - m0) < 0) {
        md += 60;
        hd -= 1;
    }
    if ((sd = s1 - s0) < 0) {
        sd += 60;
        md -= 1;
    }
    cout << "The time difference is: ";
    cout << dd << " day(s), ";
    cout << hd << " hour(s), ";
    cout << md << " minute(s), and ";
    cout << sd << " second(s)." << endl;

    return 0;
}