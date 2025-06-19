#include <iostream>
#include <memory>
using namespace std;

class Foo
{

public:
    int x = 1;

    void print()
    {
        cout << "Hello, World!" << " " << this->x << endl;
    }
};

int main()
{
    unique_ptr<Foo> ptr = make_unique<Foo>();
    ptr->print();

    unique_ptr<Foo> ptr2 = move(ptr); // only move semantics allowed, assignment not allowed
    ptr2->print();

    ptr->print(); // ptr points to null or we can say ptr = nullptr after move statement

    return 0;
}