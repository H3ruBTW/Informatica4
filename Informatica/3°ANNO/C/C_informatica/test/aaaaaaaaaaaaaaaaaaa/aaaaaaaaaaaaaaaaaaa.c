#include <stdio.h>

int main()
{
    int num, somma=0, c=-1;
    float media;

    do
    {
        printf("Inserisci numero: ");
        scanf("%d", &num);

        somma= somma + num;
        c++;
    } while (num!=0);

    media= (float)somma/(float)c;
    printf("La media e' %f", media);

    return 0;
}
