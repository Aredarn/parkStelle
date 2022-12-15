/*

#include "admin.h"

Admin::Admin(int _id, string _nev, int _szerepkorID, string _jelszo) : Felhasznalok(_id, _nev, _szerepkorID, _jelszo) {

    // Egyenlőre üres
    cout << "Szerepkor:\tADMIN" << endl;
    cout << endl;

}

void Admin::jarmuAdatModosit(Gepjarmu gepjarmu){
    int valasztottSzam = 0;
    cout << "Melyik adatot szeretne modositan? (1, rendszam\n2, Gepjarmu tipusa\n3, Parkolas kezdete\n0, Megse ";
    cin >> valasztottSzam;
    switch(valasztottSzam){
    case 1: {
        string ujRendszam;
        cout << "Adja meg az uj rendszamot: ";
        cin >> ujRendszam;
        cout << endl<<"Sikeresen frissitve!"<<endl<<endl;;
        gepjarmu.setRendszam(ujRendszam);
        break;
    }case 2: {
        string ujTipus;
        cout << "Adja meg az uj tipust: ";
        cin >> ujTipus;
        cout << endl<<"Sikeresen frissitve!"<<endl<<endl;;
        gepjarmu.setGepjarmuTipus(ujTipus);
        break;
    }case 3:{
        string ujParkolas;
        cout << "Adja meg a frissitett parkolasi idot: ";
        cin >> ujParkolas;
        cout << endl<<"Sikeresen frissitve!"<<endl<<endl;
        break;
    }default:{
        cout<<"Kilepes..."<<endl;
    }

    }
}

bool Admin::atHelyezesElfogad(Gepjarmu gepjarmu){
    int elfogad = 0;
    cout << "Elfogadja az athelyezesi kerelmet? (1, igen\n2, nem) "<<endl;
    cin >> elfogad;
    if(elfogad == 1){
        cout << "Kerelem elfogadva!"<<endl;
        return 1;
    }
    cout<<"Kerelem visszautasitva!"<<endl;
    return 0;
}

bool Admin::gepjarmuTisztitas(){
    int elfogad = 0;
    cout << "Elfogadja a gepjarmutisztitasi kerelmet? (1, igen\n2, nem) "<<endl;
    cin >> elfogad;
    if(elfogad == 1){
        cout << "Kerelem elfogadva!"<<endl;
        return 1;
    }
    cout<<"Kerelem visszautasitva!"<<endl;
    return 0;
}

void Admin::gepjarmuvekKilistaz(Gepjarmu gepjarmu){
    cout<<"Gepjarmu ID: " << gepjarmu.getAutoID()<<endl;
    cout<<"Rendszam: " << gepjarmu.getRendszam()<<endl;
    cout<<"Tipus: " << gepjarmu.getGepjarmuTipus()<<endl;
    cout<<"Parkolas kezdete: " << gepjarmu.getParkolasKezdete()<<endl;
}

*/
