#ifndef PARKOLOOR_H
#define PARKOLOOR_H

#include "felhasznalok.h"
#include "gepjarmuvek.h"
#include "ertesites.h"
#include "ertesitesek.h"

class ParkoloOr : public Felhasznalok {

    public:

        // Konstruktor

        ParkoloOr(int _id, string _nev, int _szerepkorID, string _jelszo) : Felhasznalok(_id, _nev, _szerepkorID, _jelszo) {

            cout << "Szerepkor:\tParkoloor" << endl;
            cout << endl;


        }

        // METÓDUS - Menü megjelenítése

        bool menu() {

            int menuPont;

            cout << endl;
            cout << "+---+--------------------------------------------------+" << endl;
            cout << "| 0 | Kijelentkezes                                    |" << endl;
            cout << "|   |                                                  |" << endl;
            cout << "| 1 | Ido tullepesek ellenorzese                       |" << endl;
            cout << "| 2 | Gepjarmu tisztitas elfogadas                     |" << endl;
            cout << "| 3 | Gepjarmuvek kilistazasa                          |" << endl;
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

                    cout << "Kivalasztott menupont: 1 -> Ido tullepesek ellenorzese\n" << endl;
                    idoTulLepEllenoriz();

                    return true;

                }

                case 2: {

                    system("cls");

                    cout << "Kivalasztott menupont: 2 -> Gepjarmu tisztitas elfogadas" << endl;
                    gepjarmuTisztitasElfogadas();
                    return true;

                }

                case 3: {

                    system("cls");

                    cout << "Kivalasztott menupont: 3 -> Osszes gepjarmu megjelenitese " << endl;

                    gepjarmuvekKilistaz();

                    return true;

                }

                default: {

                    system("cls");

                    helytelenMenuPont(menuPont);

                    return true;

                }
            }
        }

        void idoTulLepEllenoriz()
        {

            vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();

            vector<Gepjarmu> tulleptek;

            for(auto it : osszes)
            {
                if(it.getHosszabb() + 90  < it.elteltPercekKezdetOta())
                    tulleptek.push_back(it);
            }


            cout << "+----------+-------------------+------------------+------------------------------+" << endl;
            cout << "| Rendszam | Eltelt ido (perc) | Parkolas kezdete |  Parkolas hosszabitas (perc) |" << endl;
            cout << "+----------+-------------------+------------------+------------------------------+" << endl;

            for(auto it : tulleptek)
            {

                cout << "|   " << it.getRendszam() << " ";

                if (it.elteltPercekKezdetOta() < 10) cout << "|                 " << it.elteltPercekKezdetOta() << " ";
                else if (it.elteltPercekKezdetOta() < 100) cout << "|                " << it.elteltPercekKezdetOta() << " ";
                else if (it.elteltPercekKezdetOta() < 1000) cout << "|               " << it.elteltPercekKezdetOta() << " ";
                else cout << "|              " << it.elteltPercekKezdetOta() << " ";

                if (it.getParkolasKezdete().size() == 7) cout << "|          " << it.getParkolasKezdete() << " ";
                else if (it.getParkolasKezdete().size() == 6) cout << "|           " << it.getParkolasKezdete() << " ";
                else cout << "|            " << it.getParkolasKezdete() << " ";

                if (it.getParkolasVege().size() == 7) cout << "|                      " << it.getParkolasVege() << " ";
                else if (it.getParkolasVege().size() == 6) cout << "|                       " << it.getParkolasVege() << " ";
                else cout << "|                        " << it.getParkolasVege() << " ";
                cout << "|" << endl;

            }

            cout << "+----------+-------------------+------------------+------------------------------+" << endl;

            cout << endl;
            cout << "+---+--------------------------------------------------+" << endl;
            cout << "| 0 | Megszakitas                                      |" << endl;
            cout << "|   |                                                  |" << endl;
            cout << "| 1 | Elszallitatas                                    |" << endl;
            cout << "| 2 | Ertesites kuldese a tulajdonosnak                |" << endl;
            cout << "+---+--------------------------------------------------+" << endl;
            cout << endl;

            string valasz;

            do
            {
                cout << "Menupont kivalasztasa: ";
                cin >> valasz;
            }
            while(valasz!="0" && valasz!="1" && valasz!="2");



            if(valasz == "1")
            {

                vector<Gepjarmu> maradok;

                for(auto it : osszes)
                {
                    if(it.getHosszabb() + 60 > it.elteltPercekKezdetOta())
                        maradok.push_back(it);
                }


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
                       ";" << maradok[i].getGepjarmuTipus()<<
                       ";" << maradok[i].getParkolasKezdeteSZAM() <<
                       ";" << to_string(maradok[i].getAutoID()) <<
                       ";" << to_string(maradok[i].getHosszabb()) << "\n";
                }

                file.close();

                // system("cls");

                cout << "A gepjarmuvek amelyek tulleptek a parkolasi idot el lettek szallitatva!" << endl;

            } else if(valasz == "2") {
                vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();

                // Fájl megnyitása

                ofstream file;
                //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/ertesitesek.txt", ios_base::app);
                file.open("ertesitesek.txt", ios_base::app);

                for(auto it : tulleptek)
                {
                    for(auto et : osszes)
                        if(it.getAutoID() == et.getAutoID())
                        {
                            file << this->getID() << ";" << et.getFelhasznaloID() << ";" << "Figyelmeztetes! Lejart a parkolasi ideje" << ";" << "parkolas lejart" << endl;
                        }
                }

                file.close();

                system("cls");

                cout << "Ertesitesek kikuldve a parkolo szemelyeknek!" << endl;

            } else {

                system("cls");

                cout << "Megszakitva!" << endl;

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

        void gepjarmuvekKilistaz()
        {
            vector<Gepjarmu> osszes = Gepjarmuvek::beolvasGepjarmuvek();

            cout << endl;
            cout << "+----+----------+-------+------------------+-------------------+-----------------------------+" << endl;
            cout << "| ID | Rendszam | Tipus | Parkolas kezdete | Varhato befejezes | Parkolas hosszabitas (perc) |" << endl;
            cout << "+----+----------+-------+------------------+-------------------+-----------------------------+" << endl;

            for(auto it : osszes)
            {

                if (it.getAutoID() > 9) cout << "| " << it.getAutoID() << " ";
                else cout << "|  " << it.getAutoID() << " ";

                cout << "|   " << it.getRendszam() << " ";

                if (it.getGepjarmuTipus().size() == 4) cout << "|  " << it.getGepjarmuTipus() << " ";
                else cout << "| " << it.getGepjarmuTipus() << " ";

                if (it.getParkolasKezdete().size() == 7) cout << "|          " << it.getParkolasKezdete() << " ";
                else if (it.getParkolasKezdete().size() == 6) cout << "|           " << it.getParkolasKezdete() << " ";
                else cout << "|            " << it.getParkolasKezdete() << " ";

                if (it.getParkolasVege().size() == 7) cout << "|           " << it.getParkolasVege() << " ";
                else if (it.getParkolasVege().size() == 6) cout << "|            " << it.getParkolasVege() << " ";
                else cout << "|             " << it.getParkolasVege() << " ";

                if (it.getHosszabb() == 0) cout << "|                           " << it.getHosszabb() << " |" << endl;
                else cout << "|                          " << it.getHosszabb() << " |" << endl;

            }

            cout << "+----+----------+-------+------------------+-------------------+-----------------------------+" << endl;

        }

};

#endif // PARKOLOOR_H
