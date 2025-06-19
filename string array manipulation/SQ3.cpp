#include <iostream>
using namespace std;

int main()
{

    string s = "I am here";
    int spaceCount = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            spaceCount++;
        }
    }

    string s1[spaceCount];

    for (int i = 0, j = 0; j < s.length(); j++)
    {

        if (s[j] == ' ')
        {
            i++;
        }
        else
        {
            s1[i] += s[j];
        }
    }

    for (int i = spaceCount - 1; i >= 0; i--)
    {
        cout << s1[i] << " ";
    }

    return 0;
}