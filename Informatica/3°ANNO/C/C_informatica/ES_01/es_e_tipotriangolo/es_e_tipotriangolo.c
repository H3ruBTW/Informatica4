/**
\mainpage tipotriangolo

@brief Scrivere un programma che, lette le misure dei lati di un triangolo, visualizzi se il triangolo è equilatero, isoscele o scaleno

@author Buongallino Alessandro
@date 27/10/22
@version 1.0 Inizio scrittura del programma
*/

#include <stdio.h>

int main()
{
    //dichiariamo le variabili
    float lat1, lat2, lat3;//di input

    //avvaloriamo le variabili
    printf("Tipo triangolo\nScrivi la lunghezza del primo lato\n");
    scanf("%f", &lat1);
    printf("Scrivi la lunghezza del secondo lato\n");
    scanf("%f", &lat2);
    printf("Scrivi la lunghezza del terzo lato\n");
    scanf("%f", &lat3);

    //poniamo un confronto
    if (lat1==lat2&&lat2==lat3)
        printf("Il triangolo con lati e' equilatero");
    else
    {
        if (lat1!=lat2&&lat2!=lat3)
            printf("Il triangolo con lati %.2f, %.2f, %.2f, e' scaleno", lat1, lat2, lat3);
        else
            printf("Il triangolo con lati %.2f, %.2f, %.2f, e' isoscele", lat1, lat2, lat3);
    }

    //termino il programma
    return 0;
}
