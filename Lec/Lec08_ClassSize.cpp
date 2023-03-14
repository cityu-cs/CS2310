#include <iostream>
using namespace std;

class test1 {
    int var1, var2, var3;

    char var4;
};
class test2 {
    int var1, var2, var3;

    char var4, var5, var6, var7;

    void func1() {
        return;
    }
};
class test3 {
    void func1() {
        return;
    }
};

int main() {
    cout << sizeof(test1) << endl; // 16 due to memory alignment
    cout << sizeof(test2) << endl; // 16 function pointer
    cout << sizeof(test3) << endl; // 1 empty class
}