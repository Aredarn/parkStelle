#ifndef GEPJARMU_H
#define GEPJARMU_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <istream>
using namespace std;

class Gepjarmu
{

private:

     // Tulajdonságok

    int felhasznaloID;
    int autoID;
    string rendszam;
    string gepjarmuTipus;
    string parkolasKezdete;
    int hosszabb;

public:

    // Konstruktor

    Gepjarmu(int _felhasznaloID, int _autoID, string _rendszam, string _gepjarmuTipus, string _parkolasKezdete, int hosszabb = 0) {

        felhasznaloID   = _felhasznaloID;
        autoID          = _autoID;
        rendszam        = _rendszam;
        gepjarmuTipus   = _gepjarmuTipus;
        parkolasKezdete = _parkolasKezdete;
        this->hosszabb = hosszabb;
    }

     int elteltPercekKezdetOta()
     {
         //Megkapja mikor kezdte a parkolást
         int  kezdet = getParkolasKezdeteSZAM();
         int kMin = (kezdet/60)%60;
         int kHour = ((kezdet/3600)%60);


         //Aktuális idő
         time_t aktualisIdo = time(0);
         int aMin = (aktualisIdo/60)%60;
         int aHour = (aktualisIdo/3600)%60 +1;


         //Kiszámolja hány perc telt el a 2 érték közt
         //Figyelembe veszi az időeltolódást is
         int minutesPassed;


         minutesPassed = ((aHour-kHour) -1)*60 + (aMin-kMin);

         return minutesPassed;
     }

     // GETTER - FelhasznaloID

     int getFelhasznaloID() {

         return felhasznaloID;

     }

     // GETTER - Autó ID

     int getAutoID() {

         return autoID;

     }

     // GETTER - Rendszám

     string getRendszam() {

         return rendszam;

     }

     // GETTER - Gepjármű típusa

     string getGepjarmuTipus() {

         return gepjarmuTipus;

     }

     // GETTER - Parkolás kezdete

     string getParkolas() {

         return parkolasKezdete;

     }

     int getHosszabb()
     {
           return hosszabb;
     }

     void setHosszabb(int t)
     {

         if(hosszabb != 0)
         {
             cout << "Mar hosszabbitott parkolast." << endl;
         }
         else
             {
             ifstream fajl;
             //string fajlNev = "J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt";
             string fajlNev = "gepjarmuvek.txt";
             vector<Gepjarmu> gepjarmuvek;

             // Fájl megnyitása

             fajl.open(fajlNev.c_str());

             // Fájl sikeres megnyitásának a vizsgálata


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


                 gepjarmuvek.push_back(Gepjarmu(stoi(felhasznaloID), stoi(autoID), rendszam, gepjarmuTipus, parkolasKezdete, stoi(hosszabitva)));

            }

             gepjarmuvek[autoID -1].setHossz(t);
             setHossz(t);

             fajl.close();
             ofstream ofs;
             //ofs.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
             ofs.open("gepjarmuvek.txt", std::ofstream::out | std::ofstream::trunc);
             ofs.close();

             // Kiválasztjuk a legnagyobb autó ID, majd azt növelve megkapjuk az új autó ID -ját

             ofstream file;
             //file.open("J:/parkolohaz/Parkolohaz_V1.0/Parkolohaz V1.0/build-parkolohaz-Desktop_Qt_6_4_1_MinGW_64_bit-Debug/gepjarmuvek.txt", ios_base::app);
             file.open("gepjarmuvek.txt", ios_base::app);

             for (unsigned int i = 0; i < gepjarmuvek.size(); i++) {
                file << gepjarmuvek[i].getFelhasznaloID() <<
                        ";" << gepjarmuvek[i].getRendszam() <<
                        ";" << gepjarmuvek[i].getGepjarmuTipus()<<
                        ";" << gepjarmuvek[i].getParkolasKezdeteSZAM() <<
                        ";" << to_string(gepjarmuvek[i].getAutoID()) <<
                        ";" << to_string(gepjarmuvek[i].getHosszabb()) << "\n";
             }

             file.close();

             cout << "Parkolasa meghosszabitva " << t << " perccel"<< endl;

        }
     }

     void setHossz(int a)
     {
         hosszabb = a;
     }

     string getParkolasKezdete() {

         int x = stoi(parkolasKezdete);
         int h = ((x/ 3600) % 24) + 1;
         int m = (x/60) % 60;

         string ho = to_string(h);
         string mo = to_string(m);

         string time = ho + " : " + mo;

         return time;

     }

     string getParkolasVege()
     {

         int x = getParkolasKezdeteSZAM();
         int h = ((x/ 3600) % 24) + 2;
         int m = ((x/60) % 60) + hosszabb;

         string ho = to_string(h);
         string mo = to_string(m);

         string time = ho + " : " + mo;

         return time;


     }



     void setRendszam(string ujRendszam){
                 rendszam = ujRendszam;
             }

      void setGepjarmuTipus(string ujTipus){
                 gepjarmuTipus = ujTipus;
      }


     int getParkolasKezdeteSZAM() {
         return stoi(parkolasKezdete);
     }

};

#endif // GEPJARMU_H
