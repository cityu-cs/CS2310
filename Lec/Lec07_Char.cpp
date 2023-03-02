#include <cstdio>
#include <iostream>

char caseSwitch (char c) {
    return (c ^ 0x20);
}


int main() {
    // print the binary of ASCII code
    printf("%d\n", 'A');
    printf("%d\n", 'a');
    printf("%d\n", '0');
    printf("%c\n", caseSwitch('A'));
    printf("%c\n", caseSwitch('a'));
    char c = getchar();
    if (c >= 'A' && c <= 'Z') {
        printf("Upper case\n");
        printf("%c\n", caseSwitch(c));
    } else if (c >= 'a' && c <= 'z') {
        printf("Lower case\n");
        printf("%c\n", caseSwitch(c));
    } else if (c >= '0' && c <= '9') {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }

    std::cin >> c; // shares the same buffer with scanf
    std::cout << (int)c << std::endl;
    return 0;
}