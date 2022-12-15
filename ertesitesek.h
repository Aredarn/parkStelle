#ifndef ERTESITESEK_H
#define ERTESITESEK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>

#include "ertesites.h"

using namespace std;
class Ertesitesek
{
public:
    Ertesitesek();

    // STATIKUS METÓDUS - Értesítések beolvasása

    static vector<Ertesites> beolvasErtesitesek() {

        // Deklarációk

        ifstream fajl;
        //string fajlNev = "J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt";
        string fajlNev = "ertesitesek.txt";
        vector<Ertesites> ertesitesek;

        // Fájl megnyitása

        fajl.open(fajlNev.c_str());

        // Fájl sikeres megnyitásának a vizsgálata

        if (fajl.fail()) {

            // A fájlt nem sikerült megnyitni

            cout << "Fájl megnyitása sikertelen volt.";
            return ertesitesek;

        }

        // Fájl soronkénti vizsgálata

        string tmp;
        while(getline(fajl, tmp)) {

            stringstream line;
            line << tmp;

            string felhasznalotolID;
            string felhasznalonakID;
            string szoveg;
            string tipus;
            string stat;

            getline(line, felhasznalotolID, ';');
            getline(line, felhasznalonakID, ';');
            getline(line, szoveg, ';');
            getline(line, tipus, ';');

            if (tipus == "tisztitas") getline(line, stat, ';');
            else stat = "-2";

//            cout << "stat: " << stat << endl;
//            cout << "tipus: " << tipus << endl;
//            cout << "szoveg: " << szoveg << endl;
//            cout << "felhasznalonakID: " << felhasznalonakID << endl;
//            cout << "felhasznalotolID: " << felhasznalotolID << endl;

            ertesitesek.push_back(
                Ertesites(
                    stoi(felhasznalotolID),
                    stoi(felhasznalonakID),
                    szoveg,
                    tipus,
                    stoi(stat)
                )
            );

            /*

            if(tipus == "tisztitas")
            {
                getline(line, stat, ';');

                cout << stat << endl;
                if (stat == "") stat = "Test";
                cout << stat << endl;

                ertesitesek.push_back(
                    Ertesites(
                        stoi(felhasznalotolID),
                        stoi(felhasznalonakID),
                        szoveg,
                        tipus,
                    stoi(stat)
                ));

            } else {

                ertesitesek.push_back(
                    Ertesites(
                        stoi(felhasznalotolID),
                        stoi(felhasznalonakID),
                        szoveg,
                        tipus
                    )
                );

            }

            */

        }

        // Beolvasott értesítések visszaadása
        return ertesitesek;
    }

    // STATIKUS METÓDUS - Keresés címzett alapján

    static vector<Ertesites> keresesCimzettAlapjan(int cimzett) {

        vector<Ertesites> talalatok;
        vector<Ertesites> ertesitesek = beolvasErtesitesek();

        for (unsigned int i = 0; i < ertesitesek.size(); i++) {

            // cout << "Cimzett: " << ertesitesek[i].felhasznalonakID << endl;

            if (ertesitesek[i].getFelhasznalonakID() == cimzett) {

                talalatok.push_back(
                    Ertesites(
                        ertesitesek[i].getFelhasznalotolID(),
                        ertesitesek[i].getFelhasznalonakID(),
                        ertesitesek[i].getSzoveg(),
                        ertesitesek[i].getTipus()
                    )
                );

            }

        }

        return talalatok;

    }

    // STATIKUS METÓDUS - Keresés értesítés ID alapján

    static vector<Ertesites> osszesErtesitesIDAlapjan(int ertesitesCimzettID) {

        vector<Ertesites> ertesitesek = beolvasErtesitesek();

        vector<Ertesites> adottFelhasznaloknak;
        for(auto it : ertesitesek)
        {
            if(ertesitesCimzettID == it.getFelhasznalonakID())
                adottFelhasznaloknak.push_back(it);
        }


        return adottFelhasznaloknak;

    }


};

#endif // ERTESITESEK_H
