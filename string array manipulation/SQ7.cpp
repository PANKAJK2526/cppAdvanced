#include <iostream>
using namespace std;

int main()
{

    string s = "banana";
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            count++;
            for (int j = i; j < s.length(); j++)
                s[j] = s[j + 1];
        }
        else
        {
        }
    }

    cout << s;

    return 0;
}