/*
Buongallino ALessandro

L'utente scrive un numero tar 1000 e 9999 e viene come output con le cifre staccate di uno spazio
Input: 1 numero
Elaborazione:
Output: 4 numeri
*/

#include <stdio.h>

int main() {
//dichiariamo le variabili
int numprin;// di input
int n1, n2, n3, n4;// di output

    //avvaloriamo la variabili numprin
    printf("Scrivi un numero tra 1000 e 9999");
    scanf("%d", &numprin);

        //assegnamo il risultato
        n1=numprin%1000;
        n2=numprin%100;
        n3=numprin%10;
        n4=numprin%1;

}
