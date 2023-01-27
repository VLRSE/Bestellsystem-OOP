    //
    //  Produkt.hpp
    //  Aufgabe_22
    //
    //  Created by Vilrose Daquiado on 06.01.23.
    //

    #ifndef Produkt_hpp
    #define Produkt_hpp
    #include <stdio.h>
    #include <string>
    #include <vector>
  
    class Produkt{
        private:
            std::string produktName;
            double produktPreis;
            int kProduktID;
            
        public:
            static int produktIDCounter;
            //constructors
            Produkt();
            Produkt(std::string pProduktName, double pPreis);
            Produkt(const Produkt& produkt);//Kopierkonstruktor
            //Destruktor
            ~Produkt();
            //getters
            std::string getProduktName();
            int getProduktID();
            std::vector<int>  getGroesse();
            std::vector<int> getProduktFarbe();
            double getProduktPreis();
        
            //setters
            void setProduktName(std::string pProduktName);
            void setGroesse(std::vector<int> pProduktGroessen);
            void setProduktFarben(std::vector<int> pProduktFarbe);
            void setProduktPreis(double pProduktPreis);
            
            //methods
            //method to check if product color is available
            bool checkColorAvailability(int pColor);
            //method to check if product size is available
            bool checkSizeAvailability(int pGroesse);
            void showProduktDetails();
    };


    #endif /* Produkt_hpp */
