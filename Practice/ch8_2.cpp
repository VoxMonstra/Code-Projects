#include <iostream>
#include <iomanip>
using namespace std;

struct CarInfo
{
    string make;
    string model;
    int year;
};

struct Car
{
    CarInfo info;
    string color;
    double cost;
};

int main()
{
    Car cars[3];

    for(int i = 0; i < 3; i++)
    {
        cout << endl << "Enter data for car " << i + 1 << ":" << endl << endl;
        cout << setw(24) << left << "What car is it?";
        getline(cin, cars[i].info.make);
        cout << setw(24) << left << "What model is it?";
        getline(cin, cars[i].info.model);
        cout << setw(24) << left << "Year of the car:";
        cin >> cars[i].info.year;
        cin.ignore();
        cout << setw(24) << left << "Color of the car:";
        getline(cin, cars[i].color);
        cout << setw(24) << left << "How much did it cost?";
        cin >> cars[i].cost;
        cin.ignore();
    }

    cout << endl << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << endl << "Car " << i + 1 << ":" << endl << setw(24) << left << "Make:  " << cars[i].info.make << endl << setw(24) << left << "Model:  " << cars[i].info.model << endl << setw(24) << left << "Year:  " << cars[i].info.year;
        cout << endl << setw(24) << left << "Color:  " << cars[i].color << endl << setw(24) << left << "Cost: " << "$" << cars[i].cost << endl;
    }

    return 0;
}