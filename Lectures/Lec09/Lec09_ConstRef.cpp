#include <cstdio>
int main (const int argc, const char** argv) {
    int n = 10;
    int &ref = n; // equiv. int* const ref = &n;
    ref = 5; // n = 5
    printf("%d\n", n);
    
    // int &ref0; // Error: must be initialized
    // int &ref1 = 100; // Error: must be initialized with a variable
    const int &ref2 = 100; // OK
    int m = 15;
    const int &ref3 = m; // OK
    m = 20; // OK
    // ref3 = 20; // Error: ref3 is a constant reference

    for (int i = 0; i < argc; i++)
        printf("%s\n", *(++argv));
}