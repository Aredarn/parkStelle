#ifndef PARKOLOSZEMELY_H
#define PARKOLOSZEMELY_H
#include "felhasznalok.h"
#include "gepjarmu.h"
#include <iostream>

using namespace std;

class ParkoloSzemely : public Felhasznalok
{
    int autoID;
public:
    ParkoloSzemely(string nev,int szID,string jelszo);

};

#endif // PARKOLOSZEMELY_H
