       /**
\mainpage numeriseparati

@brief L'utente scrive un numero tra 100 e 999 e il programma divide di uno spazio le cifre
il programma accetta solo numeri interi


@author Buongallino Alessandro
@date 7/10/2022
@version 1.0 Inizio della scrittura del programma
*/

#include <stdio.h>

int main()
{
    //dichiariamo le variabili
    int n1; //di input
    int cif1, cif2, cif3; // di output

    //avvaloriamo la variabile
    printf("Scrivi un numero con un valore di 3 cifre (esempio 123)\n");
    scanf("%d", &n1);

    //assegnamo la variabile per scrivere poi le tre cifre distaccate
    cif1=n1/100;
    cif2=(n1-(cif1*100))/10;
    cif3=n1-((cif1*100)+(cif2*10));
    if (cif2<0)
        {
        cif2=cif2*(-1);
        }
    else
        {}
    if (cif3<0)
        {
        cif3=cif3*(-1);
        }
    else
        {}

    //scriviamo le cifre separate all'utente
    printf("\n\nil tuo numero e' %d %d %d", cif1, cif2, cif3);

    //termino il programma
    return 0;
}
