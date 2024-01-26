/** **************************************************************************
*\mainpage
*@brief Programma che esclude trova se l'anno inserito è Giacobeo (25 luglio =
*       domenica)
*
*@author Buongallino Alessandro
*@date 28/07/23
*@version 1.0
*/
#include <stdio.h>
#include <stdlib.h>

int annog (int);
//5 dc primo anno giacobeo
int main ()
{
    int r, anno;
    printf("Anno Giacobeo?\nInserisci l'anno: ");
    scanf("%d", &anno);

    if(anno<5)
    {
        printf("\n%d non e' un anno giacobeo", anno);
        return 0;
    }
    if(anno==5)
    {
        printf("\n%d e' un anno giacobeo", anno);
        return 0;
    }

    r=annog(anno);

    if(r==0)
    {
        printf("\n%d non e' un anno giacobeo", anno);
        return 0;
    }
    if(r==1)
    {
        printf("\n%d e' un anno giacobeo", anno);
        return 0;
    }
}
int annog (int x)
{
    int i=x;

    while(i>=5)
    {
        i-=28;
    }

    i+=28;

    if(i-11>=5)
        i-=11;
    if(i-6>=5)
        i-=6;
    if(i-5>=5)
        i-=5;
    if(i-6>=5)
        i-=6;
    if(i==5)
        return 1;
    if(i!=5)
        return 0;
}
