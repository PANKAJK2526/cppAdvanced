#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

    string arr[] = {"apple", "banana", "cherry"};
    string target = "banana";

    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Found the target :"<<*(find(arr, arr+size,target));

    return 0;
}