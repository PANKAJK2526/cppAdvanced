#include <iostream>
using namespace std;

template <typename T>
class Identity
{
public:
    void display()
    {
        cout << "Generic Type..." << endl;
    }
};

template <>
class Identity<int>
{

public:
    void display()
    {
        cout << "Int Type Specialized..." << endl;
    }
};

int main()
{
    Identity<double> d;
    d.display();

    Identity<int> i;
    i.display();

    return 0;
}