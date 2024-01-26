/*
  Buongallino Alessandro

  Input di due interi che danno come output la loro somma

  Input: 2 numeri interi
  Elaborazione: Somma
  Output: 2 Numeri Interi
*/

#include <stdio.h> //Include codici come printf e scanf

int main() {

  //dichiaramo le variabili di input
  int n1, n2;
  //e output
  int ris;

  //Input: 2 numeri interi
  printf("Scrivi il primo numero\n");
  scanf("%d", &n1);
  printf("Scrivi il secondo numero\n");
  scanf("%d", &n2);

  //Output: 2 Numeri Interi
  ris=n1+n2;
  printf("Il risultato e' %d", ris);

  return 0;
}

