#ifndef ERTESITES_H
#define ERTESITES_H
#include <iostream>

using namespace std;

class Ertesites
{
    int ertesitesID;
    string felhasznalotol;
    string felhasznalonak;
    string szoveg;
    string ertesitesTipus;

public:
    Ertesites(int ertesitesID, const string &felhasznalotol, const string &felhasznalonak, const string &szoveg, const string &ertesitesTipus);

};

#endif // ERTESITES_H
