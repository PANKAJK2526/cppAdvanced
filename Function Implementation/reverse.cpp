#include <iostream>
using namespace std;

class Reverse
{

public:
    string s;

    Reverse(string s)
    {
        this->s = s;
    }

    void print()
    {
        int n = s.length();

        for (int i = 0, j = n - 1; i < n && i <= j;)
        {

            if (isalpha(s[i]) && isalpha(s[j]))
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            else if (isalpha(s[i]) && !isalpha(s[j]))
            {
                j--;
            }
            else if (!isalpha(s[i]) && isalpha(s[j]))
            {
                i++;
            }
            else if (!isalpha(s[i]) && !isalpha(s[j]))
            {
                i++;
                j--;
            }
        }

        cout << s;
    }
};

int main()
{
    string s = "l98498498jkhascbuiywsdbciscksncdilsdbd651616c";

    Reverse r = Reverse(s);
    r.print();

    return 0;
}