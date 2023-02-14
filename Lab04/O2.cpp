#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // using Dickson's method to calculate the count of Pythagorean triples
    int lmax, lmin, ans = 0;
    cout << "Please input the maximal length allowed for the edge: ";
    cin >> lmax;
    cout << "Please input the minimal length allowed for the edge: ";
    cin >> lmin;
    if ((lmax <= lmin) || (lmin < 1) || (lmax < 1)) {
        cout << "Invalid inputs!" << endl;
        return 0;
    }
    for (int r = 2; r < lmax; r += 2) {
        int r2 = r * r / 2;
        int sbound = floor(sqrt(r2));
        for (int s = 1; s <= sbound; s++) {
            if (r2 % s != 0) {
                continue;
            }
            int t = r2 / s;
            if (r + s >= lmin && r + t >= lmin && r + s + t <= lmax) {
                // cout << r + s << " " << r + t << " " << r + s + t << endl;
                ans++;
            }
        }
    }
    cout << "The number of all Pythagorean triplets between " << lmin << " and " << lmax << " is " << ans << "." << endl;
    return 0;
}