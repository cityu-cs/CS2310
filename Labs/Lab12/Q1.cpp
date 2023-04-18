#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    public:
    string name, sid, tel;
    Student() {}
    Student(string name, string sid, string tel) {
        this->name = name;
        this->sid = sid;
        this->tel = tel;
    }
};

int main() {
    ifstream fin("lab12.txt");
    ofstream fout("lab12_output.txt");
    int n;
    string line;
    // getline(fin, line);
    // n = stoi(line);
    fin >> n;
    fin.ignore();
    Student *s = new Student[n];
    for (int i = 0; i < n; i++) {
        /*
        input format:
        NAME NAME, SID TELEPHONE
        */
        string line;
        getline(fin, line);
        int pos = line.find(',');
        s[i].name = line.substr(0, pos);
        line = line.substr(pos + 2); // a space follows the comma
        pos = line.find(' ');
        s[i].sid = line.substr(0, pos);
        s[i].tel = line.substr(pos + 1);
    }
    for (int i = 0; i < n; i++) {
        fout << "Student " << i + 1 << ": " << endl;
        fout << "Name: " << s[i].name << endl;
        fout << "Student ID: " << s[i].sid << endl;
        fout << "Tel: " << s[i].tel << endl;
        fout << endl;
    }
    delete [] s;
    fin.close();
    fout.close();
    return 0;
}