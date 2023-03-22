#include <cstdio>
int x, y;
int main () {
    int *p1, *p2;
    int a[5] = {0};
    long long b[5] = {0};
    char c[5] = {0};
    x = 10;
    y = 12;
    p1 = &x;
    p2 = &y;
    // printf("x = %d, y = %d\n", *p1, *p2);
    // printf("address: x = %p, y = %p\n", p1, p2);
    *p1 = 5;
    *p2 = *p1 + 10;
    // printf("x = %d, y = %d\n", x, y);
    // printf("address: x = %p, y = %p\n", &x, &y);
    for (int i = 0; i < 5; i++)
        printf("%p ", a + i);
    puts("");
    for (int i = 0; i < 5; i++)
        printf("%p ", b + i);
    puts("");
    for (int i = 0; i < 5; i++)
        printf("%p ", c + i);
    puts("");
    return 0;
}