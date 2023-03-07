#include <cstdio>
#include <cstring>

const int N = 50 + 1;
char w[N], p[N];

int findChar (char* word, char* patt) {
    int m = strlen(word);
    int n = strlen(patt);
    int j = m - n;
    while (j >= 0) {
        for (int k = 0; k < n; k++) {
            if (word[j + k] != patt[k])
                break;
            if (k == n - 1)
                return j;
        }
        j--;
    }
    return -1;
}

int main() {
    printf("The word and chars are: ");
    scanf("%s%s", w, p);
    printf("The last position of %s is: %d\n", p, findChar(w, p));
}