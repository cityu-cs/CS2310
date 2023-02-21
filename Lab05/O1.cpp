#include <iostream>
using namespace std;

int a[4] = {1, 2, 5, 10};
int dp[5][501] = {0};

int main(){
    cout << "Enter the value of the money: " << endl;
    int n;
    cin >> n;
    if (n <= 1) {
        cout << "There is only 1 way in total." << endl;
        return 0;
    }
    // make up the money with 1, 2, 5, 10 cents
    // a dynamic programming algorithm
    // dp[i][j] is the number of ways to make up j cents with the first i types of coins
    for (int i = 0; i < 5; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < a[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
            }
        }
    }
    cout << "There are " << dp[4][n] << " different ways in total." << endl;
    return 0;
}