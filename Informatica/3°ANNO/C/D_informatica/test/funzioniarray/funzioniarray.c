/**
* File di funzioni per Vettori
**/

#include <stdio.h>
#include <stdlib.h>

#define N 0.5

int menu(void);

/**
* Funzione di carica vettore
**/
void carica (int [], int);

/**
* Funzione che scrive i valori di un vettore
**/
void scrivi (int [], int);

/**
* Funzione che riordina i valori di un vettore
**/
void riordina (int [], int);

int main()
{
    int n;

    printf("Funzioni dei vettori\nQuanti numeri da scrivere dentro il vettore: ");
    scanf("%d", &n);

    printf("\n");

    int vet[n];

    carica(vet, n);

    system("cls");

    riordina(vet, n);

    scrivi(vet, n);

    return 0;
}
void carica(int v[], int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        printf("Inserisci il valore del vettore %d: ", cont);
        scanf("%d", &v[cont]);
    }
}
void riordina(int v[], int x)
{
    int n1, n2, lav;

    for(n1=0; n1<x; n1++)
    {
        for(n2=n1+1; n2<x; n2++)
        {
            if(v[n1]>v[n2])
            {
                lav=v[n1];
                v[n1]=v[n2];
                v[n2]=lav;
            }
        }
    }
}
void scrivi(int v[], int x)
{
    int cont;

    for(cont=0; cont<x; cont++)
    {
        printf("%d\n", v[cont]);
    }
}
