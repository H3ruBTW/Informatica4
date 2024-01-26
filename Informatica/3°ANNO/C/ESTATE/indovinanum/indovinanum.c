/** **************************************************************************
*\mainpage
*@brief Scrivi un programma che implementi il gioco in cui bisogna indovinare
*       un numero segreto e dando indizi come "troppo grande" o "troppo piccolo"
*
*@author Buongallino Alessandro
*@date 27/08/23
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

int generanum (void);
void gioco (int);

int main ()
{
    int n;

    srand(time(NULL));

    n=generanum();

    gioco(n);

    return 0;
}

int generanum (void)
{
    int n=rand()%100+1;

    return n;
}

void gioco (int x)
{
    int f=0; //fine
    int n;

    printf("Benvenuto a Indovina il numero\nIl tuo compito e' indovinare il numero segreto generato casualmente tra 1 e 100");

    for(int i=5; i>0&&f==0; i--)
    {
        printf("\n\nHai ancora %d tentativo/i\nInserisci la tua risposta: ", i);
        scanf("%d", &n);

        if(n==x)
        {
            f=1;
            printf("\n\nComplimenti, hai indovinato il numero\n\n");
        }
        else
        {
            if(n>x)
                printf("\n\nHai sbagliato\nNumero troppo grande");
            if(n<x)
                printf("\n\nHai sbagliato\nNumero troppo piccolo");
        }
    }
    if(f==0)
        printf("\n\nHai finito i tentativi, Il numero era %d\n\nGame Over\n\n", x);

    system("pause");
}
