#include <cstdio>
#include <iostream>
#include <algorithm>

class Record {
    private:
        int month, day;
        double bal;
    public:
        Record() {
            month = 0;
            day = 0;
            bal = 0;
        }
        Record(int m, int d, double b) {
            month = m;
            day = d;
            bal = b;
        }
        void setRecord(int, int, double);
        void print();
        friend bool sort_time (const Record& lhs, const Record& rhs);
        friend bool sort_bal (const Record& lhs, const Record& rhs);
};

void Record::setRecord(int m, int d, double b) {
    month = m;
    day = d;
    bal = b;
}

void Record::print() {
    std::cout << month << " " << day << " " << bal << std::endl;
}

bool sort_time (const Record& lhs, const Record& rhs) {
    if (lhs.month < rhs.month) {
        return true;
    } else if (lhs.month > rhs.month) {
        return false;
    } else {
        if (lhs.day < rhs.day) {
            return true;
        } else {
            return false;
        }
    }
}

bool sort_bal (const Record& lhs, const Record& rhs) {
    if (lhs.bal < rhs.bal) {
        return true;
    } else {
        return false;
    }
}

const int N = 30 + 1;
Record r[N];

int main () {
    int n;
    puts("Enter the number of the records: ");
    scanf("%d", &n);
    puts("Enter the contents of each records: ");
    for (int i = 0; i < n; i++) {
        int m, d;
        double b;
        scanf("%d %d %lf", &m, &d, &b);
        r[i].setRecord(m, d, b);
    }

    puts("Sort according to the balance: ");
    std::sort(r, r + n, sort_bal);
    for (int i = 0; i < n; i++) {
        r[i].print();
    }

    puts("Sort according to the time: ");
    std::sort(r, r + n, sort_time);
    for (int i = 0; i < n; i++) {
        r[i].print();
    }

    return 0;
}