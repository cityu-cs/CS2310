#include <iostream>
using namespace std;

const string key1 = "cityu";
const string key2 = "cafe";
const int len1 = 5, len2 = 4;

int main() {
    string s;
    cout << "Input the ciphertext: " << endl;
    cin >> s;
    int n = s.length();
    cout << "The corresponding plaintext is: " << endl;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a'; // 0...25
        // c -(c, 3)-> z -(c, 3)-> w
        x = (x - (key2[i % len2] - 96) + 26) % 26;
        x = (x - (key1[i % len1] - 96) + 26) % 26;
        cout << (char) (x + 'a');
    }
    cout << endl;
    return 0;
}
