/*
	Title:  	pollution.h
	Author:  	April R Crockett
	Date:  		11/13/2021
	Purpose:  	A lab assignment to practice with array of pointers
*/

//NOTE TO STUDENTS:  YOU SHOULD NOT MODIFY THIS FILE!!!
#ifndef POLLUTION_H
#define POLLUTION_H

#include <iostream>
using namespace std;

const int SIZE = 3; //number of factories
const float CO_MAX_LIMIT = 35; //35 ppm per hour
const float NO2_MAX_LIMIT = 100; //100 ppb per hour
const float O3_MAX_LIMIT = .070; //.070 ppm per 8 hours

//FUNCTION PROTOTYPES
void enterFactoryNames(string*);
float* makeArray(int);
void enterCOData(float*, int);
void enterNO2Data(float*, int);
void enterO3Data(float*, int);
void printOverLimit(string*, float**, int, float);
void getLargest(string *, float**, int, float&, string&, int&);

#endif