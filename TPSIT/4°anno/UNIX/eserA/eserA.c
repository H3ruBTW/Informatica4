#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char l[2]; 
    int r, r2, status;


    do
    {   
        printf("\nLampeggio LED\nScrivere 'v' per far lampeggiare il LED verde 10 volte ad intervalli di 0,3 s\n");
        printf("Scrivere 'r' per far lampeggiare il LED rosso 10 volte ad intervalli di 0,7 s\n");
        printf("Scrivere 'g' per far lampeggiare il LED giallo 10 volte ad intervalli di 1,2 s\n");
        printf("Scrivere 'q' per uscire dal programma\n\nInserimento: ");
        scanf("%s", l);
        
        int pid=fork();
        
        if(pid==0)
        {

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
            exit(10);
        }
        else 
        {
            wait(NULL);
        }

        if(l[0]=='q')
            exit(10);
    }while(1);
}
