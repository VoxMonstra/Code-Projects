#include "IceCream.h"

IceCream::IceCream(string custCone, string custFlavor, string custTopping, double custPrice)
{
    cone = custCone;
    flavor = custFlavor;
    topping = custTopping;
    price = custPrice;
};

void IceCream::PrintIceCream()
{
    cout << endl << "Cone: " << this->cone;
    cout << endl << "Flavor: " << this->flavor;
    cout << endl << "Topping: " << this->topping;
    cout << endl << "Price: " << setprecision(2) << fixed << this->price;
};