#include <iostream>
using namespace std;

int main(){

    int cheese = 5;
    int burger = 80;

    int beef, chicken, pork;
    int cheeseburger = cheese * burger;

    int input;

    cout << endl << "" << endl;
    cout << cheese << " " << burger << " " << (cheese + burger) << endl;
    cout << "cheese + burger" << endl;
    cout << cheeseburger << endl;

    cout << endl << "Enter in the price of beef: " << endl;
    cin >> beef;

    cout << endl << "Enter in the price of chicken:" << endl;
    cin >> chicken;

    cout << endl << "Enter in the price of pork:" << endl;
    cin >> pork;

    cout << endl << "The price of beef is $" << beef << endl;
    cout << "The price of chicken is $" << chicken << endl;
    cout << "The price of pork is $" << pork << endl;
    
    return 0;
}