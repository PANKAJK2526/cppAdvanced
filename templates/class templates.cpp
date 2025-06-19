#include <iostream>
using namespace std;

template <typename T>
class Box
{
    T value;

public:
    Box(T v) { this->value = v; }
    T getter() { return value; }
};

int main()
{

    Box<int> b(42);
    cout << b.getter() << endl;

    return 0;
}