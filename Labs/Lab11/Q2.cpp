#include <iostream>
#include <cstring>
using namespace std;

const int N = 300;

char inp[N], rep[N];

char* replace(char*, char*);

int main() {
    cout << "Enter the input string: ";
    cin.getline(inp, N);
    cout << "Enter the input space str: ";
    cin.getline(rep, N);
    cout << "The modified string is: " << replace(inp, rep) << endl;
    return 0;
}

char* replace(char* str, char* space) {
    char* out = NULL;
    int baselen = strlen(str);
    int len = baselen;
    int spacelen = strlen(space);
    for (int i = 0; i < baselen; i++) {
        if (str[i] == ' ') {
            len += spacelen - 1;
        }
    }
    out = new char[len + 1];
    int j = 0;
    for (int i = 0; i < baselen; i++) {
        if (str[i] == ' ') {
            for (int k = 0; k < spacelen; k++) {
                out[j] = space[k];
                j++;
            }
        } else {
            out[j] = str[i];
            j++;
        }
    }
    out[j] = '\0';
    return out;
}