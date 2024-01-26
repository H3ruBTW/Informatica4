/**
\mainpage numeriprimi1a100

@brief Scrivere un programma che stampi tutti i numeri primi compresi tra 1 e 100. Un numero è primo quando ha come divisore uno e sé stesso.
Quindi è primo ciascun numero naturale maggiore di 1 che sia divisibile solamente per 1 e per sé stesso.

@author Buongallino Alessandro
@date 1/12/22
@version 1.0 Inizio scrittura programma
**/

#include <stdio.h>

int main()
{
    //dichiarazione delle variabili
    int cont, primo; //di lavoro, la variabile primo serve se esso è uguale a 1 va a indicare che il numero non è primo
                     //invece se 0 è primo e quindi in seguito va a scrivere il numero
    int num; //output

    printf("Numeri primi da 1 a 100\n");

    //for per controllare tutti i numeri da 1 a 100
    for(num=1; num<=100; num++)
    {
        primo=0;

        //for per controllare i numeri da 2 a num-1 e i resti dell'espressione num%cont
        for (cont=2; cont<num; cont++)
        {
            //serve a vedere se il num è divisibile perfettamente per il cont, in caso questo sia vero il numero non è primo
            if (num%cont==0)
            {
                primo=1;
            }

        }

        if(primo==0)
            printf("%d ", num);

    }

    return 0;
}
