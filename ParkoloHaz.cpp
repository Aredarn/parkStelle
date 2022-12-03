#include <iostream>
#include "felhasznalok.h"
#include "parkoloszemely.h"
#include "parkoloor.h"
#include <list>
using namespace std;


void foMenuMegjelenit()
{
    int menupont;
    cout << "0. bejovo ertesitesek" << endl;
    cout << "1. Felhasznalovaltas" << endl;
    cout << "2. Parkolas osszeg kiirat" << endl;
    cout << "3. Parkolas meghosszabit" << endl;
    cout << "4. Tisztitasi kerelem" << endl;
    cout << "5. Auto adatai" << endl;



    cin >> menupont;
}



int main()
{
    //A felhasználó ID-k jelentése:
    // 1 = parkolószemély
    // 2 = parkolóőr
    // 3 = Admin

    bool run = true;

    ParkoloSzemely felhasznalo("Sanyi", 1, "abc");
    Parkoloor ore("Endre",2,"cba");

    vector<Felhasznalok> ok;

    ok.push_back(felhasznalo);
    ok.push_back(ore);

    for(const auto &it : ok)
    {
        cout << it.getSzerepKorID();
    }

    while(run)
    {
       foMenuMegjelenit();
    }

    return 0;
}




