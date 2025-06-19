#include <iostream>
using namespace std;

int main()
{

    string s = "wuiswchilusuvbhvlishviuewrhq";

    for (int i = 0; i < s.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}