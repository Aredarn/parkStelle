#ifndef ERTESITES_H
#define ERTESITES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>

using namespace std;

class Ertesites {

    private:

        // Tulajdonságok

        int cleanstat;
        int felhasznalotolID;
        int felhasznalonakID;
        string szoveg;
        string tipus;


    public:

        // Konstruktor

        Ertesites(int _felhasznalotolID, int _felhasznalonakID, string _szoveg, string _tipus, int cleanstat = -2) {

            felhasznalotolID = _felhasznalotolID;
            felhasznalonakID = _felhasznalonakID;
            szoveg           = _szoveg;
            tipus            = _tipus;
            this->cleanstat =cleanstat;
        }


        // STATIKUS METÓDUS - Értesítés olvasottá módosítása

        static bool ertesitesTorlese() {

//            // Deklarációk

//            ifstream fajl;
//            string fajlNev = "ertesitesek.txt";
//            vector<Ertesites> ertesitesek;

//            // Fájl megnyitása

//            fajl.open(fajlNev.c_str());

//            // Fájl sikeres megnyitásának a vizsgálata

//            if (fajl.fail()) {

//                // A fájlt nem sikerült megnyitni

//                cout << "Fájl megnyitása sikertelen volt.";
//                return false;

//            }

//            // Fájl soronkénti vizsgálata

//            string tmp;
//            while(getline(fajl, tmp)) {

//                stringstream line;
//                line << tmp;

//                string ertesitesID;

//            }

           // cout << _ertesitesID << endl;

            return true;

        }


        // GETTER - Felhasználótól ID

        int getFelhasznalotolID() {

            return felhasznalotolID;

        }

        // GETTER - Felhasználónak ID

        int getFelhasznalonakID() {

            return felhasznalonakID;

        }


        int getCleanstat() const
        {
            return cleanstat;
        }

        // GETTER - Szöveg

        string getSzoveg() {

            return szoveg;

        }

        // GETTER - Típus

        string getTipus() {

            return tipus;

        }

        void setCleanstat(int newCleanstat)
        {
            cleanstat = newCleanstat;
        }

        int getCleanstat()
        {
            return cleanstat;
        }
};

#endif // ERTESITES_H
