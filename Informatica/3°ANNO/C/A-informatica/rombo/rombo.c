/*
Buongallino ALessandro

Trovare il perimetro e l'area del rombo con il lato e la diagonale minore

Input: 2 numeri
Elaborazione: Formule per trovare il perimetro e l'area del rombo
Output: 2 numeri
*/

#include <stdio.h>
#include <math.h>

int main()
{
//dichiara le variabili
int lato, dia1;//input
int dia2; //di lavoro
int perRom, areaRom; //output

//avvaloriamo le variabili
printf("Scrivere il valore del lato del rombo\n");
scanf("%d", &lato);
printf("Scrivere il valore della diagonale minore\n");
scanf("%d", &dia1);

//assegnamo la variabile di lavoro
dia1=dia1/2;
dia2= sqrt(pow(lato, 2) - pow (dia1, 2));
dia2= dia2 * 2;

//assegnamo i risultati
perRom= lato * 4;
areaRom= (dia2 * dia1) /2;

//scriviamo i risultati a schermo
printf("Il rombo ha il perimetro di %d e l'area di %d", perRom, areaRom);

//termino il programma
return 0;
}
