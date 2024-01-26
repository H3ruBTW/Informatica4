#include <stdio.h>
#include <math.h>

int main ()
{
    float pesop;
    float intlav;
    float numsac, numcas;

    scanf("%f", &pesop);

    if(pesop<80)
    {
        numcas=pesop/30;
        intlav=(int)numcas*30;
        numsac=(pesop-intlav)/5;

        printf("Il numero di cassette e' %.0f e il numero di sacchetti e' %.0f", numcas, ceilf(numsac));
    }
    else
        printf("Troppe patate!");

    return 0;
}
