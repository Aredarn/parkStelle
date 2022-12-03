#ifndef FELHASZNALOK_H
#define FELHASZNALOK_H
#include <iostream>

using namespace std;

class Felhasznalok
{
protected:
    string nev;
    int szerepKorID;
    string jelszo;

public:
    int getSzerepKorID() const;
};

#endif // FELHASZNALOK_H
