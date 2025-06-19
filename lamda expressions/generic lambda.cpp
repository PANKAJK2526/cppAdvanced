#include<iostream>

using namespace std;

int main()
{

    auto print = [](auto x) {
        std::cout << x << std::endl;
    };

    print(10);       // int
    print(3.14);     // double
    print("hello");  // const char*

    return 0;
}