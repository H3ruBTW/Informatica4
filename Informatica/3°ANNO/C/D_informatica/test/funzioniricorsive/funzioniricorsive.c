#include <stdio.h>

int divisione (int, int);

int r;

int main()
{
    int n1,n2,ris;

    printf("Scrivi un numero\n");
    scanf("%d",&n1);
    printf("Scrivi un numero\n");
    scanf("%d",&n2);

    ris=divisione(n1,n2);

    printf("Divisione = %d\nResto = %d", ris, r);

    return 0;
}
int divisione(int a, int b)
{
    if (b>a)
    {
     r=a;
     return 0;
    }
    return (divisione(a-b,b)+1);
}
