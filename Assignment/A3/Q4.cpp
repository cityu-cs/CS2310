#include <iostream>
using namespace std;

typedef long long LL;
int n;
LL tot, ans;
int* num = NULL;

LL cnt(LL x, int type);

int main() {
    cout << "Enter the size of the dynamic array: ";
    cin >> n;
    num = new int[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << "Please input the price: ";
    cin >> tot;
    cout << "The number of possible combination is: " << cnt(tot, 0) << endl;
    delete[] num;
    num = NULL;
    return 0;
}

LL cnt(LL x, int type) {
    if (x == 0) {
        return 1;
    }
    if (x < 0 || type == n) {
        return 0;
    }
    return cnt(x - num[type], type) + cnt(x, type + 1);
}