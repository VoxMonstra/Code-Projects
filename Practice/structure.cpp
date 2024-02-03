#include <iostream>
using namespace std;

const int LENGTH = 10;

struct Name
{
    char first[LENGTH];
    char middle[LENGTH];
    char last[LENGTH];
    char full[(LENGTH * 3) + 2];

};

struct PayRoll
{
    int empNumber;
    
};

int main()
{
    Name* nameptr;
    Name name;
    nameptr = &name;

    cout << nameptr -> first; // (*nameptr).first

    return 0;
}