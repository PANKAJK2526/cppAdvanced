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
    void secret() { cout << "Secret Function\n"; }
};

int main()
{

    Base *b1 = new Derived();
    Derived *b2 = dynamic_cast<Derived *>(b1);
    b2->dummy();
    // b1->secret();          doesn't work, need to use casting like dynamic casting
    b2->secret();

    return 0;
}