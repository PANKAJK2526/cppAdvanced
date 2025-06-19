#include <iostream>
using namespace std;

int main()
{

    string s = "aaahhhhtyttyyuuyuygfhygggggfffdddeee";
    int freq[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (freq[s[i]] > 0)
        {
            cout << s[i] << freq[s[i]];
            freq[s[i]] = 0;
        }
    }

    return 0;
}