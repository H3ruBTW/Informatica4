#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int vet[4];

    printf("Numeri palindromi da 10 a 9999\n\n");

    system("pause");

    printf("\n");

    for(num=9999;num>=10;num--)
    {
        vet[0]=num/1000;
        vet[1]=num/100-vet[0]*10;
        vet[2]=num/10-vet[0]*100-vet[1]*10;
        vet[3]=num%10;

        if(num>1000)
        {
            if(vet[0]==vet[3]&&vet[1]==vet[2])
                printf("%d ", num);
        }
        if (num>100&&num<1000)
        {
            if(vet[1]==vet[3])
                printf("%d ", num);
        }
        if (num>=10&&num<100)
        {
             if(vet[2]==vet[3])
                printf("%d ", num);
        }
    }

    return 0;
}
