/** **************************************************************************
*\mainpage
*@brief Programma che esclude la colonna e la riga decisi dall'utente
*       e poi somma tutto quello che rimane
*
*@author Buongallino Alessandro
*@date 28/07/23
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

#define R 5
#define C 5

//Funzione che lavorano insieme per caricare un'unica matrice
void caricam (int [][C]);
void caricav (int []);

//funzione che scrive tutta la matrice
void scrivim (int [][C]);

//Funzione che somma tutta la matrice non esclusa
int sommam (int [][C], int, int);

int main()
{
    int rig, col, r, err=0;
    int m[R][C];

    srand(time(NULL));

    caricam (m);

    scrivim (m);

    do
    {
        if(err==1)
        {
            printf("\n***Hai inserito una riga non esistente***\n");
            err=0;
        }
        printf("\nSomma della matrice\n\nEscludi una riga: ");
        scanf("%d", &rig);
        if (rig>C-1||rig<0)
            err=1;
    } while(rig>R-1||rig<0);

    do
    {
        if(err==1)
        {
            printf("\n***Hai inserito una colonna non esistente***\n");
            err=0;
        }
        printf("\nBene, adesso escludi una colonna: ");
        scanf("%d", &col);
        if (col>C-1||col<0)
            err=1;
    } while(col>C-1||col<0);

    r=sommam(m, rig, col);

    printf("\nIl risultato della matrice con riga %d e colonna %d esclusa e' %d\n", rig, col, r);

    return 0;
}

void caricam (int m[][C])
{
    for(int i=0; i<R; i++)
    {
        caricav(m[i]);
    }
}
void caricav (int v[])
{
    for (int i=0; i<R; i++)
    {
        v[i]=rand()%10;
    }
}
void scrivim (int m[][C])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
int sommam (int m[][C], int x, int y)
{
    int ris=0;

    printf("\n");

    for(int i=0; i<R; i++)
    {
        if(i==x)
            i++;

        for(int j=0; j<C; j++)
        {
            if(j!=y)
            {
                printf("%d + %d = ", ris, m[i][j]);
                ris+=m[i][j];
                printf("%d\n", ris);

            }
        }

    }
    return ris;
}
