#include <stdio.h>
#include <stdlib.h>

void palindromi10009999 (void);

int main()
{
    palindromi10009999();

    return 0;
}
void palindromi10009999(void)
{
    int n,a1,b1,b2,a2;

    for(n=1000;n<=9999;n++)
    {
        a1=n/1000;
        b1=(n-(a1*1000))/100;
        b2=(n-((a1*1000)+(b1*100)))/10;
        a2=n-((a1*1000)+(b1*100)+(b2*10));

        if(a1==a2&&b1==b2)
        {
            printf("%d ", n);



        }
    }
}
