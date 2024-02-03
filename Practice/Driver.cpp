#include "IceCream.h"

int main()
{
    int numIceCream;
    IceCream** iceCreams;
    string inputCone, inputFlavor, inputTopping;
    double custPrice;

    cout << endl << "How many ice creams would you like?" << endl;
    cin >> numIceCream;
    cin.ignore();

    iceCreams = new IceCream*[numIceCream];

    for(int i = 0; i < numIceCream; i++)
    {
        cout << endl << endl << endl << "Enter data for ice cream " << i + 1 << ":" << endl;

        cout << endl << setw(20) << left << "Type of cone:";
        getline(cin, inputCone);
        cout << endl << setw(20) << left << "What flavor:";
        getline(cin, inputFlavor);

        cout << endl << setw(20) << left << "What topping:";
        getline(cin, inputTopping);

        cout << endl << setw(20) << left << "Price:";
        cin >> custPrice;
        cin.ignore();

        iceCreams[i] = new IceCream(inputCone, inputFlavor, inputTopping, custPrice);
    }

    cout << endl << endl << endl << endl;
    cout << "YOUR ICE CREAM ORDER:" << endl;

    for(int i = 0; i < numIceCream; i++)
    {
        cout << "Ice Cream number " << i + 1 << endl;
        iceCreams[i]->PrintIceCream();

    }

    delete [] iceCreams;

    return 0 ;
}