#include <iostream>
using namespace std;

class Set
{
public:
    int *a;
    string s;
    int size;

    Set(int *a, int size)
    {
        this->a = a;
        this->size = size;
    }

    Set(string s, int size)
    {
        this->s = s;
        this->size = size;
    }

    void print_int()
    {
        int res[size];
        int newsize = 0;
        for (int i = 0; i < size; i++)
        {
            int flag = 0;
            for (int j = i + 1; j < size; j++)
            {
                if (a[i] == a[j])
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                res[newsize++] = a[i];
            }
        }

        for (int n = 0; n < newsize; n++)
        {
            for (int m = 0; m < newsize; m++)
            {
                if (res[m + 1] < res[m])
                {
                    int temp = res[m + 1];
                    res[m + 1] = res[m];
                    res[m] = temp;
                }
            }
        }

        for (int o = 0; o < newsize; o++)
        {
            cout << res[o] << " ";
        }
    }

    void print_string()
    {
        char res[size];
        int newsize = 0;
        for (int i = 0; i < size; i++)
        {
            int flag = 0;
            for (int j = i + 1; j < size; j++)
            {
                if (s[i] == s[j])
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                res[newsize++] = s[i];
            }
        }

        for (int n = 0; n < newsize; n++)
        {
            for (int m = 0; m < newsize; m++)
            {
                if (res[m + 1] < res[m])
                {
                    char temp = res[m + 1];
                    res[m + 1] = res[m];
                    res[m] = temp;
                }
            }
        }

        for (int o = 0; o <= newsize; o++)
        {
            cout << res[o] << " ";
        }
    }
};

int main()
{

    string s = "adadsdadvsdasdasad";
    int a[] = {1, 2, 2, 1, 2, 2, 4, 4, 3, 5, 2, 1, 1};
    int size = sizeof(a) / sizeof(a[0]);
    Set s2 = Set(a, size);
    s2.print_int();
    size = s.length();
    Set s1 = Set(s, size);
    s1.print_string();
    return 0;
}