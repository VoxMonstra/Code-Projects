/*
*   Title: program4.cpp
*   Author: Noah Gregory
*   Date: 11/3
*   Purpose: To gather data about the number of hours college kids spend watching netflix
*/

#include "netflix.h"

int main(){
    int numStudents, mode;
    double average, median;
    int* students;

    cout << "How many students were surveyed?" << endl;

    numStudents = getNumStudents();
    
    students = makeArray(numStudents);

    getStudentData(students, numStudents);

    average = getAverage(students, numStudents);

    sortArray(students, numStudents);

    mode = getMode(students, numStudents);

    median = getMedian(students, numStudents);

    printArray(students, numStudents);

    cout << "\tNETFLIX STATISTICS:" << endl;

    cout << endl << "Average: " << setprecision(2) << fixed << average << endl << "Mode: ";
    if(mode != -1){
        cout << *(students + mode) << endl;
    }
    else
    {
        cout << "There is no mode" << endl; 
    }
    cout << "Median: " << setprecision(2) << fixed << median;

    delete [] students;

    return 0;
}
