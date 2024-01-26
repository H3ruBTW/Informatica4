/**
\mainpage divisorinumint

@brief Scrivere un programma che, richiesto un numero intero, visualizzi tutti i suoi divisori.

@author Buongallino Alessandro
@date 30/11/22
@version 1.0 Inizio scrittura programma
*/

#include <stdio.h>

int main()
{
    //dichiarazione delle variabili
    int num; //input
    int cont; //di lavoro
    int div; //di output

    //avvaloramento della variabile num
    printf("Divisori\nScrivere un numero\n");
    scanf("%d",&num);

    //for per individuare tutti i divisori della variabile num tra 1 e num
    for (cont=1; cont<=num; cont++)
    {
        if (num%cont==0)
            printf("%d/", cont);
    }

    return 0;
}
