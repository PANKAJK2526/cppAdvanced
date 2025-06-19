#include <iostream>

using namespace std;

class Greet
{

public:
    void operator()()
    {
        cout << "Hello World!" << endl;
    }

    void operator()(string name)
    {
        cout << "Hello " << name << endl;
    }
};

int main()
{
    Greet g;

    g();

    g("Pankaj");

    return 0;
}