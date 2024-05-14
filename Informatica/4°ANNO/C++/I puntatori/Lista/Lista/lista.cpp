#include "lista.h"
#include <iostream>

using namespace std:

lista::lista()
{
    L = new s_nodo;
    cin >> L->info;
    L->next = NULL:
}

void lista::insInTesta(int n)
{
    s_nodo* p = new s_nodo;

    p->next = L;
    L=p;
    L->info = n;
}

void lista::cancInTesta()
{
    if(!isEmpty())
    {
        s_nodo* p = L;
        L = L->next;
        free(p);
    }
    else
    {
        cout << "Errore" << endl;
    }
}

bool lista::isEmpty()
{
    if(L==NULL) return true;
    else return false;
}

