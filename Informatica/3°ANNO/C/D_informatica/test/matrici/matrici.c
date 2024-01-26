#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define C 10
#define R 10

void caricaMatriceRnd (int [][C]);
void scriviMatrice (int [][C]);
void caricaMatrice (int [][C]);
int massimo (int [][C]);
int conta (int[][C], int);
void scriviDiagonaleM (int [][C]);
int ricercaIndice (int [][C], int);

int g;

int main()
{
    int M[R][C], r, num;

    srand(time(NULL));

    /*
    printf("Caricare casualmente la matrice?\n");
    system("pause");

    caricaMatriceRnd(M);

    printf("Scrivere a schermo la matrice?\n");
    system("pause");
    printf("\n\n");

    scriviMatrice(M);

    printf("\n\n");
    */

    /*
    caricaMatrice(M);

    scriviMatrice(M);
    */

    /*
    caricaMatriceRnd(M);

    scriviMatrice(M);

    r=massimo(M);

    printf("Il numero massimo trovato nella matrice e' %d", r);
    */

    /*
    caricaMatriceRnd(M);

    scriviMatrice(M);

    printf("Inserire numero da trovare nella matrice: ");
    scanf("%d", &num);

    r=conta(M, num);

    printf("\n\nIl numero di %d nella matrice e' %d", num, r);
    */

    /*
    caricaMatriceRnd(M);

    scriviDiagonaleM(M);
    */

    /*
    caricaMatriceRnd(M);

    scriviMatrice(M);

    printf("Inserire numero da trovare nella matrice: ");
    scanf("%d", &num);

    r=ricercaIndice(M, num);

    if(r>-1)
    {
        printf("\n\nIl numero %d e' stato trovato nella riga %d, colonna %d", num, r, g);
    }
    else
    {
        printf("\n\nIl numero non e' stato trovato");
    }
    */

    return 0;
}
void caricaMatriceRnd (int M[][C])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
            M[i][j]=rand()%41+10;
    }
}
void scriviMatrice (int M[][C])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
            printf("%d ",M[i][j]);

        printf("\n");
    }
}
void caricaMatrice (int M[][C])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
            scanf("%d", &M[i][j]);
    }
}

int massimo (int M[][C])
{
    int max=INT_MIN;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(M[i][j]>max)
                max=M[i][j];
        }
    }

    return max;
}

int conta (int M[][C], int x)
{
    int c=0;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(M[i][j]==x)
                c++;
        }
    }

    return c;
}

void scriviDiagonaleM(int M[][C])
{
    for(int cont=0; cont<C; cont++)
    {
        printf("%d ", M[cont][cont]);
    }
}

int ricercaIndice (int M[][C], int x)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(M[i][j]==x)
            {
                g=j;
                return i;
            }
        }
    }
    g=-1;
    return -1;
}
