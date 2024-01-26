/*
Buongallino Alessandro

L'utente scrive 2 numeri e il programma li divide e scrive il resto

Input:2 numeri
Elaborazione:
Output: 1 numero
*/

#include <stdio.h>

int main()
{
    //dichiara le variabili
    int n1, n2;
    int resto;

    //avvaloriamo le variabili
    printf("Scrivi il valore del primo numero\n");
    scanf("%d", &n1);
    printf("Scrivi il valore del secondo numero\n");
    scanf("%d", &n2);

    //assegnamo il risultato
    resto=n1%n2;

    //scriviamo il risultato
    printf("il resto dei due numeri e' %d\n\n", resto);

    //termino il programma
    return 0;
}
