#include <iostream>
#include "felhasznalok.h"
#include "parkoloszemely.h"
#include "parkoloor.h"
#include "admin.h"
#include <list>
using namespace std;
Felhasznalok aktiv;


vector<Felhasznalok> readAllFelhasznalo()
{
    vector<Felhasznalok> temp;

    ifstream inFile("Felhasznalok.txt");
        if (inFile.is_open())
        {
            string line;
            while( std::getline(inFile,line) )
            {
                stringstream ss(line);

                string fname, password, tempID;
                int ID;
                getline(ss,fname,',');// cout<<"\" "<<fname<<"\"";
                getline(ss,tempID,',');// cout<<"\" "<<tempID<<"\"";
                getline(ss,password,',');// cout<<" \""<<password<<"\"";

                ID = stoi(tempID);

                //ParkoloSzemely szemely;

                string course;
                if(ID == 1)
                {
                    temp.push_back(ParkoloSzemely(fname,ID,password));

                }
                else if(ID == 2)
                {
                    temp.push_back(Parkoloor(fname,ID,password));
                }
                else
                {
                    temp.push_back(Admin(fname,ID,password));
                }
            }
        }
        return temp;
}

auto osszes = readAllFelhasznalo();

void felhasznaloID()
{
    cout << "Szemely, parkoloor vagy admin? (1,2,3)" << endl;
    int idNum = 0;
    cin >> idNum;

    aktiv = osszes[idNum -1];

}

int foMenuMegjelenit()
{

    int menupont;
    cout << "0. bejovo ertesitesek" << endl;
    cout << "1. Felhasznalovaltas" << endl;
    if(aktiv.getSzerepKorID() == 1)
    {

        cout << "2. Parkolas osszeg kiirat" << endl;
        cout << "3. Parkolas meghosszabit" << endl;
        cout << "4. Tisztitasi kerelem" << endl;
        cout << "5. Auto adatai" << endl;
    }
    if(aktiv.getSzerepKorID() == 2)
    {
        cout << "2. Osszes gepjarmu kilistazasa" << endl;
        cout << "3. Idotullepes ellenorzese" << endl;
        cout << "4. Athelyezes elfogadasa " << endl;
        cout << "5. Tisztitasi kerelem" << endl;
    }

    cin >> menupont;
    system ("CLS");
    cout << flush;
    return menupont;
}

void akctionEloszto(int a)
{
    if(aktiv.getSzerepKorID() == 1)
    {
        ParkoloSzemely tmp(aktiv.getNev(),aktiv.getSzerepKorID(),aktiv.getJelszo());
        switch(a)
        {
            case 1:
                felhasznaloID();
            break;
            case 2:
                tmp.parkolasOsszegKiirat();
            break;
        };

    }
    if(aktiv.getSzerepKorID() == 2)
    {
        Parkoloor tmp(aktiv.getNev(),aktiv.getSzerepKorID(),aktiv.getJelszo());
        switch(a)
        {
            case 1:
                felhasznaloID();
            break;
            case 2:
                tmp.GepjarmuListaz();
            break;
        };
    }
    if(aktiv.getSzerepKorID() == 3)
    {
        Admin tmp(aktiv.getNev(),aktiv.getSzerepKorID(),aktiv.getJelszo());
        switch(a)
        {
            case 1:
                felhasznaloID();
            break;
        };
    }
}


int main()
{

    aktiv = osszes[0];

    //A felhasználó ID-k jelentése:
    // 1 = parkolószemély
    // 2 = parkolóőr
    // 3 = Admin

    bool run = true;


    while(run)
    {
       akctionEloszto(foMenuMegjelenit());
    }

    return 0;
}




