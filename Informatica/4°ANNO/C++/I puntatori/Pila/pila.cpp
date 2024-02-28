#include "pila.h"
#include <iostream>
using namespace std;

Pila::Pila()
{
    N = 10;
    p = new int[N];
}

Pila::Pila(int N)
{
    this->N = N;
    p = new int[N]; 
}

void Pila::push(int num)
{
    if(!ifFull())
    {
        p[fine] = num;
        fine++;
        cout << "L'elemento è stato correttamente inserito" << endl;
    }
    else
    {
        cout << "ERR 01 - L'ARRAY E' PIENO - IMPOSSIBILE INSERIRE L'ELEMENTO" << endl;
    }
}

void Pila::pop()
{
    if(!ifEmpty())
    {
        fine--;
        p[fine] = 0;        
        cout << "L'elemento e' stato correttamente eliminato" << endl;
    }
    else
    {
        cout << "ERR 02 - L'ARRAY E' VUOTO - IMPOSSIBILE ELIMINARE L'ELEMENTO" << endl;
    }
}

int Pila::top()
{
    if(!ifEmpty())
    {
        cout << "Elemento e' stato preso con successo" << endl;
        return p[fine--];
    }
    else
    {
        cout << "ERR 03 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO" << endl;
    }
}

bool Pila::ifEmpty()
{
    if(fine==0)
        return true;
    else
        return false;
}

bool Pila::ifFull()
{
    if(fine==N)
        return true;
    else
        return false;
}