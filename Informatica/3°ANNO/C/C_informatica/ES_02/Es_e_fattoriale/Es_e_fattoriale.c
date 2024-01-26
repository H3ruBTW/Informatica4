/**
\mainpage fattoriale

@brief Si scriva un programma che calcoli il fattoriale di un numero intero N dato dalla tastiera.
       Si ricordi che il fattoriale di un numero n (simbolo n!) viene calcolato con la seguente formula: n! = n ·(n–1)·(n–2)· ... ·2 ·1.

@author Buongallino Alessandro
@date 7/12/22
@version 1.0 inizio della scrittura del programma
**/

#include <stdio.h>

int main()
{
    //dichiarazione delle variabili
    int num;
    int cont;
    int fat=1; //"fattoriale"

    //avvalorazione della variabile num
    printf("Fattoriale\nScrivi un numero\n");
    scanf("%d", &num);

    //moltiplica tutti i numeri alla variabile fat da num a 1
    for (cont=num; cont>=1; cont--)
    {
        fat=fat*cont;
    }

    //in caso se il numero inserito è negativo o uguale a 0
    if(num<=0)
        printf("Al numero %d non e' possibile applicare il fattoriale", num);
    else
        printf("Il fattoriale del numero %d e' %d", num, fat);

    return 0;
}
