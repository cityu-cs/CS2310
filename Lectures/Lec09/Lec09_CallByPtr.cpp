#include <cstdio>
void swap(int *a, int *b) { // *a and *b store the address of x and y
    int tmp = *a; // here * is dereference operator
    *a = *b; // to get x and y values
    *b = tmp;
}

void swapByRef(int &a, int &b) { // a and b are aliases of x and y
    int tmp = a; // they store the values of x and y
    a = b;
    b = tmp;
}

int main () {
    int x = 10, y = 12;
    swap(&x, &y); // address of x and y are passed
    printf("%d %d\n", x, y);
    swapByRef(x, y); // x and y are passed
    printf("%d %d\n", x, y);
    return 0;
}