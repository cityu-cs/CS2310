#include <iostream>
using namespace std;
const int N = 50;
char s1[N], s2[N];
int stringCompare(char* s1, char* s2) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i]; // '\0' = 0 in ASCII
}
int main() {
    cout << "Enter the first string:" << endl;
    cin.getline(s1, N);
    cout << "Enter the second string:" << endl;
    cin.getline(s2, N);
    int res = stringCompare(s1, s2);
    if (res == 0) {
        cout << "The two strings are equal." << endl;
    } else if (res < 0) {
        cout << "The second string is larger." << endl;
    } else {
        cout << "The first string is larger." << endl;
    }
    return 0;
}