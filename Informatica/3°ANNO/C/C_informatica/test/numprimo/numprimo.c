#include <stdio.h>

int main ()
{
    int num;
    int numdiv;

    printf("Numero primo\nScrivi un numero\n");
    scanf("%d", &num);

    /**
    acquisito il numero num, provo a diverlo per ogni numero
    intero compreso tra 2 e num-1.

    se il resto della divisione di num e numdiv è uguale a 0
    il programma individua che il numero non è primo
    **/

    for (numdiv=2; num>numdiv; numdiv++)
    {
        if (num%numdiv==0)
        {
            printf("Il numero %d non e' primo", num);

            return 0;
        }
    }

    printf("Il numero %d e' primo", num);

    return 0;
}
