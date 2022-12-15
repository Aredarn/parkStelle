#ifndef PARKOLOSZEMELY_H
#define PARKOLOSZEMELY_H

#include <string>
#include <time.h>
#include <chrono>
#include "felhasznalok.h"
#include "gepjarmuvek.h"
#include "ertesitesek.h"

class ParkoloSzemely : public Felhasznalok {

    private:

        // Tulajdonságok

        Gepjarmu gepjarmu = Gepjarmu(0, 0, "", "", "");

    public:

        // Konstruktor

        ParkoloSzemely(int _id, string _nev, int _szerepkorID, string _jelszo) : Felhasznalok(_id, _nev, _szerepkorID, _jelszo) {

            cout << "Szerepkor:\tParkoloSzemely" << endl;

       }

        // METODUS - Gépjármű lekérése

        bool gepjarmuLekerese() {

            Gepjarmu gepjarmuEredmeny = Gepjarmuvek::keresesFelhasznaloIDAlapjan(id);

            if (gepjarmuEredmeny.getAutoID() != 0) {

                // Az autó már regisztrálva van a rendszerben

                gepjarmu = gepjarmuEredmeny;

                cout << endl;
                cout << "Jarmu lekerese sikeresen megtortent!" << endl;
                cout << endl;
                sajatAutoAdatokKiir();

            } else {

                // Az autó regisztálása a rendszerbe

                cout << endl;
                cout << "Nincs meg auto megadva ehhez a belepeshez!" << endl;

                string regisztralas;
                cout << "Kivanja regisztralni? [y|N] ";
                cin >> regisztralas;

                if (regisztralas != "y") {

                    // A felhasználó nem kívánta regisztrálni a gépjárművet

                    cout << endl;
                    cout << "Regisztralas megszakitva!" << endl;
                    cout << "Kijelentkezes." << endl;

                    return false;

                }

                // A regisztrálás

                string rendszam;
                cout << endl;
                cout << "Gepjarmu regisztralasa:" << endl;
                cout << "Kerem adja meg a rendszamot: ";
                cin >> rendszam;
                string gepjarmuTipus;
                cout << "Gepjarmu tipusa: ";
                cin >> gepjarmuTipus;

                time_t aktualisIdo = time(0);
                string parkolasKezdete = to_string(aktualisIdo);

                Gepjarmuvek::gepjarmuRegisztralasa(id, rendszam, gepjarmuTipus, parkolasKezdete);

                // Gépjármű újra lekérése

                Gepjarmu gepjarmuEredmeny = Gepjarmuvek::keresesRendszamAlapjan(rendszam);

                gepjarmu = gepjarmuEredmeny;

                cout << endl;
                cout << "Jarmu lekerese sikeresen megtortent!" << endl;
                cout << endl;
                sajatAutoAdatokKiir();

            }

            return true;

        }

        // METÓDUS - A parkolási összeg kiiratása

        bool parkolasOsszegKiiratas() {

            int percek = elteltPercekKezdetOta();

            cout << "Percek: " << percek << endl;

            int osszeg = 0;

            // Összegek percenként:

            // Motorkerekpar: 2ft
            // Auto: 3ft
            // Teher: 5ft

            string tipus = gepjarmu.getGepjarmuTipus();

            if (tipus == "Motor") {

                osszeg = 2 * percek;

            } else if (tipus == "Auto") {

                osszeg = 3 * percek;

            } else if (tipus == "Teher") {

                osszeg = 5 * percek;

            }

            cout << "Jelenlegi osszeg: " << osszeg << " Ft" << endl;

            cout << "Szeretne fizetni? [y/N]: " ;
            string option;

            cin >> option;

            if(option == "y")
            {
                cout << endl;
                cout << "Koszonjuk a parkolast!" << endl;

                //==============================
                // Gépjármű törlése
                //==============================

                vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();
                vector<Gepjarmu> maradok;

                int autoID = gepjarmu.getAutoID();

                for(auto it : osszes)
                    if(it.getAutoID() != autoID)
                        maradok.push_back(it);

                ofstream ofs;
                //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.open("gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                ofstream file;
                //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", ios_base::app);
                file.open("gepjarmuvek.txt", ios_base::app);

                for (unsigned int i = 0; i < maradok.size(); i++) {
                   file << maradok[i].getFelhasznaloID() <<
                       ";" << maradok[i].getRendszam() <<
                       ";" <<  maradok[i].getGepjarmuTipus()<<
                       ";" <<  maradok[i].getParkolasKezdeteSZAM() <<
                       ";" <<to_string(maradok[i].getAutoID()) <<
                       ";" <<  to_string(maradok[i].getHosszabb()) << "\n";
                }

                file.close();

                //==============================
                // Gépjármű törlése
                //==============================

                vector<Ertesites> osszesErtesites = Ertesitesek::beolvasErtesitesek();
                vector<Ertesites> maradokErtesites;

                for(auto it : osszesErtesites)
                {

                    if(it.getFelhasznalotolID() == id) continue;
                    if(it.getFelhasznalonakID() == id) continue;

                    maradokErtesites.push_back(it);

                }

                //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.open("ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", ios_base::app);
                file.open("ertesitesek.txt", ios_base::app);

                for (unsigned int i = 0; i < maradokErtesites.size(); i++) {
                   file << maradokErtesites[i].getFelhasznalotolID() <<
                       ";" << maradokErtesites[i].getFelhasznalonakID() <<
                       ";" <<  maradokErtesites[i].getSzoveg()<<
                       ";" <<  maradokErtesites[i].getTipus() <<
                       ";" <<to_string(maradokErtesites[i].getCleanstat()) << "\n";
                }

                file.close();

                kijelentkezes();
                return false;
            }

            return true;

        }

