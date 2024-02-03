#include <iostream>
using namespace std;

struct Song
{
    string name;
    string artist;
    double length;
};

int main()
{

    Song input;

    cout << "Enter the name of the song:" << endl;
    getline(cin, input.name);

    cout << endl << "Enter the name of the artist:" << endl;
    getline(cin, input.artist);

    cout << endl << "Enter the legnth of the song:" << endl;
    cin >> input.length;

    cout << endl << endl << endl << endl;
    cout << "Your song:" << endl;
    cout << "Name:\t" << input.name << endl;
    cout << "Author:\t" << input.artist << endl;
    cout << "Length:\t" << input.length << endl;
    return 0;
}
