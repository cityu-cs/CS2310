#include <iostream>
#include <cstdio>

int main() {
    char s[5];
    char t[5] = "1234"; // t is memory neighbor of s
    while (s[0] != 'q') {
        std::cin.getline(s, 5); // this will cause a buffer overflow if the input is longer than 4 characters
        // error flag:
        printf("failbit: %d\n", std::cin.fail());
        printf("badbit: %d\n", std::cin.bad());
        printf("eofbit: %d\n", std::cin.eof());
        std::cin.clear(); // clear the error flag
        printf("\"%s\"\n", s);
    }
    /* Example:
    Input: "12345"
    Output:
    "1234"
    "5" */

    // overflow
    // char t[5] = "12345"; 
    // error: initializer-string for 'char [5]' is too long [-fpermissive]
    t[4] = '5';
    printf("%s\n", t); // the output will be "12345" + s[] ("q234")
    // but what if we modify s[4]?
    s[4] = '6';
    printf("%s\n", t); // the output will be "12345" + s[] ("q2346")
    return 0;
}