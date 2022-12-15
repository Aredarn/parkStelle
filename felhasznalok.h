#ifndef FELHASZNALOK_H
#define FELHASZNALOK_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>

#include "ertesites.h"

using namespace std;

class Felhasznalok {

    protected:

        // Tulajdonságok

        int id;
        string nev;
        int szerepkorID;
        string jelszo;

      public:

        // Konstruktor

        Felhasznalok(int _id, string _nev, int _szerepkorID, string _jelszo) {

            id          = _id;
            nev         = _nev;
            szerepkorID = _szerepkorID;
            jelszo      = _jelszo;

//            cout << "Sikeres bejelentkezes!" << endl;
//            cout << endl;
//            cout << "ID:\t\t" << getID() << endl;
//            cout << "Nev:\t\t" << getNev() << endl;

            //ertesitesek = Ertesites::keresesCimzettAlapjan(id);

        }

        // METODUS - Kijelentkezes

        void kijelentkezes() {

            cout << endl << "Sikeres kijelentkezes!" << endl << endl;

        }

        // GETTER - Szerepkör ID

        int getID() {

            return id;

        }

        // GETTER - Szerepkör ID

        int getSzerepkorID() {

            return szerepkorID;

        }

        // GETTER - Szerepkör ID

        string getSzerepkorNev() {

            switch (szerepkorID) {

                case 1 : return "Parkolo szemely";
                case 2 : return "Parkoloor";
                case 3 : return "Admin";
                default : return "Ismeretlen";

            }

        }

        // GETTER - Név

        string getNev() {

            return nev;

        }

        // GETTER - Jelszó

        string getJelszo() {

            return jelszo;

        }

        // SETTER - Szerepkör ID

        void setID(int _id) {

            id = _id;

        }

        // SETTER - Szerepkör ID

        void setSzerepkorID(string _szerepkorID) {

            szerepkorID = stoi(_szerepkorID);

        }

        // SETTER - Név

        void setNev(string _nev) {

            nev = _nev;

        }

        // SETTER - Jelszó

        void setJelszo(string _jelszo) {

            jelszo = _jelszo;

        }

        // Felhasználok beolvasása statikus függvény

        static vector<Felhasznalok> beolvasFelhasznalok() {

            // Deklarációk

            ifstream fajl;
            //string fajlNev = "J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/felhasznalok.txt";
            string fajlNev = "felhasznalok.txt";
            vector<Felhasznalok> felhasznalok;

            // Fájl megnyitása

            fajl.open(fajlNev.c_str());

            // Fájl sikeres megnyitásának a vizsgálata

            if (fajl.fail()) {

                // A fájlt nem sikerült megnyitni

                cout << "Can not open file!\n";
                return felhasznalok;

            }

            // Fájl soronkénti vizsgálata

            string tmp;
            while(getline(fajl, tmp)) {

                stringstream line;
                line << tmp;

                string id;
                string nev;
                string szerepkorID;
                string jelszo;

                string autoID;
                getline(line, nev, ';');
                getline(line, id, ';');
                getline(line, jelszo, ';');
                getline(line, szerepkorID, ';');


                felhasznalok.push_back(Felhasznalok(stoi(id), nev, stoi(szerepkorID), jelszo));

            }

            // Beolvasott felhasználok visszaadása

            return felhasznalok;

        }

        static Felhasznalok keresesFelhasznaloIDAlapjan(int id) {

            vector<Felhasznalok> felhasznalok = beolvasFelhasznalok();

            for (unsigned int i = 0; i < felhasznalok.size(); i++) {

                if (felhasznalok[i].getID() == id) {

                    return Felhasznalok(felhasznalok[i].getID(),
                                    felhasznalok[i].getNev(),
                                    felhasznalok[i].getSzerepkorID(),
                                    felhasznalok[i].getJelszo());

                }

            }

            return Felhasznalok(0, "", 0, "");

        }

        // Helytelen menü pont

        void helytelenMenuPont(int menuPont) {

            cout << "Helytelen menu pont! (" << menuPont << ")" << endl;
            cout << "Probalja ujra!";
            cout << endl;

        }

        // Kérdés

        bool kerdes(string kerdes = "") {

            cout << kerdes << " [y|n] ";

            string valasz = "n";
            cin >> valasz;

            return valasz == "y";
        }


};

#endif // FELHASZNALOK_H
