/**
\mainpage ugualemagmin

@brief L'utente scrive due numeri e il programma determina se uguale se no determina il minore e il maggiore


@author Buongallino Alessandro
@date 26/10/2022
@version 1.0 Inizio della scrittura del programma
*/

#include <stdio.h>

int main()
{
    //dichiara le variabile
    int num1, num2;

    //avvaloriamo le variabili
    printf("E' uguale? Se no ti scrivo il minore e il maggiore\nScrivere il primo numero\n");
    scanf("%d", &num1);
    printf("Scrivere il secondo numero\n");
    scanf("%d", &num2);

    //poniamo un confronto al programma
    if(num1==num2)
        printf("%d e %d sono uguali", num1, num2);
    else
    {
        if (num1>num2)
            printf("%d e' maggiore di %d", num1, num2);
        else
            printf("%d e' maggiore di %d", num2, num1);
    }

    //termino il programma
    return 0;
}
