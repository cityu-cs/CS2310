#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 50 + 1;
char s[N], ans[2 * N];

char* replace(char* s) {
    int i = 0, n = strlen(s), j = 0;
    while (i < n) {
        // std::cerr << i << ' ' << s[i] << std::endl;
        if (s[i] == ' ') {
            ans[j++] = '%';
            ans[j++] = '0';
        } else {
            ans[j++] = s[i];
        }
        i++;
    }
    return ans;
}

int main() {
    printf("Enter the input string: ");
    std::cin.getline(s, N - 1);
    printf("The replace string is: %s\n", replace(s));
}