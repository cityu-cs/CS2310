#include <iostream>
#include <cstring>
using namespace std;

const char* defaultName = "Black_Tea";
const int defaultPrice = 10;
const int defaultAmount = 20;

class Candy{
    public:
    char* name;
    int price, amount;
    Candy() {
        name = new char[strlen(defaultName) + 1];
        strcpy(name, defaultName);
        price = defaultPrice;
        amount = defaultAmount;
    }
    Candy(int p, int a, char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        price = p;
        amount = a;
    }
    Candy(const Candy& o) {
        name = new char[strlen(o.name) + 1];
        strcpy(name, o.name);
        price = o.price;
        amount = o.amount;
    }
    ~Candy() {
        delete[] name;
    }
    Candy operator+(const Candy& o) {
        Candy c;
        c.price = price + o.price;
        c.amount = amount + o.amount;
        // ignore o.name
        return c;
    }
};
int main() {
    Candy c1;
    cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
    char name[20];
    int price, amount;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter price: " << endl;
    cin >> price;
    cout << "Enter amount: " << endl;
    cin >> amount;
    Candy c2(price, amount, name);
    cout << "c2: name-" << c2.name << "; price-" << c2.price << "; amount-" << c2.amount << endl;
    cout << "c3 = c1+c2 is: " << endl;
    Candy c3 = c1 + c2;
    cout << "c3: name-" << c3.name << "; price-" << c3.price << "; amount-" << c3.amount << endl;
}