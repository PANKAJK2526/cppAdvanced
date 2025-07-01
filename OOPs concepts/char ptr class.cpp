#include<iostream>
#include<string.h>

using namespace std;

class MyString
{

public:

	char *str;

	MyString()
	{
		str = nullptr;
	}

	MyString(char *str)
	{
		this->str = new char[strlen(str)+1];;
		strcpy(this->str,str);
	}

	MyString &operator= (const MyString &obj)
	{
		if(this != &obj)
		{
			delete[] this->str;
			this->str = new char[strlen(obj.str)+1];
			strcpy(this->str,obj.str);
		}
		return *this;
	}

	~MyString()
	{
		delete[] this->str;
	}

};

int main()
{
	MyString ms1;
	char msg[] = {'p','a','n','k','a','j','\0'};
	MyString ms2(msg);
	ms1 = ms2;
	cout<<ms1.str<<endl<<ms2.str<<endl;

	return 0;
}