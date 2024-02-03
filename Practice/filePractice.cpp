#include <iostream>
#include <fstream>
using namespace std;


int main(){

    ifstream infile; // variable infile of data type ifstream
    infile.open("anotherFile.txt"); // opening file anotherfile.txt

    string data, lineOfData; // strings
    infile >> data; // reading data into the file

    getiline(infile, lineOfData);

    infile.close();

    ofstream outfile;

    outfile.open("myfile.txt");

    outfile << "something";
    outfile.close();



    string filename;
    int num;
    ifstream inFS;
    cout << "What is the name of your file?";

    cin >> filename;
    file0.open(filename);

    while(!file0.eof()){

        file0 >> num;

    }

    //ios::app will put the new data at the end of the file instead of overwriting it (completely erased and put in new data)
    // ios::app will be comma spaced in the open function

    //ios::out will open the file in output mode



    


    return 0;
}