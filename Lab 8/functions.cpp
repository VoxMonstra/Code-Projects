#include "paranormal.h"
using namespace std;

void getParanormalData(int evps[], string names[], string dates[]){ // gets user input

    cout << endl << "Enter the name, date, and number of EVPs in the investigation";

    for(int i = 0; i < INVESTIGATORS; i++){
        
        cout << endl << "Investigator " << i + 1 << " : " << endl << "Name - ";
        getline(cin, names[i]);
        cout << endl << "Day - ";
        getline(cin, dates[i]);
        cout << endl << "Number of EVPs: ";
        cin >> evps[i];
        cin.ignore();
    }
}

void getStats(int evps[], int& numRecordings, float&avgNumRecordings, int& index){ // processes and stores data
    int hold = evps[0];
    for(int i = 0; i < INVESTIGATORS; i++){
        if(evps[i] >= hold){
            hold = evps[i];
            index = i;
        }
        numRecordings += evps[i];
    }
    avgNumRecordings = float(numRecordings) / INVESTIGATORS;
}