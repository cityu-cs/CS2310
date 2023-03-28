#include <iostream>
#include <cstring>
using namespace std;
char arr[50];
int chars[50];
void findWord(char* arr, int* i, int* count) {
    while(arr[*i] != ' ' && arr[*i] != '\0') {
        *count = *count + 1;
        *i = *i + 1;
    }
}
int main() {
    cout << "Enter the content of the string:" << endl;
    cin.getline(arr, 50);
    int i = 0;
    int cnt = 0;
    int n = strlen(arr);
    int words = 0;
    while(i < n) {
        if(arr[i] != ' ') {
            findWord(arr, &i, &cnt);
            chars[words] = cnt;
            words++;
            cnt = 0;
        }
        i++;
    }
    for (int i = 0; i < words; i++) {
        cout << "Word " << i + 1 << " has " << chars[i] << " characters." << endl;
    }
    cout << "The number of words in the string is: " << words << endl;
    return 0;
}