#ifndef GEPJARMUVEK_H
#define GEPJARMUVEK_H
#include "gepjarmu.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Gepjarmuvek
{
    vector<Gepjarmu> osszesGepjarmu;
public:
    Gepjarmuvek() {}
    int listazGepJarmuvek();

};

#endif // GEPJARMUVEK_H
