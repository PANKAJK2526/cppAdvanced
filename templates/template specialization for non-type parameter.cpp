#include <iostream>
using namespace std;

template <int x>
class Identity
{

public:
    int i;

    Identity()
    {
        this->i = x;
    }

    void display()
    {
        cout << i << endl;
    }
};

template <>
class Identity<0>
{
public:
    int i;

    Identity()
    {
        this->i = 21;
    }

    void display()
    {
        cout << i << endl;
    }
};

int main()
{
    Identity<5> i;
    i.display();

    Identity<0> j;
    j.display();

    return 0;
}