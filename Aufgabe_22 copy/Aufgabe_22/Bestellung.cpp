//
//  Bestellung.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 12.01.23.
//

#include "Bestellung.hpp"
int Bestellung::orderCounter = 1;

//constructors
Bestellung::Bestellung():orderCount(orderCounter++){produktBestellung = new std::vector<Produkt*>(); }
Bestellung::Bestellung( std::vector<Produkt*> *pProduktBestellung)
:produktBestellung(pProduktBestellung),orderCount(orderCounter++){}
//destruktor
Bestellung::~Bestellung(){orderCounter--;
    for(int i = 0; i < produktBestellung->size(); i++){
        delete produktBestellung->at(i);
    }
   // delete this; 
}
//Getter and setter
std::vector<Produkt*>* Bestellung::getbestellungSummary() const{return produktBestellung;}

void Bestellung::addBestellung(Produkt* pAdditionalBestellung){
    produktBestellung->push_back(pAdditionalBestellung);
    bestellungSumme += produktBestellung->back()->getProduktPreis();
    std:: cout << "\nProdukt wurde erfolgreich hinzugefügt\n";
}
void Bestellung::removeBestellung(int pProduktId){
    if(produktBestellung->size() > 0){
        Produkt* currentProdukt;
        for(int i = 0; i < produktBestellung->size(); i++ ){
            currentProdukt = produktBestellung->at(i);
            if(currentProdukt->getProduktID() == pProduktId){
                std::cout << "Produkt found" << std::endl;
                if(produktBestellung->size() > 0)
                    bestellungSumme -= currentProdukt->getProduktPreis();
               // delete produktBestellung->begin()+i;
                produktBestellung->erase(produktBestellung->begin()+i);
                std:: cout << "\nProdukt wurde erfolgreich entfernt\n";
                orderCounter--;
                //The removed order price to subtract from the total order sum, if orders more than 1 item.
               
            }
            else{
                std:: cout << "\nProdukt ist nicht auf der Bestellungsliste\n";
            }
        }
    }
}
void Bestellung::showBestellungSummary(){
    //show ordered products
    if(produktBestellung->size() > 0){
        for (int i = 0; i < produktBestellung->size(); i++) {
            produktBestellung->at(i)->showProduktDetails();
            std::cout << "\n\n";
        }
    }
    else{
        std::cout << "Es gibt noch keine Bestellung" <<std::endl;
    }
}

double Bestellung::getBestellungsSumme(){
    return bestellungSumme;
}
