#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;
bool cmp(char*, char*);
void swap(char*, char*);
void sortStr(char**, int);
int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    char **str = new char*[n];
    for (int i = 0; i < n; i++) {
        str[i] = new char[N];
    }
    cout << "Enter the input strings: ";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sortStr(str, n);
    cout << "Sorted result:";
    for (int i = 0; i < n; i++) {
        cout << " " << str[i];
    }
    cout << endl;
}
bool cmp(char* a, char* b) {
    // cerr << "cmp " << a << " and " << b << endl;
    // < operator
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
        i++;
    }
    return a[i] < b[i]; // '/0' = 0 so always smaller than any other char
}
char* temp = new char[N];
void swap(char* a, char* b) {
    // you need strcpy to swap two strings
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
void sortStr(char** str, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = num - 1; j > i; j--) {
            if (cmp(str[j], str[j - 1])) {
                // cerr << "swap " << str[j] << " and " << str[j - 1] << endl;
                swap(str[j], str[j - 1]);
            }
        }
    }
}