#include <iostream>
using namespace std;

class Counter
{
public:
    int *a;
    string s;
    int size;

    Counter(int *a, int size)
    {
        this->a = a;
        this->size = size;
    }

    Counter(string s, int size)
    {
        this->s = s;
        this->size = size;
    }

    void print_int()
    {
        int m[size][2];
        for (int i = 0; i < size; i++)
        {
            int temp = a[i];
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (a[j] == temp)
                {
                    count++;
                }
            }

            int flag = 0;
            for (int k = 0; k < i; k++)
            {
                if (m[k][0] == temp)
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                m[i][0] = temp;
                m[i][1] = count;

                cout << temp << ":" << count << " ";
            }
        }
    }

    void print_string()
    {
        char m[size][2];
        for (int i = 0; i < size; i++)
        {
            char temp = s[i];
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (s[j] == temp)
                {
                    count++;
                }
            }

            int flag = 0;
            for (int k = 0; k < i; k++)
            {
                if (m[k][0] == temp)
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                m[i][0] = temp;
                m[i][1] = count;

                cout << char(temp) << ":" << count << " ";
            }
        }
    }
};

int main()
{
    string s = "adadsdadvsdasdasad";
    int a[] = {1, 2, 2, 1, 2, 2, 4, 4, 3, 5, 2, 1, 1};
    int size = sizeof(a) / sizeof(a[0]);
    Counter c2(a, size);
    c2.print_int();
    cout << endl
         << endl;
    size = s.length();
    Counter c1(s, size);
    c1.print_string();

    return 0;
}
