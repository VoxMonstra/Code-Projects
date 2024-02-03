#include "dinosaurs.h"

void printArt()
{

cout << endl << endl;
cout << "########  #### ##    ##  #######     ######## ####  ######   ##     ## ######## ####\n";
cout << "##     ##  ##  ###   ## ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n";
cout << "##     ##  ##  ####  ## ##     ##    ##        ##  ##        ##     ##    ##    ####\n";
cout << "##     ##  ##  ## ## ## ##     ##    ######    ##  ##   #### #########    ##     ##\n";
cout << "##     ##  ##  ##  #### ##     ##    ##        ##  ##    ##  ##     ##    ##\n";
cout << "##     ##  ##  ##   ### ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n";
cout << "########  #### ##    ##  #######     ##       ####  ######   ##     ##    ##    ####\n";

cout << endl;

}  

int getValidateInput(int lowerBound, int upperBound, string prompt)
{
    int input;
    bool condition = false;

    cout << prompt << endl;

    cin >> input;
    cout << endl;

    while(!cin || input > upperBound || input < lowerBound){
        if(!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter an integer" << endl;

        }
        else 
        {
            cout << "Not in valid range" << endl;
        }

        cout << prompt << endl;
        cin >> input;
    }
    cin.ignore();
    return input;
    

}

int displayMenu()
{
    int choice = 0;
    string prompt = "Choose 1, 2, 3, or 4:";
    cout << endl << "What would you like to do?" << endl << "1. Enter dinosaurs" << endl << "2. Print dinosaurs" << endl << "3. FIGHT!" << endl << "4. End Program" << endl;
    
    choice = getValidateInput(1, 4, prompt);

    return choice;
}

int preloadDinos(int capacity, Dino* dinos)
{
    string file, value;
    int num0, num1 = capacity;
    ifstream infile;
    int length;
    string list[capacity];

    infile.open("dinosaur_list.txt");
    cout << endl << "Opening file" << endl;

    if(!infile.is_open())
    {
        cout << endl << "Could not open file";
        return -5;
    }
    
    getline(infile, file);


    for(int i = 0; i < capacity;  i++)
    {
        if(file.length() == 0)
        {
            num1 = i;
            break;
        }

        value = file.substr(0, file.find('#'));
        dinos[i].type = value;
        file = file.substr(file.find('#') + 1);

        value = file.substr(0, file.find('#'));
        dinos[i].name = value;
        file = file.substr(file.find('#') + 1);

        value = file.substr(0, file.find('#'));
        num0 = stoi(value);
        dinos[i].dinoStats.ap = num0;
        file = file.substr(file.find('#') + 1);

        value = file.substr(0, file.find('#'));
        num0 = stoi(value);
        dinos[i].dinoStats.hp = num0;
        file = file.substr(file.find('#') + 1);

    }

    cout << endl << "There were " << num1 << " dinosaurs loaded into the arena" << endl;

    infile.close();
    return num1;
}

void enterDinos(int capacity, int& current, Dino* dinos)
{

    string file;
    char choice;
    int key = 0;

    do
    {
        key = 0;
        if(current == capacity)
        {
            cout << endl << "Sorry! The fight arena can only hold " << capacity << " dinosaurs or less." << endl;
            cout << endl << "You cannot add more." << endl;
            return;
        }

        cout << endl << "Enter dinosaur information:" << endl << "Dinosaur type:\t";
        getline(cin, dinos[current].type);

        cout << endl << "Dinosaur name:\t";
        getline(cin, dinos[current].name);

        cout << endl;
        dinos[current].dinoStats.ap = getValidateInput(0, numeric_limits<int>::max(), "Attack Points:\t");

        cout << endl;
        dinos[current].dinoStats.hp = getValidateInput(0, numeric_limits<int>::max(), "Health Points:\t");

        current++;

        cout << "Do you want to enter another dinosaur? (y or n)";
        do
        {
            if(key > 0)
            {
                cout << endl << "Invalid input, try again:" << endl;
            }
            cin >> choice;
            key++;
        }
        while(!(choice == 'y' || choice == 'n'));
        cin.ignore();
    }
    while(choice = 'y');

}

