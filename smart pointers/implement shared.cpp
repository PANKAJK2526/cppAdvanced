#include<iostream>

using namespace std;

template<typename T>
class MySharedPtr {
    T* ptr;
    int* ref_count;

public:
    MySharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}
    
    MySharedPtr(const MySharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    ~MySharedPtr() {
        release();
    }

    void release() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

int main()
{
    

    return 0;
}