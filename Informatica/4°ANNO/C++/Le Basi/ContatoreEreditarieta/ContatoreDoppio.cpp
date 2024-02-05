#include "Contatore.h"
#include <iostream>
using namespace std;

ContatoreDoppio::ContatoreDoppio()
{
    Contatore();
}

void ContatoreDoppio::IncrementaDoppio()
{
    inc();
    inc();
}