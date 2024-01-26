/** **************************************************************************
\mainpage test funzioni
@brief utilizzo delle funzioni

@author Buongallino Alessandro
@date 11/01/23
**/

#include <stdio.h>

//funzione che effettua la somma tra due variabili inserite da un utente esternamente
int somma (int,int);

int main()
{
    int num1, num2, r;

    printf("Somma di due numeri\nScrivere il primo numero\n");
    scanf("%d", &num1);
    printf("Scrivere il secondo numero\n");
    scanf("%d", &num2);

    r=somma(num1,num2);

    printf("Il risultato e' %d", r);

}
int somma (int x, int y)
{
    int r;
    r=x+y;
    return r;
}
