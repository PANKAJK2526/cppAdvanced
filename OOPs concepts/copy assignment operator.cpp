#include <iostream>

using namespace std;

class A
{
    int x;
    char y;

public:
    A(int x = 0, char y = 0) : x(x), y(y) {};

    A(const A &obj)
    {
        cout << "Copy Constructor Called!" << endl;

        this->x = obj.x;
        this->y = obj.y;
    }

    A &operator=(const A &obj)
    {
        cout << "Copy Assignment Operator Called!" << endl;
        this->x = obj.x;
        this->y = obj.y;

        return *this;
    }
};

int main()
{
    A obj1(1, 'a');
    A obj2 = obj1;
    A obj3;
    obj3 = obj2;

    return 0;
}