#include <iostream>

using namespace std;

class Test
{
public:
    void fun()
    {
        cout << "fun() called" << endl;
    }

    void fun() const
    {
        cout << "fun() const called" << endl;
    }

    void fun(const int *t)
    {
        cout << "func(const int *t) called" << endl;
    }

    void fun(int *t)
    {
        cout << "func(int *t) called" << endl;
    }

    void fun(int t)
    {
        cout << "func(int t) called" << endl;
    }

    void fun(const int *t) const
    {
        cout << "func(const int *t) const called" << endl;
    }

    void fun(int *t) const
    {
        cout << "func(int *t) const called" << endl;
    }

    void fun(int t) const
    {
        cout << "func(int t) const called" << endl;
    }
};

int main()
{
    Test t1;
    const Test t2;

    t1.fun();
    t2.fun();

    const int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int c = 9;

    t1.fun(a);
    t1.fun(b);
    t1.fun(c);

    t2.fun(a);
    t2.fun(b);
    t2.fun(c);

    return 0;
}