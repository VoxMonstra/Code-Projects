/*
*   Title: program2.cpp
*   Author: Noah Gregory
*   Date: 09/20/21
*   Purpose: To manage my halloween store
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

const double TAX = 1.0975;// constant for tax
time_t rawtime;// defining rawtime
string dash = "-----------------------------------------";// string for dashes

//function that enters sales
void enterSales(int choice){
    //declaring variables
    string department;
    char cont;
    int qty;
    double sale;

    //choosing department to enter sale in
    if(choice == 1){
        department = "Candy";
    }else if(choice == 2){
        department = "Costumes";
    }else if(choice == 3){
        department = "Decorations";
    }

    //gathering user inout for sale
    cout << endl << "Enter the sale amount: " << endl;
    cin >> sale;
    cout << endl << "How many did they buy: " ;
    cin >> qty;
    sale *= qty;
    sale *= TAX;// adding tax

    ofstream outfile;

    cout << endl << "Opening file";
    outfile.open("sales.txt", ios::app);// opening file

    if(!outfile.is_open()){
        cout << endl << "Could not open file" << endl;
    }else if(outfile.is_open()){
        cout << endl << "Success";
    }

    outfile << department << "\n" << sale << "\n"; // printing the input to the text file

    outfile.close();// closing file

    //asking for repeat (cont = continue)
    cout << endl << "Do you want to enter more sales? (y or n) "; 
    cin >> cont;
    for(int i = 0; i < 1;){
        if(cont == 'y' || cont == 'n'){
            i++;
        }
        else{
            cout << endl << "Invalid input, try again:";
            cin >> cont;
        }
    }

    //displaying menu if continued
    if(cont == 'y'){
        cout << endl << "Choose the department from the following menu:" << endl << "1.   Candy" << endl << "2.   Costumes" << endl << "3.   Decorations" << endl;
        cin >> choice;

        for(int i = 0; i < 1;){
            if(choice > 0 && choice < 4){
                i++;
            }
            else{
                cout << endl << "Invalid input, try again:";
                cin >> choice;
            }
        }
        enterSales(choice); //recusion of entersales
    }
    cout << endl << endl << dash << endl;
}

//function that lets you view current sales
void totalSales(){

    //declaring variables
    double price, candy = 0, costumes = 0, decor = 0;
    string item;
    time(&rawtime);

    //eof runs an extra time, reading in unwanted data. logic keys will eliminate unwanted data
    bool candyKey = false, costumeKey = false, decorKey = false, fileError = false;

    //printing time
    cout << endl << endl << "TOTAL SALES ON " << ctime(&rawtime) << endl << endl << dash << endl;

    ifstream infile;
    
    infile.open("sales.txt");

    if(!infile.is_open()){
        cout << endl << endl << "Error opening file" << endl;
        fileError = true;
    }

    while(!infile.eof() && fileError == false){

        candyKey = false;
        costumeKey = false;
        decorKey = false;

        infile >> item >> price;

        if(item == "Candy"){
            candy += price;
            candyKey = true;
        }
        else if(item == "Costumes"){
            costumes += price;
            costumeKey = true;
        }
        else if(item == "Decorations"){
            decor += price;
            decorKey = true;
        }
    }

    if(candyKey){
        candy -= price;
    }
    else if(costumeKey){
        costumes -= price;
    }
    else if(decorKey){
        decor -= price;
    }

    cout << endl << setw(15) << right << "Candy:   $" << setprecision(2) << fixed << candy << endl << setw(15) << right << "Costumes:   $" << setprecision(2) << fixed;
    cout << costumes << endl << setw(15) << right << "Decorations:   $" << setprecision(2) << fixed << decor << endl << endl << dash << endl;

    infile.close();
}

//function that deletes sales
void deleteSales(){
    cout << endl << endl << dash << endl << endl << "Deleting file" << endl;
    if(remove("sales.txt") != 0){
        cout << endl << "Error deleting file" << endl << endl << dash << endl;
    }
    else{
        cout << endl << "File deleted" << endl << endl << dash << endl;
    }
}

int main(){

    //Declaring variables
    
    int userChoice;
    char choice;

    cout << endl << dash;
    cout << endl << endl << "Gregory's Ghoulish Goodies Managment Program" << endl << "PLease select from the following items: " << endl;

    do{
        cout << "1.   Enter Sales" << endl << "2.   Total Sales for the day" << endl << "3.   Delete sales for the day" << endl << "4.   End program" << endl;
        cin >> userChoice;
        for(int i = 0; i == 0;){
            if(userChoice > 0 && userChoice < 5){
                i++;
            }
            else{
                cout << endl << "Invalid choice, try again:";
                cin >> userChoice;
            }
        }

        switch(userChoice){
            case 1:
                cout << endl << dash << endl << "Choose the department from the following menu:" << endl << "1.   Candy" << endl << "2.   Costumes" << endl << "3.   Decorations" << endl;
                cin >> userChoice;
                for(int i = 0; i == 0;){
                    if(userChoice > 0 && userChoice < 4){
                        i++;
                    }
                    else{
                        cout << endl << "Invalid choice, try again:";
                        cin >> userChoice;
                    }
                }

                enterSales(userChoice);
            break;

            case 2:
                totalSales();
            break;

            case 3:
                cout << endl << "Are you sure you want to delete your sales? (y or n)" << endl;
                cin >> choice;
                for(int i = 0; i < 1;){
                    if(choice == 'y' || choice == 'n'){
                        i++;
                    }
                    else{
                        cout << endl << "Invalid input, try again";
                        cin >> choice;
                    }
                }
                if(choice == 'y'){
                    deleteSales();
                }
            break;

        }

    }
    while(userChoice != 4);

    cout << endl << "Thank you! Have a ghoulish day!";
    return 0;

}