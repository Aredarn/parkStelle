#ifndef GEPJARMUVEK_H
#define GEPJARMUVEK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>
#include "gepjarmu.h"
#include <ctime>

using namespace std;

class Gepjarmuvek {

    Gepjarmuvek();

public:
        // STATIKUS METÓDUS - Gépjárművek beolvasása

        static vector<Gepjarmu> beolvasGepjarmuvek() {

            // Deklarációk

            ifstream fajl;
            //string fajlNev = "J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt";
            string fajlNev = "gepjarmuvek.txt";
            vector<Gepjarmu> gepjarmuvek;

            // Fájl megnyitása

            fajl.open(fajlNev.c_str());

            // Fájl sikeres megnyitásának a vizsgálata

            if (fajl.fail()) {

                // A fájlt nem sikerült megnyitni

                cout << "Fájl megnyitása sikertelen volt.";
                return gepjarmuvek;

            }

            // Fájl soronkénti vizsgálata

            string tmp;
            while(getline(fajl, tmp)) {

                stringstream line;
                line << tmp;

                string felhasznaloID;
                string rendszam;
                string gepjarmuTipus;
                string parkolasKezdete;
                string autoID;
                string hosszabitva;

                getline(line, felhasznaloID, ';');
                getline(line, rendszam, ';');
                getline(line, gepjarmuTipus, ';');
                getline(line, parkolasKezdete, ';');
                getline(line, autoID, ';');
                getline(line, hosszabitva, ';');

                gepjarmuvek.push_back(
                    Gepjarmu(
                        stoi(felhasznaloID),
                        stoi(autoID),
                        rendszam,
                        gepjarmuTipus,
                        parkolasKezdete,
                        stoi(hosszabitva)
                    )
                );

            }

            // Beolvasott gépjárművek visszaadása

            return gepjarmuvek;

        }

        // STATIKUS METÓDUS - Keresés rendszám alapján

        static Gepjarmu keresesRendszamAlapjan(string rendszam) {

            vector<Gepjarmu> gepjarmuvek = beolvasGepjarmuvek();

            for (unsigned int i = 0; i < gepjarmuvek.size(); i++) {

                if (gepjarmuvek[i].getRendszam() == rendszam) {

                    return Gepjarmu(gepjarmuvek[i].getFelhasznaloID(),
                                    gepjarmuvek[i].getAutoID(),
                                    gepjarmuvek[i].getRendszam(),
                                    gepjarmuvek[i].getGepjarmuTipus(),
                                    to_string(gepjarmuvek[i].getParkolasKezdeteSZAM()),
                                    gepjarmuvek[i].getHosszabb());

                }

            }

            return Gepjarmu(0, 0, "", "", "",0);

        }

        static Gepjarmu keresesFelhasznaloIDAlapjan(int id) {

            vector<Gepjarmu> gepjarmuvek = beolvasGepjarmuvek();

            for (unsigned int i = 0; i < gepjarmuvek.size(); i++) {

                if (gepjarmuvek[i].getFelhasznaloID() == id) {

                    return Gepjarmu(gepjarmuvek[i].getFelhasznaloID(),
                                    gepjarmuvek[i].getAutoID(),
                                    gepjarmuvek[i].getRendszam(),
                                    gepjarmuvek[i].getGepjarmuTipus(),
                                    gepjarmuvek[i].getParkolas(),
                                    gepjarmuvek[i].getHosszabb());

                }

            }

            return Gepjarmu(0, 0, "", "", "",0);

        }

        static Gepjarmu keresesAutoIDAlapjan(int id) {

            vector<Gepjarmu> gepjarmuvek = beolvasGepjarmuvek();

            for (unsigned int i = 0; i < gepjarmuvek.size(); i++) {

                if (gepjarmuvek[i].getAutoID() == id) {

                    return Gepjarmu(gepjarmuvek[i].getFelhasznaloID(),
                                    gepjarmuvek[i].getAutoID(),
                                    gepjarmuvek[i].getRendszam(),
                                    gepjarmuvek[i].getGepjarmuTipus(),
                                    gepjarmuvek[i].getParkolas(),
                                    gepjarmuvek[i].getHosszabb());

                }

            }

            return Gepjarmu(0, 0, "", "", "",0);

        }


        // STATIKUS METÓDUS - Gépjármű regisztrálása

        static void gepjarmuRegisztralasa(int felhasznaloID, string rendszam, string gepjarmuTipus, string parkolasKezdete, int hosszabb = 0) {

            vector<Gepjarmu> gepjarmuvek = beolvasGepjarmuvek();

            // Kiválasztjuk a legnagyobb autó ID, majd azt növelve megkapjuk az új autó ID -ját

            int autoID = 0;

            for (unsigned int i = 0; i < gepjarmuvek.size(); i++) {

                if (gepjarmuvek[i].getAutoID() > autoID) {

                    autoID = gepjarmuvek[i].getAutoID();

                }

            }

            autoID += 1;

            ofstream fajl;

            //fajl.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", ios_base::app);
            fajl.open("gepjarmuvek.txt", ios_base::app);

            fajl << felhasznaloID << ";" << rendszam << ";" << gepjarmuTipus << ";" << parkolasKezdete << ";" << autoID << ";" << hosszabb << "\n";

            fajl.close();

        }

};

#endif // GEPJARMUVEK_H
