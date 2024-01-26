#include <stdio.h>
#define N 10

int main()
{
    int vettore[N];

    int cont, ris=0;

    for(cont=0;cont<10;cont++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &vettore[cont]);
    }

    for(cont=0;cont<10;cont++)
    {
        ris+=vettore[cont];
    }

    for(cont=0;cont<10;cont++)
    {
        printf("%d\n", vettore[cont]);
    }

    printf("Il risultato e' %d", ris);
    return 0;
}
