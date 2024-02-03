/*
*   Title: driver.cpp
*   Author: Noah Gregory
*   Date: 10/25
*   Purpose: to compute the total, average, and mode EVPs from investigators in a haunted location
*/
#include "paranormal.h"
using namespace std;

int main(){
    //Declaring variables
    int numRecordings, index; 
    float avgNumRecordings;
    char location[100];
    int evps[INVESTIGATORS];
    string names[INVESTIGATORS];
    string dates[INVESTIGATORS];

    cout << "What location where you investigating?";

    cin.getline(location, 100);

    getParanormalData(evps, names, dates);

    getStats(evps, numRecordings, avgNumRecordings, index);

    for(int i = 0; i < 80; i ++){
        cout << "-";
    }

    cout << endl << "The total amount of EVPs recorded by all " << INVESTIGATORS << " investigators at " << location << " is " << numRecordings << ".";
    cout << endl << "The average amount of EVPs recorded at " << location << " is " << avgNumRecordings << " recordings." << endl; 
    cout << "The investigator who recorded the most (" << evps[index] << " recordings) is " << names[index] << " on " << dates[index] << "." << endl;

    for(int i = 0; i < 80; i++){
        cout << "-";
    }

    return 0;
}