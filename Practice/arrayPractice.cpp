#include <iostream>
using namespace std;

const int SIZE = 10;

int findHighest(double[]);
int findLowest(double[]);

int findHighest(double[] prices)
{
    int indexOfHighest = 0;
    double highest = prices[0];

    for(int i = 1; i < 10; i++)
    {
        if(prices[i] > highest)
        {
            indexOfHighest = i;
        }
    }
    return indexOfHighest;
}

int findLowest(double[] prices)
{
    int indexOfLowest = 0;
    double lowest = prices[0];

    for(int i = 1; i < 10; i++)
    {
        if(prices[i] < lowest)
        {
            indexOfLowestt = i;
        }
    }
    return indexOfLowest;
}

int main()
{

    char name[50];
    string items[SIZE];
    double prices[SIZE];
    int highIndex, lowIndex, average;


    cout << "\nWhat is your full name";
    cin.getline(name, 50);

    cout << endl << "Tell me 10 useful things and their price:";

    for(int i = 0; i < 10; i++)
    {
        cout << "Useful thing " << i + 1 << ": ";
        getline(cin, items[i]);

        cout << "Price for thing " << i + 1 << ": $";
        cin >> prices[i];
        cin.ignore();
    }

    highIndex = findHighest(prices);

    lowIndex = findLowest(prices);


    return 0;
}