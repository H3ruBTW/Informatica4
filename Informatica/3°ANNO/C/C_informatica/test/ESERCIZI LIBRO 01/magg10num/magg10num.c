#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, nummax=0;
    int conton=0;

    printf("Maggiore\n");

    do
    {
        printf("Scrivere un numero\n");
        scanf("%d", &num);

        if (num>nummax)
        {
            nummax=num;
        }
        conton++;
    }
    while(conton<10);

    printf("Il numero maggiore e' %d", nummax);
}
