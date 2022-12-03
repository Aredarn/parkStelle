#include "gepjarmu.h"

const string &Gepjarmu::getParkolasKezdete() const
{
    return parkolasKezdete;
}

const string &Gepjarmu::getGepjarmuTipus() const
{
    return gepjarmuTipus;
}

const string &Gepjarmu::getRendszam() const
{
    return rendszam;
}

int Gepjarmu::getAutoID() const
{
    return autoID;
}


Gepjarmu::Gepjarmu(int autoID, const string &rendszam, const string &gepjarmuTipus, const string &parkolasKezdete) : autoID(autoID),
    rendszam(rendszam),
    gepjarmuTipus(gepjarmuTipus),
    parkolasKezdete(parkolasKezdete)
{

}
