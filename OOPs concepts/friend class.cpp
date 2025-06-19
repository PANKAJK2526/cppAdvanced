#include <iostream>

using namespace std;

class A
{
private:
	int x;

protected:
	int y;

public:
	A() : x(10), y(99) {};

	friend class B;
};

class B
{
public:
	void fun(A &obj)
	{
		cout << "Friend Class Executed! : " << obj.x << " " << obj.y;
	}
};

int main()
{
	A a;
	B b;
	b.fun(a);
	return 0;
}