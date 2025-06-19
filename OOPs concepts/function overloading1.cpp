#include <iostream>

using namespace std;

void add(int a, int b)
{
    cout << "sum = " << (a + b) << endl;
}

void add(double a, double b)
{
    cout << "sum = " << (a + b) << endl;
}

void add(int a, int b, int c)
{
    cout << "sum = " << (a + b + c) << endl;
}

void add(double a, int b)
{
    cout << "sum = " << (a + b) << endl;
}

int main()
{
    add(10, 2);
    add(5.3, 6.2);
    add(5, 6, 4);
    add(5.5, 6);

    return 0;
}