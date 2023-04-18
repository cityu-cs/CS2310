#include <iostream>
#include <cstring>
using namespace std;

const char* defaultName = "strawberry";
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
};
int main() {
    cout << "Which constructor to use (1: default, 2: parameterized, 3: copy)?" << endl;
    int choice;
    cin >> choice;
    char name[20];
    int price, amount;
    switch(choice) {
        case 1: {
            Candy c1;
            cout << endl;
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
        }
        break;
        case 2: {
            cout << "Enter name: ";
            cin.ignore();
            cin.getline(name, 20);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter amount: ";
            cin >> amount;
            cout << endl;
            Candy c1(price, amount, name);
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
        }
        break;
        case 3: {
            cout << "Enter name: ";
            cin.ignore();
            cin.getline(name, 20);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter amount: ";
            cin >> amount;
            cout << endl;
            Candy c1(price, amount, name);
            Candy c2(c1);
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
            cout << "c2: name-" << c2.name << "; price-" << c2.price << "; amount-" << c2.amount << endl;
        }
        break;
    }
}