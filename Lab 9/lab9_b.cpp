/*
*   Title: lab9_b.cpp
*   Author: Noah Gregory
*   Date: 11/3/21
*   Purpose: To check to see if user inupt is valid
*/

#include <iostream>
#include <limits>
using namespace std;

int main(){

    int num;
    bool condition = false;

    cout << "Enter an number between 9 and 77 inclusive" << endl;
    

    do{
        cin >> num;

        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter an integer" << endl;

            cin >> num;
        }

    
        if(num > 77 || num < 9){
            cout << "Not in interval, try again" << endl;
        }else{
            condition = true;
        }

    }while(condition == false);

    cout << "You entered a valid number!";
    


    return 0;
}