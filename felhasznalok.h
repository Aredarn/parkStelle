#ifndef FELHASZNALOK_H
#define FELHASZNALOK_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Felhasznalok
{
protected:
    string nev;
    int szerepKorID;
    string jelszo;

public:
    Felhasznalok();
    int getSzerepKorID() const;
    const string &getNev() const;
    const string &getJelszo() const;


};

#endif // FELHASZNALOK_H
