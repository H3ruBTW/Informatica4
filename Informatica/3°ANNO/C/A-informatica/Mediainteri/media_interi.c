/*
Buongallino Alessandro

Input di 3 interi che danno come output la loro media

Input: 3 numeri interi
Elaborazione:Somma, Moltiplicazione
Output: 1 numero intero
*/

#include <stdio.h> //include i comandi come printf e scanf

int main() {
//dichiariamo le variabili
float n1, n2, n3;//di input
float ris; //di output

//facciamo dichiarare all'utente le variabili
printf("Media\nScrivi il primo numero\n");
scanf("%f", &n1);
printf("Scrivi il secondo numero\n");
scanf("%f", &n2);
printf("Scrivi il terzo numero\n");
scanf("%f", &n3);

//assegnamo il risultato
ris=(n1+n2+n3)/3;

printf("La media dei tre numeri e' %.2f", ris);

//termino il programma
return 0;
}
