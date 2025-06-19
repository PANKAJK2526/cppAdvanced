#include<iostream>
#include<map>
using namespace std;

int main()
{
    multimap<int,string> m = {{1,"Pankaj"},{3,"Alisha"},{2,"Babita"},{2,"Sonam"}};

    for(auto i : m)
    {
        cout<<i.first<<":";
        cout<<i.second<<endl;
    }

    return 0;
}