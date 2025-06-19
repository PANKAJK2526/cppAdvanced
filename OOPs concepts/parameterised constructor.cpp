#include <iostream>

using namespace std;

class Student
{
    int rno;
    char name[50];
    double fee;

public:
    Student(int, const char[], double);
    void display();
};

Student::Student(int rno, const char name[], double fee)
{
    this->rno = rno;
    strcpy_s(this->name, name);
    this->fee = fee;
}

void Student::display()
{
    cout << endl
         << this->rno << endl
         << this->name << endl
         << this->fee << endl;
}

int main()
{
    Student s(21, "Krishna Gopal", 250.70);
    s.display();
    return 0;
}