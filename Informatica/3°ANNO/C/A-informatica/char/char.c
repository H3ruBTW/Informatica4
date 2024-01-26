/*
Buongallino Alessandro

Scrivere una lettera e trovarne il suo ASCII

Input:1 lettera
Elaborazione:
Output:1 numeri/1 lettera
*/

#include <stdio.h>

int main(){
//dichoiariamo le variabili
char car;//di input e di output

printf("Scrivi una qualsiasi lettera per trovare il suo ASCII\n");
scanf("%c", &car);

//scriviamo il risultato
printf("La lettera che hai scritto e' %c\nMentre la lettera che hai scritto, in ASCII e' %d", car, car);

//termino il programma
return 0;
}
