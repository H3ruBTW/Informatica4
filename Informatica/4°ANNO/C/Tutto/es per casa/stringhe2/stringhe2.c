#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 10
#define C 20

void caricast(char [][C]);
void scrivist(char [][C]);
int strmax (char [][C]);

int main ()
{
    char ms[R][C];
    int r;

    caricast(ms);
    scrivist(ms);
    r=strmax(ms);

    printf("\n\nLa stringa piu' lunga e' %s(%d)", ms[r], strlen(ms[r]));
    return 0;
}

void caricast(char ms[][C])
{
    int f;

    for(int i=0; i<R; i++)
    {
        f=0;

        do
        {
            if(f==1)
            {
                printf("\n\nHai superato il limite dei caratteri\nRinserire la stringa di max 19 caratteri\n\n");
            }

            printf("Inserire stringa num %d di max 19 car: ", i+1);
            scanf("%s", ms[i]);

            f=1;

        }while(strlen(ms[i])>=20);
    }
}

void scrivist(char ms[][C])
{
    for(int i=0; i<R; i++)
    {
        printf("\n%s(%d)", ms[i], strlen(ms[i]));
    }
}

int strmax(char ms[][C])
{
    int max=strlen(ms[0]);
    int ind=0;

    for(int i=1; i<R; i++)
    {
        if(strlen(ms[i])>max)
        {
            max=strlen(ms[i]);
            ind=i;
        }
    }

    return ind;
}
