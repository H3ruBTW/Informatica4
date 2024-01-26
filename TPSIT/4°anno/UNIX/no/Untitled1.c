#include <stdio.h>
#include <stdlib.h>

int main()
{
    char l[10];
    int r;

    for(int j=0; j<100000000, l!="q"; j++)
    {
        printf("v r g q\n");

        scanf("%s", l);
        if(l[0]=='v')
        {
            for(int i=0; i<10; i++)
            {
                printf("LED verde acceso\n");
                r=usleep(300000);
                printf("LED verde spento\n");
                r=usleep(300000);
            }
        }
        if(l[0]=='r')
        {
            for(int i=0; i<10; i++)
            {
                printf("LED rosso acceso\n");
                r=usleep(700000);
                printf("LED rosso spento\n");
                r=usleep(700000);
            }
        }
        if(l[0]=='g')
        {
            for(int i=0; i<10; i++)
            {
                printf("LED giallo acceso\n");
                r=usleep(1200000);
                printf("LED giallo spento\n");
                r=usleep(1200000);
            }
        }
        if(l[0]=='q')
        {
            printf("Terminazione del programma...\n\n");
        }

    }
    return 0;
}

