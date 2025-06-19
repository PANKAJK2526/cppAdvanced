#include <iostream>
#include <string.h>
using namespace std;

class Copy
{

public:
    char *name;

    Copy(char *name)
    {
        strcpy(this->name, name);
    }

    // Copy Constructor only for Deep Copy

    // Copy(Copy &c)
    // {
    //     this->name = new char[50];
    //     strcpy(this->name, c.name);
    // }
};

int main()
{

    char name[50] = "Pankaj";

    Copy obj1(name);
    Copy obj2 = obj1;

    cout << "Initial Values were: \nobj1: " << obj1.name << "\nobj2: " << obj2.name << endl;

    char newname[50] = "Kumar";
    strcpy(obj1.name, newname);
    cout << "Changing the value of obj1, ideally obj2 and obj1 are different so, change in obj1 should not affect obj2" << endl;

    cout << "Final Values are: \nobj1: " << obj1.name << "\nobj2: " << obj2.name << endl;

    return 0;
}