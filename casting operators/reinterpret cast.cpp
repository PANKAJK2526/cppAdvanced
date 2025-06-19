#include <iostream>
using namespace std;

int main()
{
    double pi = 3.14;

    double doubleBits = *reinterpret_cast<double *>(&pi);
    cout << "Double value: " << pi << endl;

    int intBits = *reinterpret_cast<int *>(&pi); // only for bit manipulation/monitoring/serialization purposes
    cout << "Interpreted as int: " << intBits << endl;

    return 0;
}
