#include <iostream>
using namespace std;

class Date
{
public:
    int mo, da, yr;
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    // friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

int main()
{
    Date dt(5, 6, 92);
    cout << dt << endl;
}