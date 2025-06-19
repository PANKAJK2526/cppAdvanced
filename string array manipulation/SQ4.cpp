#include <iostream>
using namespace std;

int main()
{

    string s = "geekforgeeks";

    int freq[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }

    for (int i = 0, j = 0; i < s.length() || j < 256; i++)
    {
        if (freq[s[i]] == 1)
        {
            cout << s[i] << endl;
            break;
        }
    }

    return 0;
}