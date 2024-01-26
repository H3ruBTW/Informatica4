#define N 10
#include <stdio.h>
#include <limits.h>

int main ()
{
    int num;
    int cont;
    int max=INT_MIN, min=INT_MAX;

    for(cont=0; cont<=N; cont++)
    {
        printf("Inserisci un numero\n");
        scanf("%d", &num);

        if (max<num)
            max=num;
        if (min>num)
            min=num;
    }

    printf("Il numero maggiore e' %d ed il minore e' %d", max, min);

    return 0;
}
