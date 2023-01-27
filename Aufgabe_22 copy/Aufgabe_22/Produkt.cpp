//
//  Produkt.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 06.01.23.
//

#include "Produkt.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
//enum class Farbe {Rot=1, Blau, Grün, Gelb, Schwarz, Lila, Rosa, Braun };
//constructors
int Produkt::produktIDCounter = 1001;
Produkt::Produkt():kProduktID(produktIDCounter++){}
Produkt::Produkt(std::string pProduktName, double pPreis)
:produktName(pProduktName), produktPreis(pPreis),kProduktID(produktIDCounter++){}

Produkt::Produkt(const Produkt& pProdukt)
:produktName(pProdukt.produktName), produktPreis(pProdukt.produktPreis){
  ;}//Kopierkonstruktor

//Konstruktor
Produkt::~Produkt(){produktIDCounter--;}
//getters
std::string Produkt::getProduktName(){return produktName; }
int Produkt::getProduktID(){return kProduktID;}
double Produkt::getProduktPreis(){return produktPreis;}

//setters
void Produkt::setProduktName(std::string pProduktName){pProduktName = pProduktName;}
void Produkt::setProduktPreis(double pProduktPreis){produktPreis = pProduktPreis; }

//methods
//method to check if product color is available
bool Produkt::checkColorAvailability(int pColor){
    bool isColorAvailable = false;
    switch (pColor) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            isColorAvailable = true;
            break;
        default:
            break;
    }
    return isColorAvailable;
}
//method to check if product size is available
bool Produkt::checkSizeAvailability(int pGroesse){
    bool isSizeAvailabble = false;
    switch (pGroesse) {
        case 32:
        case 34:
            isSizeAvailabble = true;
            break;
        default:
            break;
    }
    return isSizeAvailabble;
}

void Produkt::showProduktDetails(){
    printf("\nProduct ID: %d", kProduktID);
    std::cout << "\nProduct Name: " << produktName;
    printf("\nProduct Preis:%.2f euro", produktPreis);
}
