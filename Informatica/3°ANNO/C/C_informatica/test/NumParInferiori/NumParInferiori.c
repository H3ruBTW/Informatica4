#include <stdio.h>
#include <limits.h>

int main()
{
    int num;

    printf("Visualizzatore di numeri pari inferiori a quello inserito\nScrivi un numero\n");
    scanf("%d", &num);

    if (num%2==1)
        num--;
    for (num; num>=0; num-=2)
    {
        printf("%d\n" ,num);
    }

    return 0;
}