        //METÓDUS - Eltelt percek számolás

        int elteltPercekKezdetOta()
        {
            //Megkapja mikor kezdte a parkolást
            int  kezdet =gepjarmu.getParkolasKezdeteSZAM();
            int kMin = (kezdet/60)%60;
            int kHour = ((kezdet/3600)%60);


            //Aktuális idő
            time_t aktualisIdo = time(0);
            int aMin = (aktualisIdo/60)%60;
            int aHour = (aktualisIdo/3600)%60 +1;


            //Kiszámolja hány perc telt el a 2 érték közt
            //Figyelembe veszi az időeltolódást is
            int minutesPassed;

//            if(kMin > aMin)
//            {
               minutesPassed = ((aHour-kHour) -1)*60 + (aMin-kMin);
//            }
//            else
//            {
//                minutesPassed = (aHour-kHour)*60 + (aMin-kMin);
//            }

            return minutesPassed;
        }

        // METÓDUS - Parkolás meghosszabítása egy bizonyos idővel

        void parkolasMeghosszabitas(int ido) {

            gepjarmu.setHosszabb(ido);

        }

        // METÓDUS - Tisztítási kérelem

        bool tisztitasKerelem() {

            //vector<vector<int>> tisztitasiKerelmek = beolvasTisztitasiKerelmek();

            vector<Ertesites> osszes = Ertesitesek::beolvasErtesitesek();
            int status = -2;
            for(auto it: osszes)
            {
                if(it.getFelhasznalotolID() == this->getID() && it.getTipus() == "tisztitas")
                {
                    cout << "A gepjarmu mar tisztitasra lett kerelmezve!" << endl;
                    cout << "Statusza: " << it.getCleanstat() << " - ";
                    switch (it.getCleanstat()) {
                        case -1 :
                        {
                            cout << "Elutasitva" << endl;
                            break;
                        }
                        case 0 : {

                            cout << "Elfogadasra var" << endl;
                            break;

                        }

                        case 1 : {

                            cout << "Elfogadva" << endl;

                            break;

                        }
                    }
                    return false;
                }

            }
            if(status == -2){
                if (!kerdes("Szeretne tisztitast kerelmezni?")) {

                        // A parkoló személy nem szeretne tisztítást kérelmezni

                        cout << endl;
                        cout << "Tisztitasi kerelem visszavonva!" << endl;

                    }
                else {

                        // A parkoló személy szeretne tisztítást kérelmezni

                        ofstream fajl;

                        //.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", ios_base::app);
                        fajl.open("ertesitesek.txt", ios_base::app);

                        fajl << this->getID() << ";" << 2 << ";" <<  "Tisztitasi kerelem" << ";" << "tisztitas" << ";" << 0 << "\n";

                        fajl.close();

                        cout << endl;
                        cout << "Tisztitas sikeresen kerelmezve lett!" << endl;

                    }

                return true;

            }

            return false;

        }

        // METÓDUS - Saját autó adatainak kiiratása

        void sajatAutoAdatokKiir() {

            cout << "Auto ID:\t\t" << gepjarmu.getAutoID() << endl;
            cout << "Rendszam:\t\t" << gepjarmu.getRendszam() << endl;
            cout << "Gepjarmu tipus:\t\t" << gepjarmu.getGepjarmuTipus() << endl;
            cout << "Parkolasi ido kezdete:\t" << gepjarmu.getParkolasKezdete() << endl;
            cout << "Parkolas vege:\t\t" << gepjarmu.getParkolasVege();
            cout << endl;

        }

