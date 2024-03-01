#include "coda.h"
#include <iostream>
using namespace std;

Coda::Coda()
{
    N = 10;
    p = new int[N];
}

Coda::Coda(int N)
{
    this->N = N;
    p = new int[N];
}

void Coda::push(int num)
{
    if(ifEmpty())
    {
        inizio = 0;
        fine = 0;
    }
    else
    {
        fine = (fine + 1) % N;

        if(fine == inizio)
        {
            inizio = (inizio+1) % N;
        }
    }

    p[fine] = num;
    cout << "L'elemento è stato correttamente inserito" << endl;
}

void Coda::pop()
{
    if(!ifEmpty())
    {
        if(inizio == fine)
        {
            inizio = -1;
            fine = -1;
        }
        else
        {
            inizio = (inizio + 1) % N;
        }

        cout << "L'elemento e' stato poppato" << endl;
    }
    else
    {
        cout << "ERR 01 - L'ARRAY E' VUOTO - IMPOSSIBILE ELIMINARE L'ELEMENTO" << endl;
    }
}

int Coda::top()
{
    if(!ifEmpty())
    {
        return p[inizio];
    }
    else
    {
        cout << "ERR 02 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO" << endl;
        return -1;
    }
}


bool Coda::ifEmpty()
{
    if(inizio == -1 && fine == -1)
        return true;
    else
        return false;
}
