#ifndef PARKOLOOR_H
#define PARKOLOOR_H
#include "felhasznalok.h"
#include "gepjarmu.h"
#include "gepjarmuvek.h"
#include <iostream>

using namespace std;

class Parkoloor : public Felhasznalok
{

public:
    Parkoloor(string nev,int szID,string jelszo);
    void GepjarmuListaz();
};

#endif // PARKOLOOR_H
