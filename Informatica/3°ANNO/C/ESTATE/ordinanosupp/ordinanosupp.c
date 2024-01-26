/** **************************************************************************
*\mainpage
*@brief Riordinamento vettore, a destra i numeri positivi a sinistra i negativi
*       Senza vettore di supporto
*       Range di numeri da -20 a 20
*
*@author Buongallino Alessandro
*@date 28/07/23
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

//carica il vettore con numeri casuali
void caricav (int []);

//scrive il vettore a schermo
void scriviv (int []);

//algoritmo di ordinamento bubblesort
void bubblesort (int []);
int main()
{
    int v[N];

    srand(time(NULL));

    caricav(v);

    bubblesort(v);

    scriviv(v);

    return 0;

}
void caricav (int x[])
{
    for (int y=0; y<N; y++)
    {
        x[y]=rand()%41-20;
    }
}
void scriviv(int x[])
{
    for (int y=0; y<N; y++)
    {
        printf("%4d", x[y]);
    }
}
void bubblesort(int v[])
{
    int i,k;
    int lav;
    for(i = 0; i<N-1; i++)
    {
        for(k = 0; k<N-1-i; k++)
        {
            if(v[k] < v[k+1])
            {
                lav = v[k];
                v[k] = v[k+1];
                v[k+1] = lav;
            }
        }
    }
}


