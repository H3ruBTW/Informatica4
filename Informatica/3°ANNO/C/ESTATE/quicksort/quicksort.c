/** **************************************************************************
*\mainpage
*@brief Riordinamento vettore con l'utilizzo del quicksort
*
*@author Buongallino Alessandro
*@date 01/09/23
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

void random (int []);
void quicksort (int [], int, int);
//funzione per spostare il pivot in una posizione in cui si trova a destra
//i numeri maggiori a esso e a sinistra quelli che sono minori sempre a esso
int partiziona (int [], int, int);
void stampav (int []);

int main()
{
    int v[N];

    srand (time(NULL));

    random(v);

    quicksort(v, 0, N-1);

    stampav(v);

    return 0;
}

void random (int v[])
{
    for(int i=0; i<N; i++)
    {
        v[i]=rand()%30+1;
    }
}

void quicksort (int v[], int sx, int dx)
{
    int q; //indice del pivot

    if (sx<dx)  //controllo dei termini del vettore
    {
        q=partiziona (v, sx, dx);

        //chiamata di "quicksort" per i sottovettori che si trovano a sinistra
        //e a destra del pivot(cioè il sotto vettore con i numeri minori al pivot
        //e il sotto vettore con i numeri maggiori al pivot)
        quicksort(v, sx, q-1); //controllo del vettore di sinistra e si restringe il campo
                               //perchè il punto di fine del vettore diminuisce
        quicksort(v, q+1, dx); //controllo del vettore di destro e si restringe il campo
                               //perchè il punto di inizio del vettore diminuisce
    }
}

int partiziona (int v[], int sx, int dx)
{
    int pivot; //valore del pivot
    int ipivot; //indice del pivot
    int l; //variabile di lavoro

    ipivot=sx;
    pivot = v[ipivot];

    //operazioni per effettuare il partizionamento in due sottovettori per
    //trovare il punto esatto del pivot
    while (sx<dx)
    {
        while(v[sx]<=pivot&&sx<dx) //ricerca di un elemento del vettore di sinistra
        {                          //maggiore al pivot
            sx++;
        }

        while(v[dx]>pivot) //ricerca di un elemento del vettore di destra
        {                  //minore al pivot
            dx--;
        }
        if(sx<dx)
        {
            l=v[sx];
            v[sx]=v[dx];
            v[dx]=l;
        }
    }
    //sposta il pivot in q
    l=v[ipivot];
    v[ipivot]=v[dx];
    v[dx]=l;

    stampav(v);

    return dx;
}

void stampav (int v[])
{
    for(int i=0; i<N; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");
}
