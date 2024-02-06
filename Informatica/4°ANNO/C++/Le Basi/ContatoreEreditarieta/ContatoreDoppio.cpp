#include "Contatore.h"
#include <iostream>
using namespace std;

ContatoreDoppio::ContatoreDoppio() : Contatore(){};

void ContatoreDoppio::incrementaDoppio()
{
    inc();
    inc();
}

void ContatoreDoppio::decrementaDoppio()
{
    dec();
    dec();
}
