#include <iostream>
using namespace std;

class Student {
public:
    int* ID;
    int age;
    Student(int ID, int age) {
        this->ID = new int(ID);
        this->age = age;
    }
    ~Student() {
        if(ID != NULL) {
            delete ID;
            ID = NULL;
        }
    }
    Student& operator=(const Student& other) { // deep copy
        if(ID != NULL) {
            delete ID;
            ID = NULL;
        }
        ID = new int(*other.ID);
        age = other.age;
        return *this;
    }
    bool operator==(const Student& other) {
        return *ID == *other.ID && age == other.age;
    }
};
int main() {
    Student s1(1, 20);
    Student s2(2, 21);
    Student s3(3, 22);
    Student s4(4, 23);
    cout << (s1 == s2) << endl; // 0
    cout << (s1 == s3) << endl; // 0
    cout << (s1 == s4) << endl; // 0
    s1 = s2;
    cout << (s1 == s2) << endl; // 1
    cout << (s1 == s3) << endl; // 0
    cout << (s1 == s4) << endl; // 0
    s1 = s4;
    cout << (s1 == s2) << endl; // 0
    cout << (s1 == s3) << endl; // 0
    cout << (s1 == s4) << endl; // 1
    return 0;
}