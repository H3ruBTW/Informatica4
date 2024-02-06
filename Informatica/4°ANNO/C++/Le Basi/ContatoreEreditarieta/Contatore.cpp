#include "Contatore.h"
#include <iostream>
using namespace std;
/*
Contatore::Contatore()
{
    valore = 0;
    passo = 1;
}
Contatore::Contatore(int valore)
{
    this->valore = valore;
    passo = 1;
}
Contatore::Contatore(int valore, int passo)
{
    this->passo = passo;
    this->valore = valore;
}
*/
Contatore::~Contatore()
{
    cout << "Hai utilizzato il distruttore su un oggetto Contatore" << endl;
}

void Contatore::setValore(int valore)
{
    this->valore = valore;
}
void Contatore::setPasso(int passo)
{
    this->passo = passo;
}

int Contatore::getValore()
{
    return valore;
}
int Contatore::getPasso()
{
    return passo;
}

void Contatore::reset()
{
    cout << "Il valore e' stato resettato a 0";
    valore = 0;
}

void Contatore::inc()
{
    cout << endl
         << "Incremento in corso..." << endl;
    valore += passo;
    // cout << endl << valore;
}

void Contatore::dec()
{
    cout << endl
         << "Decremento in corso..." << endl;
    valore -= passo;
    // cout << valore;
}
