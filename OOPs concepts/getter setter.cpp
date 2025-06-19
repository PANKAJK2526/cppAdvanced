#include <iostream>

using namespace std;

class A
{
    int x;
    string y;

public:
    A(int x, string y);
    int IntGetter();
    string StringGetter();
    void IntSetter(int x);
    void StringSetter(string y);
};

A::A(int x, string y)
{
    this->x = x;
    this->y = y;
}

int A::IntGetter()
{
    return this->x;
}

string A::StringGetter()
{
    return this->y;
}

void A::IntSetter(int x)
{
    this->x = x;
}

void A::StringSetter(string y)
{
    this->y = y;
}

int main()
{
    A obj(1, "11");
    obj.IntSetter(2);
    obj.StringSetter("22");
    cout << obj.IntGetter() << endl
         << obj.StringGetter() << endl;

    return 0;
}