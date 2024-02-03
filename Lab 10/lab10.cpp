#include <iostream>
#include <array>
#include <limits>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>
using namespace std;

int getNum()
{
    int num;
    bool condition = false;
    do{ // makes sure that num is an integer greater than zero

        cin >> num;

        while(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter an integer:" << endl;
            cin >> num; 
        }

        if(num < 1){
            cout << "Invalid input, please enter a number greater than 0:" << endl;
        }
        else{
            condition = true;
        }

    }while (condition == false);

    return num;
}

bool testPassword(char* password)
{
    bool upperCase = false, lowerCase = false, number = false, punct = false, space = false;
    int num = strlen(password), key = 0;
    for(int i = 0; i < num; i++)
    {
        if(isalpha(*(password + i)))
        {
            if(islower(*(password + i)))
            {
                lowerCase = true;
            }
            else if(isupper(*(password + i)))
            {
                upperCase = true;
            }
        }
        else if(isdigit(*(password + i)))
        {
            number = true;   
        }
        else if(ispunct(*(password + i)))
        {
            punct = true;
        }
        else if(isspace(*(password + i)))
        {
            space = true;
        }
    }

    if(upperCase && lowerCase && number && punct && !(space)){
        cout << "Yay!";
        return true;
    }
    else 
    {
        cout << "Oops! You didn't enter at least one";
        if(!(upperCase))
        {
            cout << " uppercase letter";
            key++;
        }
        if(!(lowerCase))
        {
            if(key != 0)
            {
                cout << ", ";
            }
            cout << " lowercase letter";
            key++;
        }
        if(!(number))
        {
            if(key != 0)
            {
                cout << ", ";
            }
            cout << " numeric digit";
            key++;
        }
        if(!(punct))
        {
            if(key != 0)
            {
                cout << ", ";
            }
            cout << " punctaution character";
            key++;
        }
        if(space){
            if(key != 0)
            {
                cout << "! ";
            }
            cout << "There also cannot be any spaces";
        }
        cout << "!" << endl << "Please try again : " << endl;
        return false;
    }
}

int main()
{
    int num, key = 0;
    char* password;
    string input;
    bool condition = false;

    cout << "How many characters should the password be? (must be at least 4) :" << endl;
    num = (getNum()) + 1;

    password = new char[num];

    cout << endl << "Enter a password with exactly " << num - 1 << " characters. " << endl << "You must have one capital letter, one lowercase letter, one digit, and one punctuation character." << endl;
    cout << "(examples: ! @ # $ % . ? )" << endl << "The password cannot contain any spaces" << endl;

    do
    {
        do{
            if(key > 0)
            {
                cout << endl << "Too many or not enough characters, try again:" << endl;
            }
            cin >> input;
            key++;
        }while(input.length() != (num -1));

        cout << endl << "Please wait, your password is being verified." << endl;
        Sleep(3000);

        if(input.length() != (num - 1)){
            cout << endl << "Invalid input, try again:" << endl;
            continue;
        }
        for(int i = 0; i < (num - 1); i++)
        {
            *(password + i) = input.at(i);
        }

        condition = testPassword(password);

    }while(condition == false);


    return 0;
}