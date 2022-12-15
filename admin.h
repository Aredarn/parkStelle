
#ifndef ADMIN_H
#define ADMIN_H

#include "felhasznalok.h"
#include "gepjarmuvek.h"
#include "ertesitesek.h"

class Admin : public Felhasznalok {

    public:

        // Konstruktor

        Admin(int _id, string _nev, int _szerepkorID, string _jelszo) : Felhasznalok(_id, _nev, _szerepkorID, _jelszo) {

            cout << "Szerepkor:\tAdmin" << endl;
            cout << endl;

        }

        bool menu() {

            int menuPont;

            cout << "+---+--------------------------------------------------+" << endl;
            cout << "| 0 | Kijelentkezes                                    |" << endl;
            cout << "|   |                                                  |" << endl;
            cout << "| 1 | Felhasznalo adat modositasa                      |" << endl;
            cout << "| 2 | Jarmu adatok modositasa                          |" << endl;
            cout << "| 3 | Gepjarmu tisztitas elfogadas                     |" << endl;
            cout << "| 4 | Osszes gepjarmu kilistazasa                      |" << endl;
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

                    cout << "Kivalasztott menupont: 1 -> Felhasznalo adat modositasa" << endl;

                    cout << endl;
                    felhasznaloAdatokModositasa();
                    cout << endl;

                    return true;

                }

                case 2: {

                    system("cls");

                    cout << "Kivalasztott menupont: 2 -> jarmu adat modositasa" << endl;

                    cout << endl;
                    jarmuAdatokModositasa();
                    cout << endl;

                    return true;

                }

                case 3: {

                    system("cls");

                    cout << "Kivalasztott menupont: 3 -> Gepjarmu tisztitas elfogadas" << endl;

                    cout << endl;
                    gepjarmuTisztitasElfogadas();
                    cout << endl;

                    return true;

                }

                case 4: {

                    system("cls");

                    cout << "Kivalasztott menupont: 4 -> Gepjarmuvek kilistazasa" << endl;

                    cout << endl;
                    gepjarmuvekKilistaz();
                    cout << endl;

                    return true;

                }

