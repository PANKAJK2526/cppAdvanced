#include <iostream>
using namespace std;

int main()
{

    string s = "A man a plan a canal Panama";

    int flag = 0;
    for (int i = 0, j = s.length() - 1; i < j;)
    {
        if (s[i] == ' ' && s[j] == ' ')
        {
            i++;
            j--;
        }
        else if (s[i] == ' ' && s[j] != ' ')
        {
            i++;
        }
        else if (s[i] != ' ' && s[j] == ' ')
        {
            j--;
        }
        else
        {

            cout << s[i] << " " << s[j] << endl;
            if (tolower(s[i]) != tolower(s[j]))
            {
                flag = 1;
            }

            i++;
            j--;
        }
    }

    if (flag == 0)
    {
        cout << "Palindrome";
    }

    return 0;
}