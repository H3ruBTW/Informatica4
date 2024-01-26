/*
Buongallino ALessandro

L'utente scrive un numero di secondi e il programma li trasforma in ore, minuti e secondi

Input: 1 numero
Elaborazione:
Output: 3 numeri
*/

#include <stdio.h>

int main()
{
    //dichiariamo le variabili
    int secprin; // di input
    int ore, min, sec; // di output

    //avvaloriamo la variabile
    printf("Buongallino Alessandro\nScrivi il numero di secondi\n");
    scanf("%d", &secprin);

    //assegnamo il risultato
    sec=secprin%60; //uso il modulo perchè i secondi sono il resto dei minuti stessa cosa vale anche per i minuti che sono il resto delle ore
    min=secprin/60;
    ore=min/60;
    min=min%60;

    //scriviamo il risultato
    printf("\n\nL'orario in xh/xm/xs e' %dh:%dm:%ds\n\n", ore, min, sec);

    //termino il programma
    return 0;
}
