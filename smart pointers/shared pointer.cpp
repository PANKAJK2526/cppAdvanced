#include <iostream>
#include <memory>
using namespace std;

class Foo
{
};

int main()
{

    shared_ptr<Foo> ptr = make_shared<Foo>();
    cout << ptr.use_count() << endl;
    {
        shared_ptr<Foo> ptr2 = ptr;
        cout << ptr.use_count() << endl;
    } // object destroyed and memory freed here for 1st time
    cout << ptr.use_count() << endl;

    return 0;
} // object destroyed and memory freed here for 2nd time