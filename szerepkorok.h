#ifndef SZEREPKOROK_H
#define SZEREPKOROK_H

#include <string>

using namespace std;

class SzerepKorok
{

    list<string> SzerepkorTipusok = ("ParkoloSzemely", "Parkoloor","Admin");

public:
    SzerepKorok();
    string getSzerepkorID(int id)
    {
           return SzerepkorTipusok[id-1];
    }
};

#endif // SZEREPKOROK_H
