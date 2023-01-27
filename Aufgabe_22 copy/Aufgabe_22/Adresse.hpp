//
//  Adresse.hpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 08.01.23.
//

#ifndef Adresse_hpp
#define Adresse_hpp

#include <stdio.h>
#include <iostream>

class Adresse{
    private:
        std::string strasse;
        int hausNr;
        int postleitzahl;
        std::string stadt;
        std::string land;
    
    public:
        // Konstrukturen
        Adresse();
        Adresse( std::string pStrasse,int pHausNr, int pPostleitzahl,
                std::string pStadt, std::string pLand);
        //Destrukturen
        ~Adresse();
        //Getters
        std::string getStrasse();
        int getHausNr();
        int getpostleitzahl();
        std::string getStadt();
        std::string getLand();
        //Setters
        void setStrasse() const;
        void setHausNr()const;
        void getpostleitzahl() const;
        void getStadt()const;
        void getLand()const;
};
#endif /* Adresse_hpp */