void printDinos(int current, Dino* dinos)
{
    string horizontalLine(80, '-'), shortLine(30, '-');
    for(int i = 0; i < current; i++)
    {
        cout << endl << endl << horizontalLine << endl << shortLine << "Dinosaur Fighter " << i + 1 << endl;
        cout << setw(15) << left << "NAME:  " << dinos[i].name << endl;
        cout << setw(15) << left << "TYPE:  " << dinos[i].type << endl;
        cout << setw(15) << left << "HIT POINTS:  " << dinos[i].dinoStats.ap << endl;
        cout << setw(15)  << left << "HEALTH POINTS:  " << dinos[i].dinoStats.hp << endl;
        cout << endl << endl;

    }
    cout << horizontalLine << endl << endl;
}

void fight(int& current, Dino* dinos)
{
    int dino1, dino2, ap1, ap2, hp1, hp2, key = 0, roundNum = 1;
    int num1, num2;
    string prompt;
    srand(time(0));

    if(current < 2)
    {
        cout << endl << "Oops! You need at least two dinosaurs to fight!" << endl;
        return;
    }
    
    cout << endl << "Which two dinosaurs do you want to fight?" << endl;

    for(int i = 0; i < current; i++)
    {
        cout << i + 1 << ". " << dinos[i].name << endl;
    }

    prompt = "Enter the first dinosaur (enter 1 - " + to_string(current) + "):";
    dino1 = getValidateInput(1, current, prompt);

    prompt = "Enter the second dinosaur (enter 1 - " + to_string(current) + "):";

    do{
        if(key > 0)
        {
            cout << endl << "Invlid input, enter a different dino than the first dino:" << endl;
        }

        dino2 = getValidateInput(1, current, prompt);
        key++;

    }
    while(dino2 == dino1);

    dino1--;
    dino2--;

    cout << endl << endl << dinos[dino1].name << " is fighting " << dinos[dino2].name << "!" << endl;

    //FIGHT STARTS!!
    ap1 = dinos[dino1].dinoStats.ap;
    ap2 = dinos[dino2].dinoStats.ap;

    hp1 = dinos[dino1].dinoStats.hp;
    hp2 = dinos[dino2].dinoStats.hp;

    roundNum = 1;

    do{
        cout << endl << "*************** ROUND" + to_string(roundNum) + "****************" << endl;
        num1 = (rand() % 2) + 1;
        num2 = (rand() % 10) + 1;
        if(num1 == 1)
        {
            cout << dinos[dino1].name << " hit " << dinos[dino2].name << " with " << (ap1 / num2) << " hit points." << endl;
            hp2 -= (ap1 / num2);
            cout << dinos[dino2].name << " is left with " << hp2 << " health points.";
            dinos[dino2].dinoStats.hp = hp2;


            if(hp2 <= 0)
            {
                cout << endl << dinos[dino2].name << " had died." << endl << dinos[dino2].name << " has been creamated." << endl;
                deleteDino(current, dino2, dinos);
                current--;
                return;
            }
        }
        if(num1 == 2)
        {
            cout << dinos[dino2].name << " hit " << dinos[dino1].name << " with " << (ap2 / num2) << " hit points." << endl;
            hp1 -= (ap2 / num2);
            cout << dinos[dino1].name << " is left with " << hp1 << " health points.";
            dinos[dino1].dinoStats.hp = hp1;

            if(hp1 <= 0)
            {
                cout << endl << dinos[dino1].name << " has died." << endl << dinos[dino1].name << " has been creamated." << endl;
                deleteDino(current, dino1, dinos);
                current--;
                return;
            }
        }
        roundNum++;
        cout << endl << endl;
    }
    while(roundNum <= 3);

}

void deleteDino(int current, int dino, Dino* dinos)
{
    for(int i = dino; i < current - 1; i++)
    {
        dinos[i].name = dinos[i + 1].name;
        dinos[i].type = dinos[i + 1].type;
        dinos[i].dinoStats.ap = dinos[i + 1].dinoStats.ap;
        dinos[i].dinoStats.hp = dinos[i + 1].dinoStats.hp;
    }
}

void saveToFile(int current, Dino* dinos)
{
    ofstream outfile;
    string file = "";
    string value;

    for(int i = 0; i < current; i++)
    {
        value = dinos[i].type;
        file += value;
        file += "#";
        value = dinos[i].name;
        file += value;
        file += "#";
        value = to_string(dinos[i].dinoStats.ap);
        file += value;
        file += "#";
        value = to_string(dinos[i].dinoStats.hp);
        file += value;
        file += "#";
    }

    outfile.open("dinosaur_list.txt");
    outfile << file;
    outfile.close();

}