#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream inFS;
    int num1, num2, num3, num4, num5;


    cout << endl << "Opening text file" << endl;
    inFS.open("integers.txt.txt");

    if(!inFS.is_open()){
        cout << endl << "Could not open file." << endl;
        return 1;
    }

    cout << endl << "Reading in integers." << endl;
    inFS >> num1 >> num2 >> num3 >> num4 >> num5;
    cout << endl << "Closing file" << endl;
    inFS.close();

    cout << endl << "Integers:" << endl << endl << num1 << endl << num2 << endl << num3 << endl << num4 << endl << num5;


    return 0;
}