        // METÓDUS - Saját értesítések kiiratása

        void ertesitesekMegjelenit()
        {
            vector<Ertesites> sajat_ossz= Ertesitesek::osszesErtesitesIDAlapjan(id);

            if(sajat_ossz.size() > 0)
            {
                for(auto it : sajat_ossz)
                {
                    cout << it.getFelhasznalotolID() << " az ertesites tipusa:  " << it.getTipus() << "  " << endl << "\t" << it.getSzoveg() << endl;
                }

                cout << "Olvasottnak tekinti uzeneteit? [y/N]" << endl;
                string valasz = "Ű";

                do
                {
                    if(valasz !="Ű")
                        cout << "Helytelen valasz";
                    cin >> valasz;

                }while(valasz !="y" && valasz !="N");

                if(valasz == "y")
                {
                    vector<Ertesites> ossz = Ertesitesek::beolvasErtesitesek();

                    ofstream ofs;
                    //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                    ofs.open("ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                    ofs.close();
                    ofstream file;
                    //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", ios_base::app);
                    file.open("ertesitesek.txt", ios_base::app);

                    for(auto it : ossz)
                    {
                        if(it.getFelhasznalonakID() != this->getID())
                        {
                            if (it.getTipus() == "tisztitas") {
                                file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus() << ";" << it.getCleanstat() << endl;
                            } else {
                                file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus() << endl;
                            }
                        }
                    }
                    file.close();

                    cout << "Ertesitesek elolvasottnak jelolve" << endl;
                }
                else
                {
                    cout << "Ertesitesek tovabbi megorzese valasztva" << endl;
                }
            }
            else
            {
                cout << "Nincsenek ertesitesei. " << endl;
            }
        }


        // METÓDUS - Menü megjelenítése

        bool menu() {

            int menuPont;

            cout << endl;
            cout << "+---+--------------------------------------------------+" << endl;
            cout << "| 0 | Kijelentkezes                                    |" << endl;
            cout << "|   |                                                  |" << endl;
            cout << "| 1 | Parkolasi osszeg kiiratasa                       |" << endl;
            cout << "| 2 | Parkolas meghosszabitasa                         |" << endl;
            cout << "| 3 | Tisztitasi kerelem                               |" << endl;
            cout << "| 4 | Sajat auto adatainak kiiratasa                   |" << endl;
            cout << "| 5 | Ertesitesek megjelenitese                        |" << endl;
            cout << "+---+--------------------------------------------------+" << endl;
            cout << endl;

            cout << "Menupont kivalasztasa: ";
            cin >> menuPont;

            switch (menuPont) {

                case 0: {

                    system("cls");

                    cout << "Kivalasztott menupont: 0 -> Kijelentkezes" << endl;

                    kijelentkezes();

                    return false;

                }

                case 1: {

                    system("cls");

                    cout << "Kivalasztott menupont: 1 -> Parkolasi osszeg kiiratasa" << endl;

                    cout << endl;
                    sajatAutoAdatokKiir();
                    cout << endl;

                    return parkolasOsszegKiiratas();

                }

                case 2: {

                    system("cls");

                    cout << "Kivalasztott menupont: 2 -> Parkolas meghosszabitasa" << endl;

                    int percek = 0;

                    cout << endl;
                    cout << "Hany perccel szeretne meghosszabitani a parkolast (5,15,30): ";
                    do
                    {
                        if(percek != 0)
                            cout << "Nem megfelelo ertek";
                        cin >> percek;

                    }
                    while(percek != 5 && percek != 15 && percek != 30);

                    parkolasMeghosszabitas(percek);

                    return true;

                }

                case 3: {

                    system("cls");

                    cout << "Kivalasztott menupont: 3 -> Tisztitasi kerelem" << endl;

                    cout << endl;
                    tisztitasKerelem();

                    return true;

                }

                case 4: {

                    system("cls");

                    cout << "Kivalasztott menupont: 4 -> Sajat auto adatainak kiiratasa" << endl;

                    cout << endl;
                    sajatAutoAdatokKiir();

                    return true;

                }
                case 5: {

                    system("cls");

                    cout << "Kivalasztott menupont: 5 -> Ertesitesek megjelenitese" << endl;

                    cout << endl;
                    ertesitesekMegjelenit();

                    return true;

                }

                default: {

                    system("cls");

                    helytelenMenuPont(menuPont);

                    return true;

                }

            }

        }
};

#endif // PARKOLOSZEMELY_H
