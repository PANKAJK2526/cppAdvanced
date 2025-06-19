#include <iostream>

using namespace std;

class B;

class A
{
private:
	int x;

protected:
	int y;

public:
	A() : x(1), y(2) {};
	friend void fun(A &, B &);
};

class B
{
private:
	int z;

protected:
	int q;

public:
	B() : z(3), q(4) {};
	friend void fun(A &, B &);
};

void fun(A &a, B &b)
{
	cout << "Friend function Executed! " << a.x << " " << a.y << " " << b.z << " " << b.q << endl;
}

int main()
{
	A a;
	B b;
	fun(a, b);
	return 0;
}