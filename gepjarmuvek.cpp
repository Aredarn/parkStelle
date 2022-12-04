#include "gepjarmuvek.h"

int Gepjarmuvek::listazGepJarmuvek()
{
    ifstream inFile("Gepjarmuvek.txt");
        if (inFile.is_open())
        {
            string line;
            while( std::getline(inFile,line) )
            {
                stringstream ss(line);

                string tempID, rendszam, tipus, parkolasKezdete;
                int ID;
                getline(ss,tempID,',');// cout<<"\" "<<tempID<<"\"";
                getline(ss,rendszam,',');// cout<<"\" "<<fname<<"\"";
                getline(ss,tipus,',');// cout<<" \""<<password<<"\"";
                getline(ss,parkolasKezdete,',');// cout<<"\" "<<tempID<<"\"";

                ID = stoi(tempID);

                osszesGepjarmu.push_back(Gepjarmu(ID,rendszam,tipus,parkolasKezdete));
            }
        }

        for(const auto &it : osszesGepjarmu)
        {
            cout << it.getAutoID() << " " << it.getGepjarmuTipus() << " " << it.getRendszam()  << " " << it.getParkolasKezdete() << endl;
        }

        cout << "\n" << "Valassza ki a gepjarmu szamat";
        int melyikAuto;
        cin >> melyikAuto;

        system ("CLS");
        cout << flush;

        return melyikAuto;
}
