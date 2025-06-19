#include <iostream>

using namespace std;

int main()
{
    string arr[10] = {"q", "g", "t", "uu", "ghj", "yo", "hi", "bye"};
    string find = "bye";

    for (string i : arr)
        if (i.compare(find) == 0)
        {
            cout << "Found " << find << " in the array";
            return 0;
        }

    cout << "Cannot find " << find << " in the array";

    return 0;
}