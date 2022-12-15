#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>
#include <algorithm>
#include "parkoloszemely.h"
#include "parkoloor.h"
#include "admin.h"
#include <cstring>

using namespace std;

int main()
{

    auto osszes = Felhasznalok::beolvasFelhasznalok();

    // A bemutatónál ezeket kell megváltoztatni

    int id;
    int szerepkorID;
    string nev;
    string jelszo;

    vector<Felhasznalok>::iterator it;

    do
    {

        system("cls");

        cout << "Adja meg a felhasznalonevet: ";
        string name;
        cin >> name;

        it = find_if(osszes.begin(), osszes.end(), [&name] (Felhasznalok& f)
        {

            return name == f.getNev();

        });

    } while ( it == osszes.end() );

    // Adatok lekérése

    int index   = distance(osszes.begin(), it);

    id          = osszes[index].getID();
    nev         = osszes[index].getNev();
    jelszo      = osszes[index].getJelszo();
    szerepkorID = osszes[index].getSzerepkorID();

    string jelsz;

    do
    {

        cout << "Adja meg a jelszavat: ";
        cin >> jelsz;

    } while ( jelszo != jelsz );

    system("cls");

    int statusz = true;

    switch (szerepkorID) {

        case 1 : {

            //==============================
            // Parkoló személy
            //==============================

            // Parkoló személy objektum létrehozása a megadott adatokkal

            ParkoloSzemely felhasznalo = ParkoloSzemely(id, nev, szerepkorID, jelszo);

            if (!felhasznalo.gepjarmuLekerese()) {

                // Ha a felhasználónak nincs regisztrálva gépjárműve és nem is kíván élni a lehetőséggel
                // Script megszakítása

                return 0;

            }

            // Menü folytonos kiiratása, amíg a kijelentkezést (0 menüpont) nem adjuk meg

            do {

                statusz = felhasznalo.menu();

            } while (statusz);

            break;

        }

        case 2 : {

            //==============================
            // Parkolóőr
            //==============================

            // Parkolóőr objektum létrehozása a megadott adatokkal

            ParkoloOr felhasznalo = ParkoloOr(id, nev, szerepkorID, jelszo);

            // Menü folytonos kiiratása, amíg a kijelentkezést (0 menüpont) nem adjuk meg

            do {

                statusz = felhasznalo.menu();

            } while (statusz);

            break;

        }

        case 3 : {

            //==============================
            // Admin
            //==============================

            // Admin létrehozása a megadott adatokkal

            Admin felhasznalo = Admin(id, nev, szerepkorID, jelszo);

            do
            {
                statusz = felhasznalo.menu();
            }while (statusz);

            break;

        }

        default: {

            return 0;

        }

    }

    return 0;
}
