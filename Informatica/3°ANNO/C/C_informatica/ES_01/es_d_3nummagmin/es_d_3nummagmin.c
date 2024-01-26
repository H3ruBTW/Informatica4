/**
\mainpage 3nummagmin

@brief Scrivere un programma che, richiesti in ingresso tre valori interi distinti, ne determini il minore e il maggiore.

@author Buongallino Alessandro
@date 26/10/22
@version 1.0 Inizio scrittura del programma
*/

#include <stdio.h>

int main()
{
    //dichiariamo le variabili
    int num1,num2,num3;//di input e di output

    //avvaloriamo le variabili
    printf("Numeri maggiore e minore\nScrivi il primo numero\n");
    scanf("%d", &num1);
    printf("Scrivi il secondo numero\n");
    scanf("%d", &num2);
    printf("Scrivi il terzo numero\n");
    scanf("%d", &num3);

    //poniamo un confronto per trovare i numeri maggiori e minori
    if (num1>num3&&num1<num2)
        printf("Il numero %d e' il maggiore e %d e' il minore", num2, num3);
    else
    {
        if (num1>num2&&num1<num3)
            printf("Il numero %d e' il maggiore e %d e' il minore", num3, num2);
        else
        {
            if (num2>num1&&num2<num3)
                printf("Il numero %d e' il maggiore e %d e' il minore", num3, num1);
            else
            {
                if (num2>num3&&num2<num1)
                    printf("Il numero %d e' il maggiore e %d e' il minore", num1, num3);
                else
                {
                    if (num3>num1&&num3<num2)
                        printf("Il numero %d e' il maggiore e %d e' il minore", num2, num1);
                    else
                    {
                        if (num3>num2&&num3<num1)
                            printf("Il numero %d e' il maggiore e %d e' il minore", num1, num2);
                    }
                }
            }
        }
    }
    //termino il programma
    return 0;
}
