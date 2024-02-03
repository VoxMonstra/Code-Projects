#include "netflix.h"
using namespace std;

int getNumStudents(){
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

int* makeArray(int num){
    int* array;
    array = new int[num];
    return array;
}

void getStudentData(int* students, int num){
    for(int i = 0; i < num; i++){
        cout << "How many hours of netflix did student " << (i + 1) << " watch?" << endl;
        *(students + i) = getNumStudents();
    }
}

double getAverage(int* students, int num){
    double average = 0;

    for(int i = 0; i < num; i++){
        average += *(students + i);
    }
    average /= num;

    return average;
}

int getMode(int* students, int num)
{
    int mode = -1, maxNum = 0, counter = 0;
    int* arr;
    arr = new int[num];
    for(int i = 0; i < num; i++)
    {
        counter = 0;
        for(int j = 0; j < num; j++)
        {
            if(*(students + i) == *(students + j))
            {
                counter++;
            }
        }

        *(arr + i) = counter;
    
    }
    for(int i = 0; i < num; i++)
    {
        if(*(arr + i) > maxNum)
        {
            maxNum = *(arr + i);
        }
    }
    if(maxNum > 1)
    {
        for(int i = 0; i < num ; i++)
        {
            if(*(arr + i) == maxNum)
            {
                mode = *(students + i);
                break;
            }
        }   
    }
    for(int i = 0; i < num; i++)
    {
        cout << *(arr + i);
    }
    delete [] arr;
    return mode;
}

void sortArray(int* students, int num){

    int temp = 0;

    for(int i = 0; i < (num - 1); i++){
        if(*(students + i) > *(students + i + 1)){
            temp = *(students + i);
            *(students + i) = *(students + i + 1);
            *(students + i + 1) = temp;
            i = -1;
        }
    }
}

void printArray(int* students, int num){
    cout << endl << "Hours each student watched Netflix in ascending order: ";
    for(int i = 0; i < num; i++)
    {
        cout << *(students + i) << " ";
    }
    cout << endl;
}

double getMedian(int* students, int num){
    double median = 0;

    if(num % 2 == 0)
    {
        median = ((*(students + (num / 2) - 1) + *(students + (num / 2)) ) / 2);
    }
    else
    {
        median = *(students + (num / 2));
    }

    return median;
}