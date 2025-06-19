#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add<int>(3, 4) << endl;
    cout << add<float>(2.5, 3.1) << endl;

    return 0;
}