#include <iostream>

using namespace std;

class A
{
    int i;

public:
    A(int);
};

A::A(int arg)
{
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}