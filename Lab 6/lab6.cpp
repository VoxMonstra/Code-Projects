/*
*   Title: lab6.cpp
*   Author: Noah Gregory
*   Date: 10/4
*   Purpose: to calculate the area of various shapes
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
const double PI = 3.14159;

void displayMenu(){
    cout << endl << "Please choose an a shape to calculate area:" << endl << setw(5) << right << " " << "1. Square" << endl << setw(5) << right << " " << "2. Rectangle" << endl;
    cout << setw(5) << right << " " << "3. Parallelogram" << endl << setw(5) << right << " " << "4. Circle" << endl << setw(5) << right << " " << "5. End program" << endl;
    cout << "Choose 1 - 5:  ";
}

double areaSquare(double side){
    return (side * side);
}

double areaRectangle(double sideA, double sideB){
    return (sideA * sideB);

}

double areaParallelogram(double base, double height){
    return (base * height);
}

double areaCircle(double radius){
    return (PI * (radius * radius));
}

int main(){

    int userChoice;
    double height, width, area;
    string userInput;

    do{

        displayMenu();
        cin >> userChoice;

        for(int i = 0; i < 1;){
            if(userChoice > 0 && userChoice < 6){
                i++;      
            }else{
                cout << endl << "Invalid input, try again:";
                cin >> userChoice;
            }
        }

        switch(userChoice){
            case 1:
                cout << endl << "Enter the height of the square:";
                cin >> height;
                area = areaSquare(height);
                cout << endl << "The area of your square is " << area << endl;
                break;

            case 2:
                cout << "Enter the height of your rectangle:  " << endl;
                cin >> height;
                cout << "Enter the width of your rectangle:  " << endl;
                cin >> width;
                area = areaRectangle(height, width);
                cout << endl << "The area of your rectangle is " << area << endl;
            break;

            case 3:
                cout << "Enter the height of your parellogram:  " << endl;
                cin >> height;
                cout << "Enter the base of your parellogram:  " << endl;
                cin >> width;
                area = areaParallelogram(width, height);
                cout << endl << "The area of your parellogram is " << area << endl;
             break;

            case 4:
                cout << "Enter the radius of your circle: " << endl;
                cin >> height;
                area = areaCircle(height);
                cout << endl << "The area of your circle is " << area << endl;
            break;
        }
        


    }while(userChoice != 5);

    return 0;
}