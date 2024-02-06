#include <iostream>
#include <math>
#include "rettangoloquadrato.h"
using namespace std;

Rettangolo::Rettangolo()
{
    base = 1;
    altezza = 1;
}

Rettangolo::Rettangolo(double base, double altezza)
{
    this->altezza=altezza;
    this->base=base;
}