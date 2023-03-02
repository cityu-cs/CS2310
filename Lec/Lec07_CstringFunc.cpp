#include <cstdio>
#include <cstring>

char str1[10] = "123456789";
char str2[20] = "123456789";
char str3[10] = "abcdefghi";
char str4[10] = "ABCDEFGHI";
char str5[20] = "ABCDEFGHIJKLMN";
char str0[10] = ".........";

int main () {
    // strcpy(dest, src)
    strcpy(str0, str3);
    printf("%s\n", str0); // abcdefghi
    strcpy(str0, str2); // len(str2) = len(str0), no overflow
    printf("%s\n", str0); // 123456789
    strcpy(str0, str5); // len(str5) > len(str0)
    printf("%s\n", str0); // ABCDEFGHIJKLMN (overflow)
    strcpy_s(str0, 10, str5);
    printf("%s\n", str0); // empty string (strcpy_s cannot cut off the overflow part)
    // how to only copy the first 9 characters? (10 including the null terminator)
    strncpy(str0, str5, 9);
    printf("%s\n", str0); // ABCDEFGHI

    // strcat(dest, src)
    strcat(str2, str3);
    printf("%s\n", str2); // 123456789abcdefghi
    strcat(str5, str3);
    printf("%s\n", str5); // ABCDEFGHIJKLMNabcdefghi (overflow)
    strcat_s(str5, 20, str3);
    printf("%s\n", str5); // empty string (strcat_s cannot cut off the overflow part)

    // strcmp(str1, str2)
    printf("%d\n", strcmp(str3, str4)); // 1 (because 'a' > 'A')
    strcpy(str5, "ABCDEFGHIJ"); // or sprintf(str5, "ABCDEFGHIJ");
    puts(str5); // ABCDEFGHIJ
    printf("%d\n", strcmp(str4, str5)); // -1 (because len(str4) < len(str5))

    // strlen(str)
    printf("%llu\n", strlen(str5)); // 10
    // not counting the null terminator
    printf("%llu\n", sizeof(str5)); // 20

    return 0;
}