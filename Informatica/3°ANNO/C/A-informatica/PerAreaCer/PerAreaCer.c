/*
Buongallino Alessandro

Dato l'input del raggio del cerchio viene dato come output la sua area e la sua circonferenza

Input: 1 numero intero
Elaboraxione: Calcoli per il cerchio
Output: 2 numeri interi
*/

#include <stdio.h>
#include <math.h>

int main() {
//dichiariamo le variabili
float r;//input
float pi=3.1415;//di lavoro
float cir, area;//output

    printf("Cerchio\nScrivere il raggio\n");
    scanf("%f", &r);

    //assegnamo l'area e la circonferenza
    r= pow (r, 2);
    area= r * pi;
    cir= 2 * pi * r;
    r= sqrt(r);

    //scriviamo i risultati
    printf("Il cerchio con raggio %f ha l'area di %f e la circonferenza di %f", r, area, cir);

    //termino il programma
    return 0;
}
