//
//  Bestellsystem.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 12.01.23.
//

#include "Bestellsystem.hpp"
#include "Shop.hpp"
#include <stdio.h>
#include <string>
//using namespace std;
Bestellsystem::Bestellsystem(){
    engeschriebenKunden = new  std::vector<Kunde*>();
    shop = new Shop();
}
void Bestellsystem::kundeRegistrieren(){
    
    std::string pVorname, pNachname, emailAdresse;
    int pContactNr;
    
    Adresse* pAdresse;
    std::string pStrasse, pStadt,  pLand;
    int pPostleitzahl, pHausNr;
    std::cout << "Vorname: ";
    std::cin>>pVorname;
    std::cout << "Nachname: ";
    std::cin>>pNachname;
  /*  do{
        std::cout << "Email Address: ";
        std::cin>>emailAdresse;
    }while((emailAdresse.find("@") && emailAdresse.find(".com") )!= 1);
    
    do{
        std::cout << "Contact Nr.[10 Ziffer]: ";
        std::cin>>pContactNr;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Bitte nochmal eingeben: ";
            std::cout << "Contact Nr.[10 Ziffer]: ";
            std::cin>>pContactNr;
        }
    }while( std::to_string(pContactNr).size() < 10);
   
    //Adresse
    std::cout << "Strasse: ";
    std::cin>>pStrasse;
    do{
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Bitte nochmal eingeben: ";
        }
        std::cout << "Haus Nr: ";
        std::cin>>pHausNr;
        
    }while(std::cin.fail());
    std::cout <<"Stadt: ";
    std::cin>>pStadt;
    do{
        std::cout << "Postleitzahl: ";
        std::cin>> pPostleitzahl;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Bitte nochmal eingeben: ";
            std::cout << "Postleitzahl: ";
            std::cin>> pPostleitzahl;
        }
    }while( std::to_string(pPostleitzahl).size() < 5);
    std::cout << "Land: ";
    std::cin>> pLand;
    pAdresse = new Adresse(pStrasse, pHausNr, pPostleitzahl,pStadt, pLand);
*/
    currentLoggedINKunde = new  Kunde(pVorname,pNachname, pAdresse, emailAdresse,pContactNr );
    engeschriebenKunden->push_back(currentLoggedINKunde);
    std::cout<< "\nKunde wurde registriert\n"<<std::endl;
    //Kunden sofort anmelden
    kundeAnmelden(currentLoggedINKunde->getKundenID());
    
}
void Bestellsystem::kundeAnmelden(int kundeNr){
    bool isCustomerFound = false;
    Kunde* kunde;
    if(engeschriebenKunden->size() > 0){
        for(int i = 0; i < engeschriebenKunden->size() && isCustomerFound == false; i++){
            kunde = engeschriebenKunden ->at(i);
            if(kundeNr == kunde->getKundenID()){
                kunde->changeAnmeldungStatus(true);
                std:: cout <<"Kunde ist angemeldet\n"<< std::endl;
                isCustomerFound = true;
                kunde->showKundeDetails();
                //updated klassen attribute logged in Kunde to newly logged-in Kunde
                currentLoggedINKunde=kunde;
            }
        }
    }
    else{
        std:: cout <<"\n Kunde ist noch nicht registriert. Bitte zuest registrieren."<< std::endl;
        currentLoggedINKunde = NULL;
    }
}
void Bestellsystem::showOrderSummary(){
    int size = currentLoggedINKunde->getBestellung()->getbestellungSummary()->size();
    std:: cout <<"\n Order Summary:"<< std::endl;
    if(size >0){
        //show summary
            currentLoggedINKunde->getBestellung()->showBestellungSummary();
    }
    else{
        std:: cout <<"\n Es wurde noch keine Bestellung abgegeben:"<< std::endl;
    }
}
//add bestellung in die BestellungsListe
void Bestellsystem::placeOrder(int produktNr){
    if(shop->isProduktAvailable(produktNr)){
        //Product show details and
        std::cout << "\nOrdered Product: " <<std::endl;
        shop->getProdukt(produktNr)->showProduktDetails();
       // add product to Kundensbestellungsliste
        currentLoggedINKunde->getBestellung()->addBestellung(shop->getProdukt(produktNr));
    }
    else{
       std:: cout << "Produkt not available\n" ;
    }
}
void Bestellsystem::deleteOrderedProdukt(int pProduktNr){
   
    int bestellungsSize = currentLoggedINKunde->getBestellung()->getbestellungSummary()->size();
    if(bestellungsSize > 0){
        //remove order from ordersummary of current Kunde
        currentLoggedINKunde->getBestellung()->removeBestellung(pProduktNr);
    currentLoggedINKunde->getBestellung()->showBestellungSummary();
    }
    else{
        std::cout << "Noch keine Besellung abegegebgen\n";
    }
      
}
Kunde* Bestellsystem::getEingeschriebeneKunden(int pKundenNr){
    return engeschriebenKunden->at(pKundenNr);
}

void Bestellsystem::showAllRegisteredKunden(){
    if(engeschriebenKunden->size() > 0){
        std::cout << "\n Registrierten Kunden:\n";
        for (int i = 0; i < engeschriebenKunden->size(); i++) {
            //show Kunden Details
            engeschriebenKunden->at(i)->showKundeDetails();
        }
    }
    else{
        std::cout << "\n Es gibt noch keine registrierten Kunden\n";
    }
}
void Bestellsystem::showShop()const{
    shop->showAllProducts();
}
Kunde * Bestellsystem::getCurrentLoggedInKunde(){
    return currentLoggedINKunde;
}
Shop* Bestellsystem::getShop(){
    return shop;
}
void Bestellsystem::setKundenBestellung(Bestellung* pBestellung){
    currentLoggedINKunde->setBestellung(pBestellung);
}
void Bestellsystem::bezahlen(int bestellungsNummer){
    double currentGuthaben = currentLoggedINKunde->getCredit();
    double bestellungsSumme = currentLoggedINKunde->getBestellung()->getBestellungsSumme();
    
    if(currentGuthaben < bestellungsSumme){
        std::cout << "Guthaben nicht genügend für diese Bestellung. Bitte ein paar Produkte von dem Warenkorb entfernen"<<std::endl;
    }
    else{
        char forsetzen= 'N';
        //Show Kunde information details
        currentLoggedINKunde->showKundeDetails();
        currentLoggedINKunde->showAddress();
        showOrderSummary();
        printf("\nBestellung summe: %.2f",bestellungsSumme);
        printf("\nKundens Guthaben:: %.2f",currentGuthaben);
        std::cout << "\nMöchten Sie die Bestellung forsetzen[J, N]?"<<std::endl;
        std::cin>>forsetzen;
        switch (toupper(forsetzen)) {
            case 'N':
                break;
            case 'J':
                std::cout << "Bestellung wurde erfolgreich bezahlt"<<std::endl;
                currentGuthaben -= bestellungsSumme;
                currentLoggedINKunde->setCredit(currentGuthaben);
                printf("Ihre Guthaben ist jetzt: %.2f\n " ,currentGuthaben)  ;
                break;
                
            default:
                std::cout<<"Bitte nur N oder J eingeben";
                break;
        }
        
    }
    
}
