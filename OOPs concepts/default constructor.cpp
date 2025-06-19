#include <iostream>

using namespace std;

class Student
{
    int rno;
    char name[50];
    double fee;

public:
    Student()
    {
        cout << "Enter the roll no.";
        cin >> rno;
        cout << "Enter the name";
        cin >> name;
        cout << "Enter the fee";
        cin >> fee;
    }

    void display()
    {
        cout << endl
             << rno << endl
             << name << endl
             << fee << endl;
    }
};

int main()
{
    Student s;
    s.display();

    return 0;
}