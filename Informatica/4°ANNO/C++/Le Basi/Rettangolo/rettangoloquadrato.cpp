#include "rettangoloquadrato.h"
#include <math>
void Rettangolo::setBase(double base)
{
    l1=base;
    l3=base;
}

void Rettangolo::setAltezza(double altezza)
{
    l2=altezza;
    l4=altezza;
}

void Quadrato::setLati(double l)
{
    l1=l;
    l2=l;
    l3=l;
    l4=l;
}

double Quadrato::calcolaPerimetro()
{
    return (l1*4);
}

double Quadrato::calcolaArea()
{
    return (l1*l1);
}

double Quadrato::calcolaDiagonale()
{
    return hypot(l1,l1);
}
