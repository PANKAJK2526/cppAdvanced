#include <iostream>

using namespace std;

int main()
{
    int *x = new int(1);
    int *ptr = x;
    cout << *ptr << endl;
    delete x;
    cout << *ptr << endl;

    return 0;
}