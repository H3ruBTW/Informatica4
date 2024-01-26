/**
\mainpage medianum

@brief Si scriva un programma per calcolare la media aritmetica di una serie di numeri inseriti da tastiera.
L’introduzione del valore 0 indica il termine del caricamento dei dati.

@author Buongallino Alessandro
@date 31/11/22
@version 1.0 inizio scrittura programma
**/

#include <stdio.h>

int main ()
{
    //dichiariaro le variabile
    int num;
    int somman=0, cont;
    float media=0;

    //for che conta i numeri inseriti e effettua la somma per effetuare la media
    for (cont=-1; num!=0; cont++)
    {
        printf("Media\nScrivi un numero\nScrivere la cifra 0 se si vuole uscire dal programma\n");
        scanf("%d", &num);
        somman+=num;
    }
    //if che se in caso la somma è diversa da zero effettua la media
    //invece se questo è falso significa che i numeri che sono stati scritti dentro sono solo lo zero
    if (somman!=0)
    {
        media=(float)somman/(float)cont;
        printf("La media e' %f", media);
    }
    else
        printf("Sei uscito senza scrivere numeri.");

    return 0;
}
