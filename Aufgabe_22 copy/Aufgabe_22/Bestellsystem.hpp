//
//  Bestellsystem.hpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 12.01.23.
//

#ifndef Bestellsystem_hpp
#define Bestellsystem_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Kunde.hpp"
#include "Bestellung.hpp"
#include "Shop.hpp"

class Bestellsystem{
    private:
        std::vector<Kunde*> * engeschriebenKunden;
        std::vector<Bestellung*>* bestellungsSummary;
        Shop * shop;
        Kunde * currentLoggedINKunde;
public:
    Bestellsystem();
    void kundeRegistrieren();
    void kundeAnmelden(int kundeNr);
    void showOrderSummary();
    void placeOrder();
    void deleteOrderedProdukt(int pProduktNr);
    void placeOrder(int produktNr);
    Kunde* getEingeschriebeneKunden(int pKundenNr);
    void showAllRegisteredKunden();
    void showShop()const;
    Shop* getShop();
    Kunde * getCurrentLoggedInKunde();
    void setKundenBestellung(Bestellung* pBestellung);
    void bezahlen(int bestellungsNummer);
   
    //process payment
};


#endif /* Bestellsystem_hpp */
