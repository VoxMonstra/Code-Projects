/*
*   Title: ch8_3.cpp
*   Author: Noah Gregory
*   Date: 11/22
*   Purpose: to use dynamically allocated array of structures to display phones
*/

#include <iostream>
using namespace std;

const int SIZE = 5;

struct Phone
{
    string type;
    string color;
    int memory;
};

void addPhone(Phone* phones)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << endl << "Enter the data for phone " << (i + 1) << endl << "Type:\t";
        getline(cin, phones[i].type);

        cout << endl << "Color:\t";
        getline(cin, phones[i].color);

        cout << endl << "What is the capacity (in GB):\t";
        cin >> phones[i].memory;
        cin.ignore();
        cout << endl << endl;
    }
}

void printArray(Phone* phones)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Phone: " << phones[i].type << endl;
        cout << "Color: " << phones[i].color << endl;
        cout << "Memory: " << phones[i].memory << " GB" << endl << endl << endl;
    }

}

int main()
{
    Phone* phones;
    phones = new Phone[SIZE];

    addPhone(phones);

    printArray(phones);

    delete [] phones;
    return 0;
}