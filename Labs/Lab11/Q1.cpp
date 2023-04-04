#include <iostream>
#include <cstring>
using namespace std;

const int N = 100;

char str[N], d;

void deleteStr(char *str, char delete_char);

int main() {
    cout << "Enter the input string: ";
    cin.getline(str, N);
    cout << "Enter the input delete_char: ";
    cin.get(d);
    deleteStr(str, d);
    cout << "The modified string is: " << str << endl;
    return 0;
}

void deleteStr(char *str, char delete_char) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != delete_char) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}