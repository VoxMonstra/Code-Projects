/*
*   Title: lab5a.cpp
*   Author: Noah Gregory
*   Date: 9/27
*   Purpose: to generate a nickname for the user using random number generation and user selection
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //seeding random numbers
    srand(time(0));

    //declaring variables
    int userNum = 0, x = 0, num;
    char char1, char2, char3, char4;
    string name;

    while(userNum < 65 || userNum > 90){

        if(x != 0){
            cout << endl << endl << "Invalid number, try again.";
        }

        cout << endl << endl << "Please choose a number between 65 and 90 inclusively.";
        x++;
        cin >> userNum;

    }
    char1 = static_cast<char>(userNum); // assigning char1 a letter based on userNum

    num = (rand() % (5)) + 1;

    switch(num){// assigning char2 a vowel based on random number
        case 1:
            char2 = 'a';
            break;
        
        case 2:
            char2 = 'e';
            break;
        
        case 3:
            char2 = 'i';
            break;

        case 4:
            char2 = 'o';
            break;

        case 5:
            char2 = 'u';
            break;
    }

    num = (rand() % (122 - (97 + 1)) + 97);

    char3 = static_cast<char>(num); // assigning char3 a letter based on random number

    char4 = 'y';

    // creating nickname by appending characters
    name.push_back(char1);
    name.push_back(char2);
    name.push_back(char3);
    name.push_back(char4);

    cout << "Your nickname is " << name << "!";


    return 0;
}