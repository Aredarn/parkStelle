#include "felhasznalok.h"

const string &Felhasznalok::getNev() const
{
    return nev;
}

const string &Felhasznalok::getJelszo() const
{
    return jelszo;
}

Felhasznalok::Felhasznalok()
{

}


int Felhasznalok::getSzerepKorID() const
{
    return szerepKorID;
}
