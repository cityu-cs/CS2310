#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 20 + 1;
int n;
pair <int, int> a[N];

inline int popcount(int x) {
    int ans = 0;
    while (x) {
        ans += x & 1;
        x >>= 1;
    }
    return ans;
}

int solve(int i, int status) {
    // return the ans of first i courses

    // first check if i-th course can be added
    bool ok = true;
    for (int j = 1; j < i; j++) {
        if (status & (1 << j)) {
            if (a[j].second > a[i].first) {
                // j ends later than i starts
                ok = false;
                break;
            }
        }
    }
    if (i == n) {
        return popcount(status) + (ok ? 1 : 0);
    }
    if (ok) {
        return max(solve(i + 1, status | (1 << i)), solve(i + 1, status));
    }
    return solve(i + 1, status);
}

int main () {
    cout << "Input the number of the courses: " << endl;
    cin >> n;
    cout << "Input the starting time and the ending time for each course: " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    // brute force. choose and not choose each course. O(2^n)
    // status code is the binary representation of the course selection 1 << n

    cout << "There are " << solve(1, 0) << " classes that can be scheduled for the same classroom." << endl;
    return 0;
}

/* 
6 2 3 1 9 3 5 1 7 4 6 6 8 (3)
8 0 10 3 4 2 8 1 5 4 5 4 8 5 6 7 9 (4)
7 2 5 5 8 1 3 2 5 7 9 5 8 4 6 (3)

3
1 2
2 3
1 3 (2)

5
1 9
2 8
3 7
4 6
5 6 (1)

6
1 3
3 5
5 7
7 9
9 11
11 13 (6)

	
5
1 9
2 3
3 5
6 9
2 3 (3)

4
1 3
2 4
3 5
4 6 (2)
*/