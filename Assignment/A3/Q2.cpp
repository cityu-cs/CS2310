#include <iostream>
#include <string>
using namespace std;
const int N = 50;

template <typename T>
void Swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

class Professor {
    private:
    string Name;
    int BirthYear;
    int Count;
    public:
    Professor() {}
    Professor(string n, int y, int c) {
        Name = n;
        BirthYear = y;
        Count = c;
    }
    string getName();
    int getYear();
    int getCount();
    bool assign();
};
string Professor::getName() {
    return Name;
}
int Professor::getYear() {
    return BirthYear;
}
int Professor::getCount() {
    return Count;
}
bool Professor::assign() {
    if (Count > 0) {
        Count--;
        // cerr << "Count = " << getCount() << endl;
        return true;
    }
    return false;
}

class Subject {
    private:
    string Name;
    int Cnt;
    Professor List[N];
    public:
    Subject() {}
    Subject(string s) {
        Name = s;
        Cnt = 0;
    }
    int getCourses();
    int getProCnt();
    Professor* getPro(int);
    void hire(string, int, int);
    void bubble_sort();
    void print();
};
int Subject::getCourses() {
    int ans = 0;
    for (int i = 0; i < Cnt; i++) {
        ans += List[i].getCount();
    }
    return ans;
}
int Subject::getProCnt() {
    return Cnt;
}
Professor* Subject::getPro(int i) {
    return &List[i];
}
void Subject::hire(string n, int y, int c) {
    List[Cnt++] = Professor(n, y, c);
}
void Subject::bubble_sort() { // sort professors by ascending birth year
    for (int i = 0; i < Cnt - 1; i++) {
        for (int j = Cnt - 1; j > i; j--) {
            if (List[j].getYear() < List[j - 1].getYear()) {
                Swap(List[j], List[j - 1]);
            }
        }
    }
}
void Subject::print() {
    bubble_sort();
    for (int i = 0; i < Cnt; i++) {
        cout << List[i].getName() << " " << List[i].getYear() << " " << List[i].getCount() << endl;
    }
}

Subject cls[3];

int main() {
    cls[0] = Subject("History");
    cls[1] = Subject("Science");
    cls[2] = Subject("Engineering");
    cout << "Welcome to the University, what do you want to do?" << endl;
    char opt;
    int n;
    string _n;
    bool flag;
    while (true) {
        cin >> opt;
        switch (opt) {
            case 'H': // hire
                cout << "Input the number of Professors: " << endl;
                cin >> n;
                cout << "Input the information of Professors (name, birth_year, lectures_number, subject): " << endl;
                for (int i = 0; i < n; i++) {
                    string n, s;
                    int y, c;
                    cin >> n >> y >> c >> s;
                    switch (s[0]) {
                        case 'H':
                            cls[0].hire(n, y, c);
                            break;
                        case 'S':
                            cls[1].hire(n, y, c);
                            break;
                        case 'E':
                            cls[2].hire(n, y, c);
                            break;
                    }
                }
                cout << "All Professors hired. What do you want to do next?" << endl;
                break;
            case 'L': // list
                cout << "Professors in the university: " << endl;
                cout << "Number of History lectures available: " << cls[0].getCourses() << endl;
                cls[0].print();
                cout << "Number of Science lectures available: " << cls[1].getCourses() << endl;
                cls[1].print();
                cout << "Number of Engineering lectures available: " << cls[2].getCourses() << endl;
                cls[2].print();
                cout << "All Professors listed. What do you want to do next?" << endl;
                break;
            case 'A': // assign
                cout << "Input the name of the Professors you want to assign: " << endl;
                if (cls[0].getCourses() + cls[1].getCourses() + cls[2].getCourses() == 0) {
                    cout << "All Professors are busy. What do you want to do next?" << endl;
                    break;
                }
                cin >> _n;
                flag = false;
                while (true) {
                    for (int j = 0; (j < 3) && (!flag); j++) {
                        int proCnt = cls[j].getProCnt();
                        for (int i = 0; i < proCnt; i++) {
                            // cerr << "Checking Subject " << j << " Professor " << i << " named " << cls[j].getPro(i)->getName() << endl;
                            if (cls[j].getPro(i)->getName() == _n) {
                                // cerr << "Found at Subject " << j << " Professor " << i << endl;
                                if (cls[j].getPro(i)->assign()) {
                                    cout << "Succeed! What do you want to do next?" << endl;
                                    flag = true;
                                } else {
                                    cout << "Sorry, the Professor is not available. Try again:" << endl;
                                }
                                break;
                            }
                        }
                    }
                    if (flag) {
                        break;
                    }
                    cin >> _n;
                }
                break;
            case 'Q': // quit
                cout << "Have a nice day, bye!" << endl;
                return 0;
        }
    }
}