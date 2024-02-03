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
{/*
    Car cars[3];

    for(int i = 0; i < 3; i++)
    {
        cout << endl << "Enter data for car " << i << ":" << endl;
        cout << setw(24) << "What car is it?";
        getline(cin, cars[i].info.make);
        cout << setw(24) << "What model is it?";
        getline(cin, cars[i].info.model);
        cout << setw(24) << "Year of the car:";
        cin >> cars[i].info.year;
        cin.ignore();
        cout << endl << setw(24) << "Color of the car:";
        getline(cin, cars[i].color);
        cout << setw(24) << "How much did it cost?";
        cin >> cars[i].cost;
    }

    cout << endl << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << endl << "Your car:" << endl << "Make:  " << cars[i].info.make << endl << "Model:  " << cars[i].info.model << endl << "Year:  " << cars[i].info.year;
        cout << endl << "Color:  " << cars[i].color << endl << "Cost: $" << cars[i].cost;
    }
*/
    return 0;
}