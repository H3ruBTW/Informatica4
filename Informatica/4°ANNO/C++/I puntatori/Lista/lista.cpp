#include <iostream>
using namespace std;

struct s_nodo
{
    int info;
    struct s_nodo *next;
}typedef s_nodo;


class Lista {
private:
    s_nodo *p, *l;
    int size=0;
public:
    Lista()
    {
        l = new s_nodo;
        l->next = NULL;
        l->info = NULL;

        size++;

        for(int i=1; i<5; i++)
        {
            p = new s_nodo;
            p->next = l;
            p->info = NULL;

            size++;

            l = p;
        }
    }

    void push(int info)
    {
        if(p != NULL)
        {
            p->info = info;

            p = p->next;

            cout << "Elemento inserito" << endl;
        }
        else
        {
            cout << "ERR 01 - IL PUNTATORE SI TROVA NEL NULLA, LISTA PIENA" << endl;
        }
    }

    void pop()
    {
        if(l != NULL)
        {
            s_nodo *pp = l;
            l = l->next;
            free(pp);

            size--;

            cout << "Elemento eliminato" << endl;
        }
        else
        {
            cout << "ERR 02 - IL PUNTATORE SI TROVA NEL NULLA, LISTA VUOTA" << endl;
        }
    }

    void top()
    {
        if(l != NULL)
        {
            cout << "Elemento top: " << l->info << endl;
        }
        else
        {
            cout << "ERR 03 - IL PUNTATORE SI TROVA NEL NULLA, LISTA VUOTA" << endl;
        }
    }

    void aggiungiInLista (int pos=0)
    {
        s_nodo *pp = l;

        if(size == 0)
        {
            l = new s_nodo;

            l->next = NULL;
            l->info = NULL;
            size=1;
        }
        else if(pos > 0 && pos < size)
        {
            if(pos==0)
            {
                p = new s_nodo;

                p->next = l;
                p->info = NULL;

                l = p;

            }
            else
            {
                for(int i=0; i<pos-1; i++)
                {
                    pp = pp->next;
                }                      

                p = new s_nodo;

                p->next = pp->next;
                pp->next = p;
            }
            
        }
    }

    void caricaListaRand()
    {
        s_nodo *pp = l;

        cout << "Carica" << endl;

        while(pp != NULL)
        {
            pp->info = rand()%10+1;
            cout << "Informazione Caricata: " << pp->info << endl;
            pp = pp->next;
        }
    }

    void stampaLista()
    {
        s_nodo *pp = l;

        cout << "Stampa" << endl;

        while(pp != NULL)
        {
            cout << "Informazione: " << pp->info << endl;
            pp = pp->next;
        }
    }
};

int main(){

    Lista l1;

    /*l1.caricaListaRand();
    cout << endl;
    l1.stampaLista();*/

    return 0;
}