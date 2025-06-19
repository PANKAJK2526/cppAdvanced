#include <iostream>

using namespace std;

class vehicle
{
public:
    vehicle()
    {
        cout << "this is a vehicle\n";
    }

    void gaddi()
    {
        cout << "punjab di gaddi" << endl;
    }
};

class fourwheeler
{
public:
    fourwheeler()
    {
        cout << "this is a 4 wheeler vehicle\n";
    }

    void gaddi()
    {
        cout << "chak de phatte" << endl;
    }
};

class car : public vehicle, public fourwheeler
{
};

int main()
{
    car obj;
    // obj.gaddi();
    obj.vehicle::gaddi();
    obj.fourwheeler::gaddi();
    return 0;
}