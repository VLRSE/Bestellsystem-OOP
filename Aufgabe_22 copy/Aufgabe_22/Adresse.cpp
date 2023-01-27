//
//  Adresse.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 08.01.23.
//

#include "Adresse.hpp"
// Konstrukturen
Adresse::Adresse(){};
Adresse::Adresse( std::string pStrasse,int pHausNr, int pPostleitzahl,
        std::string pStadt, std::string pLand)
:strasse(pStrasse), hausNr(pHausNr), postleitzahl(pPostleitzahl){}
//Destrukturen
Adresse::~Adresse(){}
//Getters
std::string Adresse::getStrasse(){return strasse;}
int Adresse::getHausNr(){return hausNr;}
int Adresse::getpostleitzahl(){return postleitzahl;}
std::string Adresse::getStadt(){return stadt;}
std::string Adresse::getLand(){return land;}
//Setters
void Adresse::setStrasse() const{}
void Adresse::setHausNr()const{}
void Adresse::getpostleitzahl() const{}
void Adresse::getStadt()const{}
void Adresse::getLand()const{}
