#include <cstdio>
#include <cstring>

const int N = 50 + 1;
char a[N], b[N], ans[N * 2];

template <typename T>
inline void mySwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void quickSort(T *s, int l, int r) {
    int i = l, j = r;
    int mid = (l + r) / 2;
    T pivot = s[mid];
    while (i <= j) {
        while (s[i] < pivot) ++i;
        while (s[j] > pivot) --j;
        if (i <= j) {
            mySwap(s[i], s[j]);
            ++i, --j;
        }
    }
    if (l < j) quickSort(s, l, j);
    if (i < r) quickSort(s, i, r);
}

void merge(char* s, char* t, char* dest) {
    int i = 0, j = 0, k = 0;
    while (s[i] && t[j]) {
        if (s[i] < t[j]) dest[k++] = s[i++];
        else dest[k++] = t[j++];
    }
    while (s[i]) dest[k++] = s[i++];
    while (t[j]) dest[k++] = t[j++];
    dest[k] = '\0';
}

int main() {
    scanf("%s%s", a, b);
    quickSort(a, 0, strlen(a) - 1);
    quickSort(b, 0, strlen(b) - 1);
    merge(a, b, ans);
    puts(ans);
    return 0;
}