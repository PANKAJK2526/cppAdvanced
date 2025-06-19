#include <iostream>
using namespace std;

void byValue(int x) { x += 10; }
void byRef(int &x) { x += 10; }
void byValue(const int x) { cout << "Read-only: " << x << endl; }
void byConstRef(const int &x) { cout << "Read-only: " << x << endl; }

int main()
{
    int a = 5;
    const int a = 5;
    byValue(a);
    cout << "After Passing by Value: " << a << endl;
    byRef(a);
    cout << "After Passing by Reference: " << a << endl;
    byValue(a);
    byConstRef(a);

    return 0;
}