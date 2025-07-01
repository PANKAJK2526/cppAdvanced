#include<iostream>
#include<memory>

using namespace std;

class Foo {};

int main()
{

	shared_ptr<Foo> ptr1(new Foo());

	cout<<ptr1.use_count()<<endl;
	{
		shared_ptr<Foo> ptr2 = ptr1;
		cout<<ptr1.use_count()<<endl;
	}

	cout<<ptr1.use_count()<<endl;

	return 0;
}