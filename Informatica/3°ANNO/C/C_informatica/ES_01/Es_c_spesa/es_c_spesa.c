/**
\mainpage spesa

@brief Un negoziante per ogni spesa di importo superiore a 50 € effettua uno sconto del 5%, del 10% per ogni spesa superiore a 100 €.
Scrivere un programma che richieda all'utente l'ammontare della spesa e visualizzi quindi l'importo effettivo da pagare.

@author Buongallino Alessandro
@date 26/10/22
@version 1.0 Inizio scrittura programma
*/

#include <stdio.h>

int main()
{
    //dichiariamo le variabili
    float spesa; //di input
    float spesafin; //di output

    //avvaloriamo le variabili
    printf("Calcolo spesa\nScrivere il valore della spesa totale\n");
    scanf("%f", &spesa);

    //poniamo un paragone per trovare lo sconto da applicare
    if (spesa>100)
        spesafin=spesa-spesa*0.1;
    else
    {
        if (spesa>=50)
            spesafin=spesa-spesa*0.05;
        else
            spesafin=spesa;
    }

    //scriviamo il risultato a schermo
    printf("La tua spesa e' di %.2f", spesafin);

    //termino il programma
    return 0;
}
