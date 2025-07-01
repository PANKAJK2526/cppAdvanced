#include<iostream>
#include<memory>

using namespace std;

class Foo 
{
public:
		int value;
		
		Foo()
		{
			this->value = 0;
		}

};

int main()
{

	//Normal unique_ptr statement
	unique_ptr<Foo> ptr1;

	//unique_ptr statement with new statement for memory allocation of size 1 but initialize with zero
	unique_ptr<Foo> ptr2(new Foo());

	//unique_ptr statement with new statement for memory allocation of size 50
	unique_ptr<Foo[]> ptr3(new Foo[50]());

	//assign a value 5 to each of the memory allocated above
	ptr2->value = 5;

	for(int i=0; i<50; i++)
	{
		ptr3[i].value = 5;
	}

	//pointer to unique_ptr statement and allocate memory to each 2d array
	unique_ptr<unique_ptr<Foo[]>[]> ptr4(new unique_ptr<Foo[]>[3]);

	for(int i=0; i<3; i++)
		ptr4[i] = unique_ptr<Foo[]>(new Foo[4]());

	//assign a value 7 to each of the memory allocated above
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			ptr4[i][j].value = 5;

	return 0;
}