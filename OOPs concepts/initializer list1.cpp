#include <iostream>

using namespace std;

// class A
//{
//	int& x;
//
// public:
//
//	//A(int x)
//	//{
//	//	this->x = x;
//	//}
//
//	A(int x) :x(x) {};
// };
//
// int main()
//{
//	A x(1);
//
//	return 0;
// }

class B
{
    const int t;

public:
    B(int t) : t(t) {}
};

int main()
{
    B obj(10);

    return 0;
}