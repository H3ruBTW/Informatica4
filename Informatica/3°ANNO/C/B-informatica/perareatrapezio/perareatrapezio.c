/**
\mainpage perareatrapezio

@brief l'utente scrive il valore delle basi e dell'altezza e il programma trova l'area e il perimetro
il programma accetta tutti i tipi di numeri


@author Buongallino Alessandro
@date 7/10/2022
@version 1.0 Inizio della scrittura del programma
*/

#include <stdio.h>
#include <math.h>

int main ()
{
    //dichiarare le variabili
    float basmin, basmag, alt; //di input
    float latobl; //di lavoro
    float area, per; //di output

    //avvaloriamo le variabili
    printf("Area del trapezio\nScrivi il valore della base minore\n");
    scanf("%f", &basmin);
    printf("Scrivi il valore della base maggiore\n");
    scanf("%f", &basmag);
    printf("Scrivi il valore dell'altezza\n");
    scanf("%f", &alt);

    //assegnamo il risulato
    area=(basmin+basmag)*alt/2;
    latobl= sqrt(pow (basmag-basmin, 2)+ pow(alt, 2));
    per=(latobl*2)+basmin+basmag;

    //scriviamo il risultato all'utente
    printf("\nIl trapezio ha l'area di %f e il perimetro di %f", area, per);

    //termino il programma
    return 0;
}
