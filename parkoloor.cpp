#include "parkoloor.h"

Parkoloor::Parkoloor(string nev, int szID, string jelszo)
{
    this->nev = nev;
    this->szerepKorID = szID;
    this->jelszo = jelszo;
}

void Parkoloor::GepjarmuListaz()
{
    Gepjarmuvek hozzaFeresipont;
    hozzaFeresipont.listazGepJarmuvek();
}
