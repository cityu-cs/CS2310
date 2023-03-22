#include <iostream>
using namespace std;

const int N = 20 + 1;
int a[N][N], pre[N][N];

int main() {
    int n;
    cout << "Input the size of the matrix: " << endl;
    cin >> n;
    int ans = 1000000000, anst, ansb, ansl, ansr, anssize = 0;
    cout << "Input the content of the matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    for (int t = 1; t <= n; t++) {
        for (int b = t; b <= n; b++) {
            for (int l = 1; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    int cur = pre[b][r] - pre[t - 1][r] - pre[b][l - 1] + pre[t - 1][l - 1];
                    if ((cur < ans) || (cur == ans && (r - l + 1) * (b - t + 1) > anssize)) {
                        anst = t;
                        ansb = b;
                        ansl = l;
                        ansr = r;
                        ans = cur;
                        anssize = (r - l + 1) * (b - t + 1);
                    }
                }
            }
        }
    }
    cout << "The minimum sum submatrix can be represented as:" << endl;
    cout << ans << " " << ansl - 1 << " " << ansr - 1 << " " << anst - 1 << " " << ansb - 1 << " " << endl;
    return 0;
}
/*
4 -9 -9
-9 1 1
-9 1 1

-1 -1 10 10
-1 -1 10 10
10 10 10 10
10 10 10 -4

12 4 -34 21 3
-32 23 -16 2 9
18 12 -34 -14 3
83 -64 45 52 -63
24 -45 34 52 -11
*/