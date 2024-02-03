/*
*   Title: lab9_c.cpp
*   Author: Noah Gregory
*   Date: 11/3/21
*   Purpose: To calculate the area of a rectangle using pointers
*/

#include <iostream>
using namespace std;

int main(){
    int length, width, area;
    int* lengthPtr;
    int* widthPtr;

    lengthPtr = &length;
    widthPtr = &width;

    cout << "Enter the length: " << endl;
    cin >> *lengthPtr;

    cout << endl << "Enter the width: " << endl;
    cin >> *widthPtr;

    area = *lengthPtr * *widthPtr;

    cout << "The area is " << area << "." << endl;

    if(*lengthPtr < *widthPtr){
        cout << "The width is greater than the length." << endl;
    }else if(*lengthPtr > *widthPtr){
        cout << "The length is greater than the width." << endl;
    }else{
        cout << "The length and width are the same." << endl;
    }

    return 0;
}