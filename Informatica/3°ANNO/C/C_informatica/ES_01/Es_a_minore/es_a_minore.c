/**
\mainpage numero minore

@brief L'utente scrive due numeri e il programma scrive a schermo il minore


@author Buongallino Alessandro
@date 26/10/2022
@version 1.0 Inizio della scrittura del programma
*/

#include <stdio.h>

int main ()
{
    //dichiariamo le variabili
    int num1, num2;//di input e output

    //avvaloriamo le variabili
    printf("Qual'e' il minore?\nScrivere il primo numero\n");
    scanf("%d", &num1);
    printf("Scrivere il secondo numero\n");
    scanf("%d", &num2);

    //poniamo un confronto al programma
    if(num1>num2)
        printf("%d e' il minore", num2);
    else
    {
        if(num2>num1)
            printf("%d e' il minore", num1);
        else
            printf("I due numeri sono uguali");
    }

    //termino il programma
    return 0;
}
