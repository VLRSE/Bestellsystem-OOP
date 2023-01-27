//
//  Kunde.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 08.01.23.
//

#include "Kunde.hpp"
#include "Produkt.hpp"
int Kunde::kundenCount = 1;
//Konstrukturen
Kunde::Kunde():kundenID(kundenCount++){bestellung = new Bestellung();}
Kunde::Kunde(std::string pVorname, std::string pNachname, Adresse *pAdresse,
             std::string emailAdresse,int pContactNr )
:kundenID(kundenCount++),vorname(pVorname),nachname(pNachname),
emailAdresse(emailAdresse), contactNr(pContactNr),adresse(pAdresse) {bestellung = new Bestellung();}

//Dstruktur
Kunde::~Kunde(){kundenCount--;
    delete bestellung;
}
//getters
int Kunde::getKundenID()const{return kundenID;}
std::string Kunde::getVorname()const{return vorname;}
std::string Kunde::getNachname()const{return nachname;}
Adresse* Kunde::getAdresse()const{return adresse;}
std::string Kunde::getEmailAdresse()const{return emailAdresse;}
int Kunde::getContactNr()const{return contactNr;}
double Kunde::getCredit() {return credit;}
Bestellung* Kunde::getBestellung()const{
    return bestellung;
    
}
//Setters
void Kunde::setVorname(std::string pName){vorname = pName;}
void Kunde::setNachname(std::string pNachname){nachname = pNachname;}
void Kunde::setAdresse(Adresse* pAdresse ){adresse = pAdresse;}
void Kunde::setEmailAdresse(std::string pEmailAdresse){ emailAdresse = pEmailAdresse;}
void Kunde::setContactNr(int pContactNr){contactNr = pContactNr;}
void Kunde::setCredit(double pCredit){credit = pCredit;}
void Kunde::showKundeDetails(){
    std::cout<< "\nKunde ID: " << kundenID << std::endl;
    std::cout<< "Kunde Vorname: " << vorname << std::endl;
    std::cout<< "Kunde Nachname: " << nachname<< "\n" << std::endl;
}
void Kunde::changeAnmeldungStatus(bool pIstKundeAngemeldet){
    isKundeAngemeldet = pIstKundeAngemeldet;
}
void Kunde::setBestellung(Bestellung * bestellung){
    bestellung = bestellung;
}
void Kunde::showAddress()const{
    std::cout<< "\nAdresse: " << std::endl;
    std::cout<< adresse->getStrasse()<<" "<<adresse->getHausNr() << std::endl;
    std::cout<< adresse->getpostleitzahl()<<" "<<adresse->getStadt() << std::endl;
    std::cout<< adresse->getLand()<< std::endl;
  
}
