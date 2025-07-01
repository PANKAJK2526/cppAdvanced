#include<iostream>

using namespace std;

template <typename T>
class UniquePtr 
{

	T *ptr;

public:

	UniquePtr()
	{
		this->ptr = nullptr;
	}

	UniquePtr(T *ptr)
	{
		this->ptr = ptr;
	}

	UniquePtr(const UniquePtr &obj) = delete;
	UniquePtr &operator= (const UniquePtr &obj) = delete;

	UniquePtr(UniquePtr && obj)
	{
		this->ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	UniquePtr & operator=(UniquePtr && obj)
	{
		if(this != &obj)
		{
			release();
			this->ptr = obj.ptr;
			obj.ptr = nullptr;
		}
		return *this;
	}

	void release()
	{
		delete this->ptr;
	}

	T & operator*()
	{
		return *(this->ptr);
	}

	T * operator->()
	{
		return (this->ptr);
	}

	~UniquePtr()
	{
		release();
	}

};

int main()
{

	UniquePtr<int> ptr1(new int(1)); 

	UniquePtr<int> ptr2;
	
	ptr2 = move(ptr1);

	return 0;
}