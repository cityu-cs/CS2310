#include <cstdio>
int main () {
    // constant pointer
    int x = 10;
    int y = 12;
    int *const p1 = &x;
    *p1 = 5; // OK
    // p1 = &y; // Error
    printf("%d %d\n", x, *p1);
    // constant pointer can only point to one specific variable
    // i.e., its address is constant

    // pointer to constant
    const int *p2 = &x;
    // *p2 = 5; // Error
    p2 = &y; // OK
    y = 15;
    printf("%d\n", *p2); // 15
    // pointer to constant can point to different variables
    // the pointed variable cannot be changed from the pointer
    // but can be changed from the variable itself
}