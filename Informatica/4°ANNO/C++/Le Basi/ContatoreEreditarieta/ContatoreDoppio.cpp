#include "Contatore.h"
#include <iostream>
using namespace std;

ContatoreDoppio::ContatoreDoppio() : Contatore(){};

void ContatoreDoppio::inc()
{
    Contatore::inc();
    Contatore::inc();
}

void ContatoreDoppio::dec()
{
    Contatore::dec();
    Contatore::dec();
}
