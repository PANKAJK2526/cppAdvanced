#include<iostream>

using namespace std;

int main()
{

	int *ptr;
	//cout<<*ptr<<" at "<<&ptr<<endl; Segmentation Fault

	ptr = new int(1);
	cout<<*ptr<<" at "<<&ptr<<endl;

	ptr = new int[10]();

	for(int i=0; i<10; i++)
	cout<<ptr[i]<<" at "<<&ptr[i]<<endl;

	for(int i=0; i<10; i++)
	ptr[i]=5;

	for(int i=0; i<10; i++)
	cout<<ptr[i]<<" at "<<&ptr[i]<<endl;

	delete[] ptr;

	int *(*x);

	x = new int*[3];
	for(int i=0; i<3; i++)
	{
		x[i] = new int[4]();
	}

	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
			x[i][j]=7;

	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
			cout<<x[i][j]<<" at "<<&x[i][j]<<endl;

	for(int i=0; i<3; i++)
	{
		delete[] x[i];
	}

	return 0;
}