#include <cstdio>
#include <cstring>
// kmp
const int N = 50 + 1;
char w[N], p[N];
int findTimes(char* word, char* patt) {
    int m = strlen(word);
    int n = strlen(patt);
    int j = m - n;
    int cnt = 0;
    while (j >= 0) {
        for (int k = 0; k < n; k++) {
            if (word[j + k] != patt[k])
                break;
            if (k == n - 1)
                cnt++;
        }
        j--;
    }
    return cnt;
}

int main() {
    printf("Enter two strings: ");
    scanf("%s%s", w, p);
    printf("The occurrence of %s in %s is: %d\n", p, w, findTimes(w, p));
    return 0;
}