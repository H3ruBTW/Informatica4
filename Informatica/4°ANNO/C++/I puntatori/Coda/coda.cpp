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
    if(N_elem % N == 0 && N_elem != 0)
    {
        fine = 0;
        inizio = 1;
        d = 1;
    }

    if(inizio == N)
        inizio = 0;

    p[fine] = num;
    fine++;
    N_elem++;

    if(d)
        inizio++;
}

void Coda::pop()
{

}

int Coda::top()
{
    if(!ifEmpty())
    {
        return p[inizio];
    }
    else
    {
        cout << "ERR 03 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO" << endl;
    }
}


bool Coda::ifEmpty()
{
    if(fine==0)
        return true;
    else
        return false;
}

bool Coda::ifFull()
{
    if(fine==N)
        return true;
    else
        return false;
}