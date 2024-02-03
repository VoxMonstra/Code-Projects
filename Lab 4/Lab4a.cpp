/*
	Title:  	lab4a.cpp
	Author:  	Noah Gregory
	Date:       9/20/21
	Purpose:	This program illustrates the use of logical operators
*/

#include <iostream>
using namespace std;

int main()
{
   char year;
   float gpa;

   cout << "What year student are you ?\n";
   cout << "Enter 1 (freshman), 2 (sophomore), 3 (junior), or 4 (senior)\n\n";
   cin >> year;

   cout << "Now enter your GPA\n";
   cin >> gpa;

   if(year == '1' && gpa < 2.0){

       cout << endl << endl << "You need to visit your freshman advisor and seek tutoring to improve your gpa.";

   }
   else if(year == '4' && gpa >=2.0){

       cout<< endl << endl << "It is time to graduate soon.";

   }
   else{

       cout << endl << endl << "You need more schooling.";

   }

   return 0;
}