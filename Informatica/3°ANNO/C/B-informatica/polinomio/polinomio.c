/**
\mainpage polinomio

@brief risoluzione del polinomio (-ax^3+bx^2-c^x+d)
il programma accetta solo numeri interi


@author Buongallino Alessandro
@date 7/10/2022
@version 1.0 Inizio della scrittura del programma
*/

#include <stdio.h>
#include <math.h>

int main()
{
    //dichiariamo le variabili
    int a, b, c, d, x; //input
    int ris; //output

    //avvaloriamo le variabili
    printf("Polinomio\n\n-ax^3+bx^2-c^x+d\n\nScrivi il valore di a\n");
    scanf ("%d", &a);
    printf("\nScrivi il valore di b\n");
    scanf ("%d", &b);
    printf("\nScrivi il valore di c\n");
    scanf ("%d", &c);
    printf("\nScrivi il valore di d\n");
    scanf ("%d", &d);
    printf("\nScrivi il valore di x\n");
    scanf ("%d", &x);

    //assegnamo il risultato
    ris=(-a)*pow(x, 3);
    ris=ris+b*pow(x, 2);
    ris=ris-c*x+d;

    //scriviamo il risultato all'utente
    printf("\n\nIl risultato e' %d", ris);

    //termino il programma
    return 0;
}
