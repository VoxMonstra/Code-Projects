#ifndef NETFLIX_H
#define NETFLIX_H

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int getNumStudents();
int* makeArray(int);
void getStudentData(int*, int);
void printArray(int*, int);
double getAverage(int*, int);
int getMode(int*, int);
double getMedian(int*, int);
void sortArray(int*, int);

#endif