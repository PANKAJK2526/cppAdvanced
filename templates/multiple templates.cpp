#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s)
    {
        this->first = f;
        this->second = s;
    }

    void display()
    {
        cout << first << endl
             << second << endl;
    }
};

int main()
{

    Pair<int, string> p(7, "riyotsu");
    p.display();

    return 0;
}