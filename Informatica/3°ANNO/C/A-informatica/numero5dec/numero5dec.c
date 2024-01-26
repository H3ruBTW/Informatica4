/*
Buongallino Alessandro

Programma che scrive le ultime cinque decimali

Input:1 numero intero
Elaborazione: Nessuno
Output: 1 numero intero
*/

#include <stdio.h>

int main() {
//Dichiariamo le variabili
float num1; //di input e output

    //assegnamo la variabile
    printf("Scrivere un numero\n");
    scanf("%f", &num1);

    //scriviamo il risultato
    printf("Il numero che scritto e' %.5f", num1);

    //termino il programma
    return 0;
}
