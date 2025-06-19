#include <iostream>
#include <memory>
using namespace std;

class Shape
{
public:
    void virtual draw() = 0;
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Circle..." << endl;
    }
};

class Cube : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Cube..." << endl;
    }
};

class Factory
{
public:
    static unique_ptr<Shape> createShape(string type)
    {
        if (type == "circle")
            return make_unique<Circle>();
        else if (type == "cube")
            return make_unique<Cube>();
        else
            return nullptr;
    }
};

int main()
{

    unique_ptr<Shape> shape1 = Factory::createShape("circle");
    unique_ptr<Shape> shape2 = Factory::createShape("cube");

    if (shape1)
        shape1->draw();
    if (shape2)
        shape2->draw();

    return 0;
}