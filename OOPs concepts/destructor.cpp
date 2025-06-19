#include <iostream>

using namespace std;

class A
{
    static int c;

public:
    A()
    {
        cout << " Object " << c++ << " created!" << endl;
    }

    ~A()
    {
        cout << " Object " << --c << " destroyed!" << endl;
    }
};

int A::c = 1;

int main()
{
    A obj1, obj2, obj3, obj4;
    return 0;
}