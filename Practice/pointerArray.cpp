#include <iostream>
using namespace std;

void getData(int numPeople, string* name, int* numCoasters, int** injuriesArray)
{
    for(int i = 0; i < numPeople; i++){
        cout << endl << "How many roller coasters did " << *(name + i) << " ride?" << endl;
        cin >> *(numCoasters + i);
    }
    

    for(int i = 0; i < numPeople; i++){
        *(injuriesArray + i) = new int[*(numCoasters + i)];
    }

    for(int i = 0; i < numPeople; i++){
        for(int j = 0; j < *(numCoasters + i); j++){
            cout << endl << "How many injuries did " << *(name + i) << " have on coaster " << (j + 1) << "?" << endl;
            cin >> *(*(injuriesArray + i) + j);
        }
    }

}
int getTotal(int numPeople, int* numCoasters, int** injuriesArray){
    int total = 0;
    for(int i = 0; i < numPeople; i++){
        for(int j = 0; j < *(numCoasters + i); j++){
            total += *(*(injuriesArray + i) + j);
        }
    }
    return total;
}

int main()
{
    int numPeople, total = 0;
    int** injuriesArray;
    string* name;
    int* numCoasters;

    cout << "How many people rode roller coasters?" << endl;
    cin >> numPeople;

    numCoasters = new int[numPeople];
    name = new string[numPeople];
    injuriesArray = new int*[numPeople];

    for(int i = 0; i < numPeople; i++){
        cout << endl << "What was the name of customer " << i + 1 << endl;
        cin >> *(name + i);
    }

    getData(numPeople, name, numCoasters, injuriesArray);
    
    

    for(int i = 0; i < numPeople; i++){
        cout << endl << *(name + i) << "'s injuries: ";
        for(int j = 0; j < *(numCoasters + i); j++){
            cout << *(*(injuriesArray + i) + j) << " ";
        }
    }

    total = getTotal(numPeople, numCoasters, injuriesArray);
    cout << endl << "The total amount of injuries is " << total;

    for(int i = 0; i < numPeople; i++){
        delete [] *(injuriesArray + i);
    }

    delete [] numCoasters;
    delete [] injuriesArray;

    return 0;
}