#include <iostream>

using namespace std;

#define a 5

#define c(a, b) (a > b)

#define z(a, b, c) ((a > b) ? ((a > c) ? a : ((c > b) ? c : b)) : ((b > c) ? b : ((c > a) ? c : a)))

int main()
{
    cout << a << endl;
    cout << c(1, 2) << endl;
    cout << c(5, 2) << endl;
    cout << z(1, 2, 3) << endl;
    cout << z(3, 2, 1) << endl;

    return 0;
}
