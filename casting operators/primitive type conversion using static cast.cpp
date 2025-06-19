#include <iostream>
using namespace std;

int main()
{

    double pi = 3.14;
    int intpi = static_cast<int>(pi); // truncates to 3
    cout << intpi << endl;

    return 0;
}