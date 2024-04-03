#include <iostream>
using namespace std;

struct s_nodo
{
    int info;
    struct s_nodo *next;
}typedef s_nodo;


class ListaCoda {
private:
    s_nodo *p, *l;
    int size=0;
public:
    ListaCoda(int n=1)
    {
        l = new s_nodo;
        l->next = NULL;
        l->info = NULL;

        size++;

        for(int i=1; i<n; i++)
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
        if(l != NULL && p != NULL)
        {
            p->info = info;

            p = p->next;

            cout << "Elemento inserito" << endl;
        }
        else
        {
            s_nodo *pp;
            

            if(l == NULL)
            {
                pp = new s_nodo;

                l = pp;
                l->next = NULL;
                l->info = NULL;
                p = l;
            }
            else
            {   
                pp = l;
                while(pp->next != NULL)
                {
                    pp = pp->next;
                }
                
                p = new s_nodo;

                pp->next = p;
                p->next = NULL;
                p->info = info;
            }

            size++;
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
            cout << "ERR 02 - IL PUNTATORE SI TROVA NEL NULLA, ListaCoda VUOTA" << endl;
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
            cout << "ERR 03 - IL PUNTATORE SI TROVA NEL NULLA, ListaCoda VUOTA" << endl;
        }
    }

    void aggiungiInListaCoda (int pos=0)
    {
        s_nodo *pp = l;

        if(l == NULL)
        {
            l = new s_nodo;

            l->next = NULL;
            l->info = NULL;
            size=1;
        }
        else if(pos >= 0 && pos <= trovaSize())
        {
            if(pos==0)
            {
                s_nodo *pp = new s_nodo;

                pp->next = l;
                pp->info = NULL;

                l = pp;

                size++;
            }
            else
            {
                for(int i=0; i<pos-1; i++)
                {
                    pp = pp->next;
                }                      

                s_nodo *ppp = new s_nodo;

                ppp->next = pp->next;
                pp->next = ppp;

                size++;
            }
        }
        else
        {
            cout << endl
                 << "Non è possibile inserire un nodo li'!" << endl;
        }
    }

    void eliminaInListaCoda(int pos=0)
    {
        if(pos>=0 && pos<=getSize()-1)
        {
            if(getSize()==1)
            {
                pop();
            }
            else
            {
                s_nodo *pp = l;
                s_nodo *ppp = l;
                
                ppp = ppp->next;

                for(int i=1; i<pos; i++)
                {
                    pp = pp->next;
                    ppp = ppp->next;
                }

                pp->next = ppp->next;

                free(ppp);

                size--;
            }  
        }
        else
        {
            cout << "ERR - La posizione non esiste" << endl;
        }
    }

    void caricaListaCodaRand()
    {
        p = l;

        cout << "Carica" << endl;

        while(p != NULL)
        {
            p->info = rand()%10+1;
            cout << "Informazione Caricata: " << p->info << endl;
            p = p->next;
        }
    }

    void stampaListaCoda()
    {
        s_nodo *pp = l;

        cout << "Stampa" << endl;

        while(pp != NULL)
        {
            cout << "Informazione: " << pp->info << endl;
            pp = pp->next;
        }
    }

    int getSize()
    {
        return size;
    }

    int trovaSize()
    {
        s_nodo *pp = new s_nodo;
        pp = l;
        int SIZE = 0;

        while (pp != NULL)
        {
            SIZE++;
            pp = pp->next;
        }
        
        return SIZE;
    }
};

int menu(ListaCoda);

int main(){

    ListaCoda l1;

    int d, n;

    do
    {
        switch (menu(l1))
        {
        case 1:
            cout << endl
                 << "Inserire il numero con cui fare push: ";
            cin >> n;
            l1.push(n);
            break;
        
        case 2:
            l1.pop();
            break;
        
        case 3:
            l1.top();
            break;

        case 4:
            if(l1.getSize()==0)
            {
                l1.aggiungiInListaCoda();
            }
            else
            {
                cout << endl 
                     << "Scegli la posizione in cui mettere il nuovo nodo: ";
                cin >> n;
                l1.aggiungiInListaCoda(n);
            }
            
            break;
        
        case 5:
            l1.stampaListaCoda();
            break;
        
        case 6:
            l1.caricaListaCodaRand();
            break;

        case 7:
            if(l1.getSize()==0)
            {
                l1.eliminaInListaCoda();
            }
            else
            {
                cout << endl 
                     << "Scegli la posizione dove vuoi rimuovere un nodo: ";
                cin >> n;
                l1.eliminaInListaCoda(n);
            }

        default:
            cout << endl
                 << "Hai inserito una scelta non esistente"
                 << endl;
            break;
        }
    } while (d!=0);
    

    return 0;
}

int menu(ListaCoda l1){
    int sce;

    cout << endl
         << "Grandezza ListaCoda: " << l1.getSize() << endl
         << "1 - PUSH" << endl
         << "2 - POP" << endl
         << "3 - TOP" << endl
         << "4 - Aggiungi in ListaCoda un nodo" << endl
         << "5 - Stampa tutta la ListaCoda" << endl
         << "6 - Carica Random la ListaCoda" << endl
         << "7 - Elimina in ListaCoda un nodo" << endl
         << "Inserire la scelta: ";

    cin >> sce;

    return sce;
}