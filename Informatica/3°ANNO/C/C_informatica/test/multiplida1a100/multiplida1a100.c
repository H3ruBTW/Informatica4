#include <stdio.h>
#include <unistd.h>

int main()
{
    int num; //numero principale
    int mult; //multipli di num da controllare

    for (num=1; num<=50; num++)
    {
        printf("\n\nMultipli di %d minori a 100\n", num);

        for(mult=num+1; mult<=100; mult++)
        {
            if (mult%num==0)
                printf("%d,", mult);
        }

        //fflush(stdout);
        //sleep(1);
    }

    return 0;
}
