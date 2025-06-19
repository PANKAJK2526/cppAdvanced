#include <iostream>

using namespace std;

// class A
//{
// public:
//	A()
//	{
//		cout << "Class object A constructed!" << endl;
//	}
//
//	~A()
//	{
//		cout << "Class object A destroyed!" << endl;
//	}
// };

class A
{
public:
    A()
    {
        cout << "Class object A constructed!" << endl;
    }

    virtual ~A()
    {
        cout << "Class object A destroyed!" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "Class object B constructed!" << endl;
    }

    ~B()
    {
        cout << "Class object B destroyed!" << endl;
    }
};

int main()
{
    B obj2;
    A *obj1 = &obj2;

    delete obj1;

    return 0;
}