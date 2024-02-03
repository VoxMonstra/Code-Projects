/*
*   Title: lab_12.cpp
*   Author: Noah Gregory
*   Date: 11/29
*   Purpose: To gather data about esports players at ttu that are csc majors
*/
#include <iostream>
using namespace std;

struct Player
{
    string name;
    string hometown;
    int age;
    int numGames;
};

int main()
{
    int numPlayers, totalHours, maxHours, minHours;
    string maxStudName, minStudName;
    int** games;
    Player* players;

    cout << endl << "How many students at TTU major in CSC and participate in esports?" << endl;
    cin >> numPlayers;
    cin.ignore();

    players = new Player[numPlayers];
    games = new int*[numPlayers];


    for(int i = 0; i < numPlayers; i++)
    {
        totalHours = 0;

        cout << "PLAYER " << i + 1 << ":" << endl;
        cout << endl << "\tNAME:" ;
        getline(cin, players[i].name);

        cout << endl << "\tHOMETOWN:";
        getline(cin, players[i].hometown);

        cout << endl << "\tAGE: ";
        cin >> players[i].age;

        cout << endl << "\tHOW MANY GAMES DOES " << players[i].name << " PLAY: ";
        cin >> players[i].numGames;
        cin.ignore();

        *(games + i) = new int[players[i].numGames];

        for(int j = 0; j < players[i].numGames; j++)
        {
            cout << endl << "\t\tNUMBER OF HOURS " << players[i].name << " PLAYED FOR GAME " << j + 1 << ": ";
            cin >> *(*(games + i) + j);
            totalHours += *(*(games + i) + j);
        }
        cin.ignore();
        

        if(i == 0)
        {
            maxHours = totalHours;
            minHours = totalHours;
            minStudName = players[i].name;
            maxStudName = players[i].name;
            continue;
        }

        if(totalHours > maxHours)
        {
            maxHours = totalHours;
            maxStudName = players[i].name;
        }

        if(totalHours < minHours)
        {
            minHours = totalHours;
            minStudName = players[i].name;
        }
    }

    cout << endl << "The player that played the most hours (" << maxHours << " hours) is " << maxStudName << endl;
    cout << endl << "The player that played the least hours (" << minHours << " hours) is " << minStudName << endl;

    delete [] players;
    for(int i = 0; i < numPlayers; i++)
    {
        delete [] *(games + i);
    }
    delete [] games;


    return 0;
}