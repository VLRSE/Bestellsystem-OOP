//
//  Shop.hpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 13.01.23.
//

#ifndef Shop_hpp
#define Shop_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Produkt.hpp"

class Shop{
    private:
        const std::vector<Produkt*>  * shop;
    public:
        Shop();
        Produkt * getProdukt(int produktID) const;
        void showAllProducts()const;
        bool isProduktAvailable(int ProduktNr);
        
};

#endif /* Shop_hpp */
