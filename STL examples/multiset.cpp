#include<iostream>
#include<set>
using namespace std;

int main()
{
    multiset<int> s = {1,2,3,3,3,4,5,5};

    for(auto i : s)
    {
        cout<<i<<" ";
    }


    return 0;
}