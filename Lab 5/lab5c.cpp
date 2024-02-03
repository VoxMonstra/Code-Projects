/*
*   Title: lab5c.cpp
*   Author: Noah Gregory
*   Date: 9/28
*   Purpose: To find the mean of two integers given some conditions are satisfied
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    //Declaring variables
    int num1, num2;
    float total;

    cout << endl << "Please enter the beginning positive integer:   ";
    cin >> num1;
    cout << endl << "Please enter the ending positive integer :   ";
    cin >> num2;

    if(num1 < 0 || num2 < 0){
        cout << endl << "Invalid input - integers must be greater than or equal to zero";
        return 0;
    }
    if(num2 < num1){
        cout << endl << "Invalid input - ending integer must be greater than or equal to beginning integer";
        return 0;
    }
    // READ THIS 
    // the average of the conecutive integers equals the average of the first and last, so there is no need for any loops

    /*
    Mathmatical proof
    (n + j + (n + 1) + (j - 1).....(n+((j - n) / 2))) / (j - n) is equal to (n + j) / 2
    */

    total = num1 + num2;
    total /= 2;

    cout << endl << "The mean average of the consecutive positive integers from " << num1 << " to " << num2 << " is " << setprecision(2) << fixed << total;


    return 0;
}