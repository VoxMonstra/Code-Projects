/*
	Title:  	Lab4b.cpp
	Author:		Noah Gregory
	Date:		9/20/21
	Purpose:	learning switch statements
*/

#include <iostream>
using namespace std;

int main()
{
	char grade;

	cout << "What grade did you earn in Programming I ?" << endl;
	cin >> grade;


    switch(grade){

	case 'A':
		cout << "An A - excellent work !" << endl;
        break;

	case 'B':
		cout << "You got a B - good job" << endl;
        break;

	case 'C':
		cout << "Earning a C is satisfactory" << endl;
        break;

	case 'D':
		cout << "While  D is passing, there is a problem" << endl;
        break;

	case 'F':
		cout << "You failed - better luck next time" << endl;
        break;

	default:
		cout << "You did not enter an A, B, C, D, or F" << endl;

    }    

    return 0;
}