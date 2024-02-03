#include <iostream>
using namespace std;

int main()
{
    int students[] = {1, 2, 2, 3, 4, 4, 4};

    int *s = students;

    for(int i = 0; i < 7; i++)
        cout << s[i] << endl;

    return 0;
}