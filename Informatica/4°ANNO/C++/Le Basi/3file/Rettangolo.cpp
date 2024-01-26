#include "Rettangolo.h"
#include <math.h>
#include <iostream>
using namespace std;

Rettangolo::Rettangolo()
{
    altezza=0;
    base=0;
}

Rettangolo::Rettangolo(double n)
{
    altezza=n;
    base=n;
}

Rettangolo::Rettangolo(double altezza, double base)
{
    this->altezza=altezza;
    this->base=base;
}

void Rettangolo::setAltezza(double altezza)
{
    this->altezza=altezza;
}

void Rettangolo::setBase(double base)
{
    this->base=base;
}

double Rettangolo::getAltezza()
{
    return altezza;
}

double Rettangolo::getBase()
{
    return base;
}

double Rettangolo::calcoloPerimetro()
{
    return (altezza+base)*2;
}

double Rettangolo::calcoloArea()
{
    return base*altezza;
}

double Rettangolo::calcolaDiagonale()
{
    return sqrt(base*base+altezza*altezza);
}