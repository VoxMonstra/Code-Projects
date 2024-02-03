/*
*   Title: function.cpp
*   Author: Noah Gregory
*   Date: 11/15
*   Purpose: To use allocated arrays of allocated arrays
*/

#include "pollution.h"

void enterFactoryNames(string* factoryNames)
{
    cout << "What is the name of the first factory:" << endl;
    getline(cin, *(factoryNames));

    cout << endl << "What is the name of the second factory: " << endl;
    getline(cin, *(factoryNames + 1));

    cout << endl << "What is the name of the third factory:" << endl;
    getline(cin, *(factoryNames + 2));

}

float* makeArray(int years)
{
    float* array;
    array = new float[years];
    return array;
}

void enterCOData(float* array, int years)
{
    cout << "Carbon Monoxide (CO) average level per hour (in parts per million)";

    for(int i = 0; i < years; i++)
    {
        cout << endl << "\tYEAR " << i + 1 << ":\t";
        cin >> *(array + i);
    }
    cout << endl << endl;
}

void enterNO2Data(float* array, int years)
{
    cout << "Nitrogen Oxide (NO2) average level per hour (in parts per million)";

    for(int i = 0; i < years; i++)
    {
        cout << endl << "\tYEAR " << i + 1 << ":\t";
        cin >> *(array + i);
    }
    cout << endl << endl;
}

void enterO3Data(float* array, int years)
{
    cout << "Ozone (O3) average level per eight hours (in parts per million))";

    for(int i = 0; i < years; i++)
    {
        cout << endl << "\tYear " << i + 1 << ":\t";
        cin >> *(array + i);
    }
    cout << endl << endl;
}

void printOverLimit(string* factoryNames, float** factoryData, int years, float limit)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < years; j++)
        {
            if(*(*(factoryData + i) + j) > limit)
            {
                cout << *(factoryNames + i) << endl;
                break;
            }
        }
    }
}

void getLargest(string* factoryNames, float** factoryData, int years, float& largest, string& largestFactory, int& largestYear)
{
    largest = 0;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < years; j++)
        {
            if(*(*(factoryData + i) + j) > largest)
            {
                largest = *(*(factoryData + i) + j);
                largestYear = j;
                largestFactory = *(factoryNames + i);
            }
        }
    }

}