/*
*   Title: program5.cpp
*   Author: Noah Gregory
*   Date: 11/16
*   Purpose: to simualte dinosaurs fighting each other
*/
#include "dinosaurs.h"

int main()
{
    string horizontalLine(80, '-'), prompt = "What is the maximum capacity of the dinosaur fight arena?";
    int capacity, choice, current, failKey = 0;
    Dino* dinos;
    bool end = false;


    printArt();

    cout << horizontalLine << endl << endl;

    capacity = getValidateInput(0, numeric_limits<int>::max(), prompt);
    cout << endl << horizontalLine << endl;

    dinos = new Dino[capacity]; // allocated array of dinos

    current = preloadDinos(capacity, dinos);

    if(current == -5)
    {
        return 1;
    }

    do
    {

        choice = displayMenu();

        cout << endl << horizontalLine << endl;

    
        switch(choice)
        {
            case 1:
                enterDinos(capacity, current, dinos);
                break;
        
            case 2:
                printDinos(current, dinos);
                break;
        
            case 3:
                fight(current, dinos);
                break;

            case 4:
                end = true;
                saveToFile(current, dinos);
                break;

        }

    }while(end == false);


    delete [] dinos;

    return 0;
}