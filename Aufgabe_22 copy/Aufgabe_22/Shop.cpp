//
//  Shop.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 13.01.23.
//

#include "Shop.hpp"
Shop::Shop(){
    this->shop = new std::vector<Produkt*>{
        new Produkt("Kleid 1", 10.00),
        new Produkt("Kleid 2", 15.00),
        new Produkt("Hose", 21.00),
    };
}
Produkt * Shop::getProdukt(int produktID) const{
    Produkt * produktPtr =NULL;
    bool productFound = false;
    int index = produktID %1000-1;
    if(index < shop->size() ){
        produktPtr = shop->at(index);
    }
    return produktPtr;
}


void Shop::showAllProducts()const{
    std::cout << "\tSHOP" << std::endl;
    for (int i = 0; i < shop->size(); i++ ) {
        std::cout <<  "Produkt ID: " << shop->at(i)->getProduktID() <<std::endl;
        std::cout <<  "Produkt Name: " << shop->at(i)->getProduktName()<< std::endl;
        std::cout <<  "Produkt Preis: " << shop->at(i)->getProduktPreis()<< " euro"<< std::endl;
        std::cout << std::endl;
    }
}
bool Shop::isProduktAvailable(int ProduktNr){
    bool isProduktAvailable = false;
    for (int i = 0; i <shop->size() && isProduktAvailable == false; i++) {
        if(ProduktNr == shop->at(i)->getProduktID() ){
            isProduktAvailable = true;
        }
    }
    return isProduktAvailable;
}
