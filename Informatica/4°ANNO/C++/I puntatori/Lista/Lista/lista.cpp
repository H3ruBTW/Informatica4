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

void lista::insInCoda(int n)
{
    if(isEmpty())
    {
        L = new s_nodo;
        L->info = n;
        L->next = NULL:
    }
    else
    {
        s_nodo* p = L, p2 = new s_nodo;
    }
}

void lista::cancInCoda()
{
    if(!isEmpty())
    {
        if(L->next==NULL)
        {
            L = L->next;
            free(p);
        }
        else
        {
            s_nodo* p2 = L->next;
            for(;p2->next != NULL; p2 = p2->next);
            p->next=NULL;
            free(p2);
        }
    }
    else
    {
        cout << "Errore" << endl;
    }
}

void lista::stampaLista()
{
    s_nodo* p;

    cout << "Informazioni: "

    for(p=L; p!=NULL; p = p->next)
    {
        cout << p->info << " ";
    }

    cout << endl;
}

bool lista::isEmpty()
{
    if(L==NULL) return true;
    else return false;
}

