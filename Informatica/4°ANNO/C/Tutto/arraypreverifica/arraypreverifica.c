/** **************************************************************************
\mainpage array pre verifica
@brief 6 funzioni con utilizzo degli array per esercitazione verifica

@author Buongallino Alessandro
@date 18/09/24
@version 1.0
**/

#include <stdio.h>
#include <stdlib.h>

#define N 100

/*
Funzione che inserisce nell'array, i primi N numeri pari piu grandi di x
*/
void carica (int [], int);
/*
Funzione che scrive a schermo l'array
*/
void scrivi (int []);
/*
Funzione che inserisce x al primo indice e dopo raddoppia, triplica...
*/
void nuovoinserisci (int [], int);
/*
Funzione che conta gli elementi degli indici pari maggiori ad x
*/
int conta (int [], int);
/*
Funzione che da come return l'indice del numero massimo dell'array
*/
int massimo (int []);
/*
Funzione inserisce al contrario nel secondo array il doppio di quello che si trova nel primo
*/
void inserire (int [],int []);
/*
Funzione che scrive il numero del primo array tante volte quante il numero che si trova nel secondo
*/
void stampa (int [], int []);

int main()
{
    int v1[N], v2[N], n, r;

    /*1*/
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    if(n%2==1)
        n++;

    carica(v1, n);
    scrivi(v1);


    /*2
    nuovoinserisci(v1, 11);
    scrivi(v1);
    */

    /*3
    printf("\nInserisci un numero: ");
    scanf("%d", &n);

    r=conta(v1, n);
    printf("\n\n%d", r);
    */

    /*4
    r=massimo(v1);

    printf("\n\n%d", r);
    */

    /*5*/
    inserire(v1,v2);

    printf("\n\n");
    scrivi(v2);

    /*6*/
    stampa(v1, v2);

    return 0;
}

void carica (int v[], int x)
{
    for(int i=0; i<N; i++, x+=2)
    {
        v[i]=x;
    }
}

void scrivi (int v[])
{
    for(int i=0; i<N; i++)
    {
        printf("%d ", v[i]);
    }
}

void nuovoinserisci(int v[], int x)
{
    v[0]=x;

    for(int i=1; i<N; i++)
    {
        v[i]=v[i-1]*(i+1);
    }
}

int conta (int v[], int x)
{
    int c=0;

    for(int i=0; i<N; i+=2)
    {
        if(v[i]>x)
        {
            c++;
        }
    }
    return c;
}

int massimo (int v[])
{
    int max=v[0], ind=0;

    for(int i=1; i<N; i++)
    {
        if(v[i]>max)
        {
            max=v[i];
            ind=i;
        }
    }

     return ind;
}

void inserire(int v1[], int v2[])
{
    for(int i=0; i<N; i++)
    {
        v2[N-1-i]=v1[i]*2;
    }
}

void stampa (int v1[], int v2[])
{
    printf("\n\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<v2[i]; j++)
        {
            printf("%d ", v1[i]);
        }
        printf("\n");
    }
}
