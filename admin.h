#ifndef ADMIN_H
#define ADMIN_H
#include "felhasznalok.h"
#include "gepjarmu.h"
#include <iostream>
using namespace std;

class Admin : public Felhasznalok
{

public:
    Admin(string nev,int szID,string jelszo);
};

#endif // ADMIN_H
