#include <iostream>
#include <cstring>
using namespace std;
const int M = 15, N = 50;
char a[M][N];
char buffer[N];
void strSwap(char* s1, char* s2) {
    strcpy(buffer, s1);
    strcpy(s1, s2);
    strcpy(s2, buffer);
}
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
    cout << "Enter the number of the strings:" << endl;
    int n;
    cin >> n;
    cout << "Enter the contents of each string:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // bubble sort
    for(int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (stringCompare(a[j], a[j - 1]) < 0) {
                strSwap(a[j], a[j - 1]);
            }
        }
    }
    cout << "The sorted strings are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}