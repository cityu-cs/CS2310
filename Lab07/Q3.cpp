#include <cstdio>
#include <cstring>

const int N = 50 + 1;
char a[N], b[N];
char ans[2 * N];

void sortString(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (s[j] < s[j - 1]) {
                char tmp = s[j - 1];
                s[j - 1] = s[j];
                s[j] = tmp;
            }
        }
    }
}

char* mergeStrings(char* a, char* b) {
    sortString(a);
    sortString(b);
    int i = 0, j = 0, n = strlen(a), k = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }
    }
    while (i < n) {
        ans[k++] = a[i++];
    }
    while (j < n) {
        ans[k++] = b[j++];
    }
    return ans;
}

int main () {
    printf("Input String 1: ");
    scanf("%s", a);
    printf("Input String 2: ");
    scanf("%s", b);
    printf("Merged String: ");
    puts(mergeStrings(a, b));
}