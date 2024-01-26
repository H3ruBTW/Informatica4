/**
\mainpage sommauguale15

@brief Scrivere un programma che visualizzi tutte le coppie ordinate di numeri naturali la cui somma è 15

@author Buongallino Alessandro
@date 30/11/22
@version 1.0 Inizio scrittura programma
*/

#include <stdio.h>

int main()
{
    //dichiarazione delle variabili
    int n1, n2;

    //for che controlla tutti i numeri da 15 in giu finché questo è maggiore del secondo
    for (n1=15, n2=0; n1>n2; n1--)
    {
        //while che continua ad incrementare la variabile n2 finchè questa sommata con n1 è uguale a 15
        while (n1+n2!=15)
        {
            n2++;
        }
        printf("%d + %d = 15\n", n1, n2);
    }

    return 0;
}
