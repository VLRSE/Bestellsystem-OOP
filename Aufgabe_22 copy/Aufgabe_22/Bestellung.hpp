//
//  Bestellung.hpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 12.01.23.
//

#ifndef Bestellung_hpp
#define Bestellung_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Produkt.hpp"

class Bestellung{
    private:
        int orderCount;
        std::vector<Produkt*>* produktBestellung;
        double bestellungSumme;
       
    public:
        static int orderCounter;
        //constructors
        Bestellung();
        Bestellung( std::vector<Produkt*>* pProduktBestellung);
        //destruktor
        ~Bestellung();
        //Getter and setter
        std::vector<Produkt*>* getbestellungSummary() const;
        void addBestellung(Produkt* pAdditionalBestellung);
        void removeBestellung(int pProduktId);
        void showBestellungSummary();
        double getBestellungsSumme();
};
#endif /* Bestellung_hpp */
