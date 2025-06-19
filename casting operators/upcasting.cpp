#include <iostream>
using namespace std;

class Base
{
};
class Derived : public Base
{
};

int main()
{

    Derived d;
    Base *b = static_cast<Base *>(&d); // upcasting is safe

    return 0;
}