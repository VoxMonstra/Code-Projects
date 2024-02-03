#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <iomanip>
using namespace std;

class IceCream {
    public:
    
        IceCream()
        {
            cone = "NoCone";
            flavor = "NoFlavor";
            topping = "NoTopping";
            price = 0.0;
        };

        IceCream(string, string, string, double);
        
        void SetCone(string custCone){ cone = custCone; }

        void SetFlavor(string custFlavor){ flavor = custFlavor; }

        void SetTopping(string custTopping){ topping = custTopping; }

        void SetPrice(double custPrice) { price = custPrice; }

        string GetCone() const{ return cone; }

        string GetFlavor() const{ return flavor; }

        string GetTopping() const { return topping; }

        double GetPrice() const { return price; }

        void PrintIceCream();


    private:
        string cone;
        string flavor;
        string topping;
        double price;

};

#endif