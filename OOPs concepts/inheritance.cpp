#include <iostream>
using namespace std;

class Base
{
public:
    void virtual firstfun() { cout << "class base function firstfun" << endl; };
    void secondfun() { cout << "class base function secondfun" << endl; };
};

class Derived : public Base
{
public:
    void firstfun() { cout << "class Derived function firstfun" << endl; };
    void secondfun() { cout << "class Derived function secondfun" << endl; };
};

int main()
{

    Base *ptr = new Derived();
    ptr->firstfun();
    ptr->secondfun();

    return 0;
}