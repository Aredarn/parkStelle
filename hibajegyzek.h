#ifndef HIBAJEGYZEK_H
#define HIBAJEGYZEK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>
#include "gepjarmu.h"
#include <ctime>

class Hibajegyzek
{
    string hibanev;
public:
    Hibajegyzek();

    void ujhiba(string hiba);

};

#endif // HIBAJEGYZEK_H
