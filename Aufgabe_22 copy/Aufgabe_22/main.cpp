//
//  main.cpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 06.01.23.
//

#include <iostream>
#include <stdlib.h> // toupper()
#include "Produkt.hpp"
#include "Shop.hpp"
#include "Bestellung.hpp"
#include "Bestellsystem.hpp"
#include <vector>

using namespace std;


char showMenu(){
    char choice;
    cout<<"\n\tMENU"<< endl;
    cout<<"Registrieren [R]"<< endl;
    cout<<"Anmelden [A]"<< endl;
    cout<<"Bestellen [B]"<< endl;
    cout<<"Bestellung Anzeigen [S]"<< endl;
    cout<<"Bezahlen [P]"<< endl;
    cout<<"Bestellte Produkt Entfernen [E]"<< endl;
    cout<<"Programm beenden [X]"<< endl;
    cout<<"Auswahl eingeben: ";
    cin>> choice;
    return toupper(choice);
}


int main() {
 //  char choice =  showMenu();
    Bestellsystem * bestellsystem = new Bestellsystem();
    
    int produktNrToRemove ;
    Kunde * kundePTR;
    bool continueLoop = true;

    do{
        switch ( showMenu()) {
            case 'R':
                //Register new Kunde
                bestellsystem->kundeRegistrieren();
                break;
            case 'A':
                //Allow registered Kunde to log-in
                int kundenNr;
                cout << " Bitte kundenNr eingeben: ";
                cin>>kundenNr;
                bestellsystem->kundeAnmelden(kundenNr);
                break;
            case 'B':
                int produktNr;
                //Verify first if shopper ist registered or logged-in
                if(bestellsystem->getCurrentLoggedInKunde() == NULL){
                    cout  << " Bitte Sie sich zuerst registrieren oder anmelden\n";
                    continue;
                }
                else{
                    //Show Shop
                    bestellsystem->showShop();
                    cout << "Bitte Produktnummer eingeben: ";
                    cin >> produktNr;
                    cout << "Current Kunde " <<bestellsystem->getCurrentLoggedInKunde()->getKundenID()<<endl ;
                    bestellsystem->placeOrder(produktNr);
                }
                break;
                
            case 'S':
                //Show Kundens Bestellung
                //Show only Bestellung summary if and only if there is a Kunde is logged-in, who registered
                if(bestellsystem->getCurrentLoggedInKunde() != NULL){
                    bestellsystem->showOrderSummary();
                    printf("Summe: %.02f \n", bestellsystem->getCurrentLoggedInKunde()->getBestellung()->getBestellungsSumme());
                }
                break;
            case 'P':
                //Bezahlen
                //For now, only one Bestellung is allowed
                if(bestellsystem->getCurrentLoggedInKunde() !=NULL){
                    bestellsystem->bezahlen(0);
                }
                else{
                    cout <<"Please place order first." << endl;
                }
                break;
            case 'E':
                cout <<"Bitte die Produktnummer, die Sie entfernen möchten, eingeben: " ;
                cin>>produktNrToRemove;
             
               // kundePTR->getBestellung()->removeBestellung(produktNrToRemove);
                bestellsystem->deleteOrderedProdukt(produktNrToRemove);
                break;
            case 'X':
                //Show Kundens Bestellung
                cout << "\n Programm beendet \n";
                continueLoop = false;
                break;
                
            default:
                break;
        }
    }while(continueLoop);
  
    return 0;
}
