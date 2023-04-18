#include <iostream>
#include <cstring>
using namespace std;

const char* defaultName = "strawberry";
const int defaultPrice = 10;
const int defaultAmount = 20;

const int defaultYear = 2022;
const int defaultMonth = 1;
const int defaultDay = 1;

class ProductionDate {
    public:
    int year, month, day;
    ProductionDate() {
        year = defaultYear;
        month = defaultMonth;
        day = defaultDay;
    }
    ProductionDate(int y, int m, int d): year(y), month(m), day(d) {}
};

class Candy{
    public:
    char* name;
    int price, amount;
    ProductionDate date;
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
    int Compute_age(int y, int m, int d) {
        // return the age of the candy, rounded down
        if (m > date.month) {
            return y - date.year;
        } else if (m == date.month) {
            if (d >= date.day) {
                return y - date.year;
            } else {
                return y - date.year - 1;
            }
        } else {
            return y - date.year - 1;
        }
    }
};

void reverse(char* target) {
    // in-place reverse
    int n = strlen(target);
    int n2 = n / 2;
    for (int i = 0; i < n2; i++) {
        char tmp = target[i];
        target[i] = target[n - i - 1];
        target[n - i - 1] = tmp;
    }
}

int main() {
    Candy c1;
    cout << "Enter year, month and day: " << endl;
    int y, m, d;
    cin >> y >> m >> d;
    cout << endl;
    cout << "Age: " << c1.Compute_age(y, m, d) << endl;
    cout << "Original name: " << c1.name << endl;
    reverse(c1.name);
    cout << "Reversed name: " << c1.name << endl;
}