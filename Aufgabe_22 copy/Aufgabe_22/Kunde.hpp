//
//  Kunde.hpp
//  Aufgabe_22
//
//  Created by Vilrose Daquiado on 08.01.23.
//

#ifndef Kunde_hpp
#define Kunde_hpp

#include <stdio.h>
#include <iostream>
#include "Bestellung.hpp"
#include "Adresse.hpp"


class Kunde{
    private:
        int kundenID;
        std::string vorname;
        std::string nachname;
        std::string emailAdresse;
        int contactNr;
        Adresse* adresse;
        double credit = 50.00;
        Bestellung* bestellung;
        //std::vector<Bestellung*> bestellungen;
        bool isKundeAngemeldet = false;

    public:
        static int kundenCount;
        //Konstrukturen
        Kunde();
        Kunde(std::string pVorname, std::string pNachname, Adresse* pAdresse,
              std::string emailAdresse,int pContactNr );
        //Dstruktur
        ~Kunde();
        //Getters
        int getKundenID()const;
        std::string getVorname()const;
        std::string getNachname()const;
        Adresse* getAdresse()const;
        std::string getEmailAdresse()const;
        int getContactNr()const;
        double getCredit() ;
        Bestellung* getBestellung() const;
        //Setters
        void setVorname(std::string pName);
        void setNachname(std::string pNachname);
        void setAdresse(Adresse* pAdresse );
        void setEmailAdresse(std::string pEmailAdresse);
        void setContactNr(int pContactNr);
        void setCredit(double pCredit);
        //Methods
        void showKundeDetails();
        void changeAnmeldungStatus(bool pIstKundeAngemeldet);
        void setBestellung(Bestellung * bestellung);
        void showAddress()const;
};

#endif /* Kunde_hpp */