                default: {

                    system("cls");

                    helytelenMenuPont(menuPont);

                    return true;

                }

            }

        }

        void gepjarmuvekKilistaz()
        {
            vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();

            for(auto it : osszes)
            {

                cout << "Auto ID:\t\t\t" << it.getAutoID() << endl;
                cout << "Rendszam:\t\t\t" << it.getRendszam() << endl;
                cout << "Tipus:\t\t\t\t" << it.getGepjarmuTipus() << endl;
                cout << "Parkolas kezdete:\t\t" << it.getParkolasKezdete() << endl;
                cout << "Varhato befejezes:\t\t" << it.getParkolasVege() << endl;
                cout << "Parkolas hosszabitas (perc):\t" << it.getHosszabb() << endl;
                cout << endl;

            }

        }

        void gepjarmuTisztitasElfogadas()
        {
            vector<Ertesites> ertesitesek = Ertesitesek::beolvasErtesitesek();
            vector<Ertesites> tisztitasok;

            for(auto it : ertesitesek)
            {
                if(it.getCleanstat() == 0)
                    tisztitasok.push_back(it);
            }

            cout << "Valassza ki mit szeretne tenni a fuggoben levo tisztitasokkal: " << endl;
            cout << "[Elfogadas, Elutasitas, Megszakit : (F,E,M)]" << endl;

            string valasz;
            do
                cin >> valasz;
            while(valasz != "F" && valasz != "E" && valasz != "M");

            if(valasz == "F")
            {
                vector<Ertesites> nemtiszt;

                for(auto it : ertesitesek)
                {
                    if(it.getTipus() != "tisztitas")
                        nemtiszt.push_back(it);
                }

                ofstream ofs;
                //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.open("ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                ofstream file;
                //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", ios_base::app);
                file.open("ertesitesek.txt", ios_base::app);

                for(auto it : nemtiszt)
                {
                      file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus() << endl;
                }
                for(auto it : tisztitasok)
                {
                      file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus()<<  ";"<< it.getCleanstat()+1 << endl;
                }

                file.close();

                cout << "Az osszes felhasznalo tisztitasi kerelme elfogadva!!" << endl;
            }
            else if(valasz == "E")
            {
                vector<Ertesites> nemtiszt;

                for(auto it : ertesitesek)
                {
                    if(it.getTipus() != "tisztitas")
                        nemtiszt.push_back(it);
                }

                ofstream ofs;
                //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.open("ertesitesek.txt", std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                ofstream file;
                //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", ios_base::app);
                file.open("ertesitesek.txt", ios_base::app);

                for(auto it : nemtiszt)
                {
                      file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus() << endl;
                }
                for(auto it : tisztitasok)
                {
                      file << it.getFelhasznalotolID() <<";" << it.getFelhasznalonakID() << ";" << it.getSzoveg() << ";" << it.getTipus()<<  ";"<< it.getCleanstat()-1 << endl;
                }


                file.close();

                cout << "Az osszes felhasznalo tisztitasi kerelme elutasitva!!" << endl;
            }
            else
            {

                cout << "Megszakitva" << endl;
            }


        }

        bool felhasznaloAdatokModositasa() {

            //==============================
            // Gépjárművek kilistázása
            //==============================

            vector<Felhasznalok> osszes = Felhasznalok::beolvasFelhasznalok();

            for(auto it : osszes)
            {

                cout << "ID:\t\t" << it.getID() << endl;
                cout << "Nev:\t\t" << it.getNev() << endl;
                cout << "Szerepkor:\t" << it.getSzerepkorNev() << endl;
                cout << endl;

            }

            //==============================
            // Gépjármű kiválasztása
            //==============================

            int felhasznaloID = 0;

            cout << endl;
            cout << "Valasszon egy felhasznalot!" << endl;
            cout << "Adjon meg \"0\"-t a folyamat befejezesehez!" << endl;
            cout << endl;

            do {

                cout << "Felhasznalo ID: ";
                cin >> felhasznaloID;

            } while (felhasznaloID < 0 || felhasznaloID > (int) osszes.size());

            if (felhasznaloID == 0) {

                system("cls");

                return false;

            }

            Felhasznalok felhasznalo = Felhasznalok::keresesFelhasznaloIDAlapjan(felhasznaloID);

            system("cls");
            cout << "Valasztott felhasznalo ID: " << felhasznalo.getID() << endl;
            cout << "Nev: " << felhasznalo.getNev() << endl;
            cout << "Szerepkor: " << felhasznalo.getSzerepkorNev() << endl;
            cout << endl;

            cout << "Ha modositani szeretne az adott mezot, csak irja be a kivant szoveget!" << endl;
            cout << "Maskulonben adjon meg egy \"X\"-et!" << endl;
            cout << endl;

            string ujNev = "";
            string ujSzerepkor = "-6";
            string ujJelszo = "";

            cout << "Uj nev (" << felhasznalo.getNev() << "): ";
            cin >> ujNev;
            if (ujNev == "X") ujNev = felhasznalo.getNev();

            cout << endl;
            cout << "Lehetseges szerepkorok:" << endl;
            cout << "1 - Parkolo szemely" << endl;
            cout << "2 - Parkoloor" << endl;
            cout << "3 - Admin" << endl;
            cout << "Uj szerepkor (" << felhasznalo.getSzerepkorID() << " - " << felhasznalo.getSzerepkorNev() << "): ";
            cin >> ujSzerepkor;
            if (ujSzerepkor == "X") ujSzerepkor = to_string(felhasznalo.getSzerepkorID()); // NEM NYULSZ HOZZA!

            cout << endl;
            cout << "Uj jelszo: ";
            cin >> ujJelszo;
            if (ujJelszo == "X") ujJelszo = felhasznalo.getJelszo();

            //==============================
            // Gépjármű törlése
            //==============================

            vector<Felhasznalok> ujOsszes;

            for(auto it : osszes) {
                if(it.getID() == felhasznaloID) {
                    it.setNev(ujNev);
                    it.setSzerepkorID(ujSzerepkor);
                    it.setJelszo(ujJelszo);
                }
                ujOsszes.push_back(it);
            }

            ofstream ofs;
            //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/felhasznalok.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.open("felhasznalok.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            ofstream file;
            //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/felhasznalok.txt", ios_base::app);
            file.open("felhasznalok.txt", ios_base::app);

            for (unsigned int i = 0; i < ujOsszes.size(); i++) {
               file << ujOsszes[i].getNev() <<
                   ";" << ujOsszes[i].getID() <<
                   ";" << ujOsszes[i].getJelszo()<<
                   ";" << ujOsszes[i].getSzerepkorID() << "\n";
            }

            file.close();

            system("cls");
            cout << "Modositas sikeresen vegrehajtva!" << endl;

            osszes = Felhasznalok::beolvasFelhasznalok();

            for(auto it : osszes)
            {

                cout << "ID:\t\t" << it.getID() << endl;
                cout << "Nev:\t\t" << it.getNev() << endl;
                cout << "Szerepkor:\t" << it.getSzerepkorNev() << endl;
                cout << endl;

            }

            return true;

        }

        bool jarmuAdatokModositasa() {

            //==============================
            // Gépjárművek kilistázása
            //==============================

            vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();

            if (osszes.size() == 0) {

                cout << "Nem allnak rendelkezesre jarmuvek!" << endl;
                cout << "Folyamat automatikus befejezese!" << endl;

                return false;

            }

            for(auto it : osszes)
            {

                cout << "Auto ID:\t" << it.getAutoID() << endl;
                cout << "Rendszam:\t" << it.getRendszam() << endl;
                cout << "Tipus:\t\t" << it.getGepjarmuTipus() << endl;
                cout << endl;

            }

            //==============================
            // Gépjármű kiválasztása
            //==============================

            int gepjarmuID = 0;

            cout << "Valasszon egy gapjarmuvet!" << endl;
            cout << "Adjon meg \"0\"-t a folyamat befejezesehez!" << endl;
            cout << endl;

            do {

                cout << "Gepjarmu ID: ";
                cin >> gepjarmuID;

            } while (gepjarmuID < 0 || gepjarmuID > (int) osszes.size());

            if (gepjarmuID == 0) {

                system("cls");

                return false;

            }

            Gepjarmu gepjarmu = Gepjarmuvek::keresesAutoIDAlapjan(gepjarmuID);

            system("cls");
            cout << "Valasztott gepjarmu ID: " << gepjarmu.getAutoID() << endl;
            cout << "Rendszam: " << gepjarmu.getRendszam() << endl;
            cout << "Tipus: " << gepjarmu.getGepjarmuTipus() << endl;
            cout << endl;

            cout << "Ha modositani szeretne az adott mezot, csak irja be a kivant szoveget!" << endl;
            cout << "Maskulonben adjon meg egy \"X\"-et!" << endl;
            cout << endl;

            string ujRendszam = "";
            string ujTipus = "";

            cout << "Uj rendszam (" << gepjarmu.getRendszam() << "): ";
            cin >> ujRendszam;

            if (ujRendszam == "X") ujRendszam = gepjarmu.getRendszam();

            cout << "Uj tipus (" << gepjarmu.getGepjarmuTipus() << "): ";
            cin >> ujTipus;

            if (ujTipus == "X") ujTipus = gepjarmu.getGepjarmuTipus();

            //==============================
            // Gépjármű törlése
            //==============================

            vector<Gepjarmu> ujOsszes;

            for(auto it : osszes) {
                if(it.getAutoID() == gepjarmuID) {
                    it.setRendszam(ujRendszam);
                    it.setGepjarmuTipus(ujTipus);
                }
                ujOsszes.push_back(it);
            }

            ofstream ofs;
            //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.open("gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            ofstream file;
            //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", ios_base::app);
            file.open("gepjarmuvek.txt", ios_base::app);

            for (unsigned int i = 0; i < ujOsszes.size(); i++) {
               file << ujOsszes[i].getFelhasznaloID() <<
                   ";" << ujOsszes[i].getRendszam() <<
                   ";" << ujOsszes[i].getGepjarmuTipus()<<
                   ";" << ujOsszes[i].getParkolasKezdeteSZAM() <<
                   ";" << to_string(ujOsszes[i].getAutoID()) <<
                   ";" << to_string(ujOsszes[i].getHosszabb()) << "\n";
            }

            file.close();

            system("cls");
            cout << "Modositas sikeresen vegrehajtva!" << endl;
            cout << endl;
            gepjarmuvekKilistaz();

            return true;

        }

};

#endif // ADMIN_H
