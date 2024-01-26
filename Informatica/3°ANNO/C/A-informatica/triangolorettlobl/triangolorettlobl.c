/*
Buongallino Alessandro

Trovare il perimetro e l'area con il lato obliquo e uno dei cateti

Input:2 numeri
Elaborazione: Formule per trovare il perimetro e l'area
Output: 2 numeri
*/

#include <stdio.h>
#include <math.h>

int main() {
//dichiarare le variabili
float cat1, ipo; //di input
float per, area; //di output
float cat2; //di lavoro

    //assegnare le variabili di input
    printf("Scrivere il valore del lato obliquo\n");
    scanf("%f", &ipo);
    printf("Scrivere il valore del cateto\n");
    scanf("%f", &cat1);

    //assegnamo le variabili di lavoro
    cat2=sqrt (pow (ipo, 2) - pow (cat1, 2));

    //assegnamo i risultati
    per=cat1 + cat2 + ipo;
    area=(cat1 * cat2)/2;

    //scriviamo il risultato
    printf("Il triangolo con catetto %.5f e %.5f ed ipotunusa %.5f ha il perimetro di %.5f e l'area di %.5f", cat1, cat2, ipo, per, area);

    //termino il programma
    return 0;
}
