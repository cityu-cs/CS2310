#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20 + 1;
char s[N];
long long dp[N][N];

int main() {
    printf("Input the integer number:\n");
    scanf("%s", s+1);
    int n = strlen(s+1), k;
    printf("Input the value of k:\n");
    scanf("%d", &k);
    printf("The largest k bit is: ");
    // dp[i][j] = the max j-bit number formed by s[1...i], must end with s[i]
    // dp[i][1] = s[i] - '0'
    // dp[i][j] = max(dp[u][j-1] * 10 + s[i] - '0') for u = 1...i-1
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            dp[i][j] = 0; // don't use dp[i-1][j] here
            for (int u = j-1; u < i; u++) {
                dp[i][j] = max(dp[i][j], dp[u][j-1] * 10 + s[i] - '0');
            }
        }
    }
    long long ans = 0;
    for (int i = k; i <= n; i++) {
        ans = max(ans, dp[i][k]);
    }
    // when length is not enough, put 0 at the beginning
    char ansstr[N];
    sprintf(ansstr, "%lld", ans);
    int anslen = strlen(ansstr);
    if (anslen < k) {
        for (int i = 1; i <= k - anslen; i++) {
            printf("0");
        }
    }
    printf("%lld\n", ans);
    return 0;
}