#include <cstdio>
#include <iostream>
#include <cstring>

const int N = 50 + 1;
char s[N];

int main() {
    printf("Enter the student info: ");
    std::cin.getline(s, N - 1);
    int len = strlen(s);
    int m = len - 1;
    while (m > 0 && s[m] != ' ')
    m--;
    printf("Student name is: ");
    for (int i = 0; i < m; i++) {
        putchar(s[i]);
    }
    printf("\nStudent ID is: ");
    for (int i = m + 1; i < len; i++) {
        putchar(s[i]);
    }
    printf("\n");
    return 0;
}
