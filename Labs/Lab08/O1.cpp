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
        double getbal() {
            return bal;
        }
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

    std::sort(r, r + n, sort_bal);
    puts("Enter the balance to find: ");
    double tar;
    scanf("%lf", &tar);

    int l = 0, u = n;
    int ansl = -1, ansu = -1;
    while (l < u) {
        int mid = (l + u) / 2;
        if (r[mid].getbal() == tar) {
            int i = mid;
            while (i >= 0 && r[i].getbal() == tar) {
                i--;
            } // i is the first element that is not equal to tar
            ansl = i + 1;
            i = mid;
            while (i < n && r[i].getbal() == tar) {
                i++;
            }
            ansu = i - 1;
            break;
        } else if (r[mid].getbal() < tar) {
            l = mid + 1;
        } else {
            u = mid - 1;
        }
    }

    if (ansu == -1) {
        puts("No records found!");
    } else {
        printf("%d records found!\n", ansu - ansl + 1);
        std::sort(r + ansl, r + ansu + 1, sort_time);
        for (int i = ansl; i <= ansu; i++) {
            r[i].print();
        }
    }

    return 0;
}