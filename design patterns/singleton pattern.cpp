#include <iostream>

using namespace std;

class Singleton
{
private:
    string name;
    int id;

    static Singleton *obj;

    Singleton() {}

public:
    Singleton(const Singleton &obj) = delete;

    static Singleton *getinstance()
    {
        if (obj == NULL)
        {
            obj = new Singleton();
            return obj;
        }
        else
        {
            return obj;
        }
    }

    void setter(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    void getter()
    {
        cout << this->name << " " << this->id << endl;
    }
};

int main()
{
    Singleton *obj = Singleton::getinstance();

    obj->setter("pankaj", 101);
    obj->getter();

    // Singleton* obj1 = new Singleton();
    // Singleton* obj1 = new Singleton("kumar", 21);

    Singleton *obj1 = obj;

    return 0;
}