/**************************************************************************************************************************************************************
*                                                                                                                                                             *
*   Title: program2.cpp                                                                                                                                       *
*   Author: Noah Gregory                                                                                                                                      *
*   Date: 9/13/21                                                                                                                                             *
*   Purpose: To take information about one credit card from the user and calculate how long it will take to pay the card                                      *
*                                                                                                                                                             *
*   IMPORTANT FORMULAS :                                                                                                                                      *
*                                                                                                                                                             *
*   Periodic Rate = APR / 365 * 0.01                                                                                                                           *
*   Average Days In a Month = 30.42                                                                                                                           *
*   Monthly Interest Fee = Credit Card Balance * Periodic Rate * Average Days In a Month                                                                      *
*   Monthly Balance = Previous Monthly Balance + Monthly Interest Fee - Payment                                                                               *
*                                                                                                                                                             * 
**************************************************************************************************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

     //Declaring variables
    string card_name;
    double current_balance, prev_current_balance, annual_rate, minimum_payment, interest, principle, current_balance_orig, minimum_payment_orig;   //"orig" (original) are placeholders for the original values for later output
    double periodic_rate, cumul_int = 0;
    int month_num = 1;

    //gathering input
    cout << endl << endl << "Enter the name of your card:";
    getline(cin, card_name);

    cout << endl << "Current balance on your " << card_name << " card:  $"; //can write whatever you want poop
    cin >> current_balance;
    current_balance_orig = current_balance;

    cout << endl << "Annual Percentage Rate (APR) on your " << card_name << " card:  ";
    cin >> annual_rate;

    cout << endl << "Monthly minimum payment on your " << card_name << " card:  $";
    cin >> minimum_payment;
    minimum_payment_orig = minimum_payment;

    cout << "Credit card debt analysis for your " << card_name << " card:" << endl << endl;
    cout << setw(22) << right << "Payment" << setw(15) << right << "Interest" << setw(15) << "Principal" << setw(15) << "Balance" << endl;
    cout << setw(66) << right << "$" << current_balance << endl;

    periodic_rate = (annual_rate / 365) * 0.01;

    do{

        //iterating the next column of statistics
        interest = current_balance * periodic_rate * 30.42;
        cumul_int += interest;//cumulative interest
        principle = minimum_payment - interest;
        prev_current_balance = current_balance;// stroig the previous balance
        current_balance = (current_balance + interest) - minimum_payment;

        //if statement for when the balance is paid off, it is to make sure that the user doesnt over pay
        if(current_balance < 0){
            current_balance = 0;
            minimum_payment = prev_current_balance + interest;
            principle = minimum_payment - interest;

        }

        //output
        cout << "Month   " << setw(5) << right << month_num << ":" << setw(5) << right <<  "$" << setw(15) << left << setprecision(2) << fixed << minimum_payment;
        cout << "$" << setw(13) << setprecision(2) << fixed << interest << "$" << setw(16) << left << setprecision(2) << fixed << principle;

        //if the card will never be paid off
        if(principle <= 0){

            cout << endl << endl << "Credit card balance will continually get larger and never be paid off." << endl << "You will need to make a payment higher than your minimum payment of $";
            cout << minimum_payment_orig << " in order to pay off your credit card.";

            return 0;// program ends if it reaches here
        }

        cout << "$" << setw(13) << left << current_balance << endl;
        month_num++;

    } while(current_balance > 0);

    month_num--;//month num increments an extra time after the debt has been paid, so i decremented it here

    //debrief output
    cout << endl << endl << "With your current monthly payment of $" << minimum_payment_orig << " for your " << card_name << " card, you will pay it off in " << month_num << " months.";
    cout << endl << endl << "You also would have paid $" << cumul_int << " in interest payments."; 
    
    return 0;
}
