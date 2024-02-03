/*
*   Title: lab7.cpp
*   Author: Noah Gregory
*   Date: 10/18
*   Purpose: to calculate the area of various shapes
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//Global Variables
const double PI = 3.14159;
double height, width, length, area;

int displayMenu(){

    int choice;
    int x;

    cout << endl << "Please choose an a shape to calculate area:" << endl << setw(5) << right << " " << "1. Tapezoid" << endl << setw(5) << right << " " << "2. Cone" << endl;
    cout << setw(5) << right << " " << "3. Parallelogram" << endl << setw(5) << right << " " << "4. Circle" << endl << setw(5) << right << " " << "5. End program" << endl;
    cout << "Choose 1 - 5:  ";

    do{

        if(x > 0){
            cout << "Invalid Input, try again" << endl << endl;
        }
        cin >> choice;
        x++;
    }while(choice < 1 || choice > 5);

    return choice;
}

double areaTrapezoid(double &height, double &width, double &length){
    cout << endl << "Enter the height of the trapezoid:";
    cin >> height;
    cout << endl << "Enter the length of side 'a': ";
    cin >> width;
    cout << endl << "Enter the length of side 'b': ";
    cin >> length;
    return (0.5 * (length + width) * height);
}

double areaCone(double &height, double &r){
    cout << "Enter the height of your cone:  " << endl;
    cin >> height;
    cout << "Enter the radius of your cone:  " << endl;
    cin >> r;
    return (PI * r * (r + sqrt( pow(height, 2) + pow(r, 2) ) ) );
}

double areaParallelogram(double &base, double &height){
    cout << "Enter the height of your parellogram:  " << endl;
    cin >> height;
    cout << "Enter the base of your parellogram:  " << endl;
    cin >> base;
    return (base * height);
}

double areaCircle(double &radius){
    cout << "Enter the radius of your circle: " << endl;
    cin >> radius;
    return (PI * (radius * radius));
}

int main(){

    ofstream outfile;
    int userChoice;
    

    outfile.open("result.txt");

    if(!outfile.is_open()){

        cout << "Could not open file" << endl;

        return 1;
    }


        do{

        userChoice = displayMenu();

        switch(userChoice){
            case 1:
                area = areaTrapezoid(height, width, length);
                cout << endl << "The area of your trapezoid with a height of " << height << ", and bases of " << width << " and " << length << " is " << area  << "."<< endl;
                outfile << "The area of your trapezoid with a height of " << height << ", and bases of " << width << " and " << length << " is " << area  << "."<< endl;
                break;

            case 2:
                area = areaCone(height, width);
                cout << endl << "The surface area of your cone with a height of " << height << " and a radius of " << width << " is " << area << "." << endl;
                outfile << "The surface area of your cone with a height of " << height << " and a radius of " << width << " is " << area << "." << endl;
                break;

            case 3:
                area = areaParallelogram(width, height);
                cout << endl << "The area of your parellogram with a height of " << height << " and a base of " << width << " is " << area << "." << endl;
                outfile << "The area of your parellogram with a height of " << height << " and a base of " << width << " is " << area << "." << endl;
                break;

            case 4:
                area = areaCircle(height);
                cout << endl << "The area of your circle with a radius of " << height << " is " << area << "." << endl;
                outfile << "The area of your circle with a radius of " << height << " is " << area << "." << endl;
                break;
        }
        


    }while(userChoice != 5);

    cout << "Closing file";
    outfile.close();

    return 0;
}