/**
\mainpage binario

@brief Scrivere un programma che converte un numero binario a 8 bit in un numero decimale.
       L’utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit più significativo.
       Il programma dovrà visualizzare il numero decimale corrispondente.
       Suggerimento: per calcolare le potenze di 2 utilizzare la funzione pow includendo la libreria math.h.

@author Buongallino Alessandro
@date 9/12/22
@version 1.0 inizio scrittura del programma
**/

#include <stdio.h>
#include <math.h>

int main()
{
    //avvaloriamo le variabili
    int cifra; //di input
    int pot, qnum; //di lavoro, pot significa potenza, qnum significa quantità di numeri e serve solo per aiutare a ricordare proprio quest'ultima
    int dec; //di output, dec significa decimale

    printf("Convertitore binario (8bit) a decimale, dal bit piu' significativo\n");

    //for che serve a far scrivere i 8 bit e utilizza le potenze tra 7 e 0
    for(pot=7, qnum=0, dec=0; pot>=0; pot--)
    {
        printf("\nQuantita' di bit inseriti = %d\nInserire un bit\n", qnum);
        scanf("%d", &cifra);

        //if che effettua l'operazione in caso la cifra del bit sua 1 e l'incremento di qnum
        if(cifra==1)
        {
            dec+=cifra * pow(2, pot);
            qnum++;
        }
        else
        {
            //if che effettua un incremento della variabile qnum in caso la cifra non sia 1 ma sia uguale a 0
            if(cifra==0)
            {
                qnum++;
            }
            //caso in cui la cifra non sia ne 1 ne 0 quindi il programma indica che è stato inserito un numero sbagliato
            //e effettua un incremento della variabile pot cosicchè, all'inizio del ciclo for viene effettuato "pot--",
            //e quindi la variabile pow rimane invariata dal ciclo scorso
            else
            {
                printf("\nIl numero inserito non e' compreso tra 1 e 0\n");
                pot++;
            }
        }

    }

    printf("Il numero binario inserito, convertito in decimale, e' uguale a %d", dec);

    return 0;
}
