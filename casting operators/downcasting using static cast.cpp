#include <iostream>
using namespace std;

class Base
{
public:
    virtual void dummy() { cout << "Base Class\n"; }
};

class Derived : public Base
{
public:
    void dummy() { cout << "Derived Class\n"; }
};

int main()
{

    Base *b1 = new Derived();
    Derived *b2 = static_cast<Derived *>(b1); // downcasting not safe
    b2->dummy();

    return 0;
}