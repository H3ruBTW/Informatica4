/**
\mainpage Conto_Num_Par

@brief programma che conta i numeri pari scritti dall'utente e in caso di scrittura di uno 0, terminare il programma scrivendo in precedenza
la quantità di numeri pari

@author Buongallino Alessandro
@date 16/11/22
@version 1.0 inizio scrittura programma
**/

#include <stdio.h>

int main()
{
    //dichiarare le variabili
    int num; // di input
    int numpar; // di output

    do
    {
        printf("Scrivere un numero\n");
        scanf("%d", &num);

        if (num%2==0)
            numpar++;
    }
    while (num!=0);

    printf("La quantita' di numeri pari inserita e' %d", numpar);

    return 0;
}
