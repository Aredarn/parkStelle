#include "parkoloszemely.h"

int ParkoloSzemely::getAutoID() const
{
    return autoID;
}

void ParkoloSzemely::parkolasOsszegKiirat()
{


}

ParkoloSzemely::ParkoloSzemely(string nev,int szID,string jelszo)
{
    this->nev = nev;
    this->szerepKorID = szID;
    this->jelszo = jelszo;
}
