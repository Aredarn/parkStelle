#ifndef GEPJARMU_H
#define GEPJARMU_H
#include <iostream>
#include "gepjarmuvek.h"
using namespace std;

class Gepjarmu
{
    int autoID;
    string rendszam;
    string gepjarmuTipus;
    string parkolasKezdete;

public:
    Gepjarmu(int autoID, const string &rendszam, const string &gepjarmuTipus, const string &parkolasKezdete);
    const string &getParkolasKezdete() const;
    const string &getGepjarmuTipus() const;
    const string &getRendszam() const;
    int getAutoID() const;
};

#endif // GEPJARMU_H
