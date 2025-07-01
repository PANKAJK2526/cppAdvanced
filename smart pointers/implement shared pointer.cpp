#include<iostream>

using namespace std;

template<typename T>
class MySharedPtr {

	T *ptr;
	int *ref_count;

	public:

		MySharedPtr()
		{
			this->ptr = nullptr;
			this->ref_count = new int();
		} 

		MySharedPtr(T *ptr)
		{
			this->ptr = ptr;
			this->ref_count = new int(1);
		} 

		MySharedPtr(const MySharedPtr &obj)
		{
			this->ptr = obj.ptr;
			this->ref_count = obj.ref_count;
			++(*ref_count);
		}

		MySharedPtr & operator= (const MySharedPtr &obj)
		{
			if(this != &obj)
			{
				release();
				this->ptr = obj.ptr;
				this->ref_count = obj.ref_count;
				++(*ref_count);
			}

			return *this;
		}

		void release()
		{
			--(*ref_count);
			if(*ref_count==0)
			{
				delete this->ptr;
				delete this->ref_count;
			}
		}

		int use_count() 
		{
			return *(this->ref_count);
		}

		T & operator*() 
		{
			return *(this->ptr);
		}

		T * operator->()
		{
			return (this->ptr);
		}

		~MySharedPtr() {
			release();
		}

};

int main()
{

	MySharedPtr<int> sp1(new int(100));
	cout<<"sp1 use_count: "<<sp1.use_count()<<endl;

	{

		MySharedPtr<int> sp2 = sp1;
		cout<<"sp1 use_count after it is copied to sp2: "<<sp1.use_count()<<endl;
		cout<<"sp2 use_count: "<<sp2.use_count()<<endl;

	}

	cout<<"sp1 use_count after sp2 destroyed: "<<sp1.use_count()<<endl;

	return 0;
}