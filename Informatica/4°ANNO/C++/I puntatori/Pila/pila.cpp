#include "pila.h"
#include <iostream>
using namespace std;

Pila::Pila(int N)
{
    this.N = N;
    p = new int[N]; 
}

void Pila::push(int num)
{
    if(!ifFull())
    {
        *p = num;
        p++;
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
        *p = NULL;
        p--;
        fine--;
        cout << "L'elemento e' stato correttamente eliminato" << endl;
    }
    else
    {
        cout << "ERR 02 - L'ARRAY E' VUOTO - IMPOSSIBILE ELIMINARE L'ELEMENTO" << endl;
    }
}

void Pila::top()
{
    if(!ifEmpty())
    {

        return *p[--];
    }
    else
    {
        cout << "ERR 03 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO" << endl;
    }
}