#include <stdio.h>
#include <stdlib.h>

#define R 5
#define C 5

int M1[R][C];
int M2[R][C];

void caricam0 (void);
int cmatrix1 (int, int);
int cmatrix2 (int, int);
void pnaviG1 (void);
void pnaviG2 (void);
void scriviMatriceG1 (void);
void scriviMatriceG2 (void);
void scriviMatrice1 (void);
void scriviMatrice2 (void);
int turnog1 (void);
int turnog2 (void);
int cdigioco1 (int);
int cdigioco2 (int, int, int);

int main()
{
    int fine=0;

    printf("Battaglia Navale\n\n");
    system("pause");
    system("cls");
    pnaviG1();
    system("cls");
    pnaviG2();
    system("cls");

    inizio:

    fine=turnog1();
    system("cls");

    if(fine==2||fine==3)
        goto fine;

    fine=turnog2();
    system("cls");

    if(fine==2||fine==3)
        goto fine;
    else
        goto inizio;

    fine:

    if(fine==2)
        printf("Complimenti, Giocatore 1, HAI VINTO!!!");
    if(fine==3)
        printf("Complimenti, Giocatore 2, HAI VINTO!!!");

    return 0;
}

void caricam0 (void)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
         {
             M1[i][j]=0;
             M2[i][j]=0;
         }
    }
}

int cmatrix1(int x, int y)
{
    if(x>4||x<0||y>4||y<0)
    {
        printf("\n\nCoordinate non disponibili\n\n");
        return 0;
    }
    if(M1[x][y]==1)
    {
        printf("\nE' gia' presente una nave a queste coordinate\n\n");
        return 0;
    }
    M1[x][y]=1;
    return 1;
}

int cmatrix2(int x, int y)
{
    if(x>4||x<0||y>4||y<0)
    {
        printf("\n\nCoordinate non disponibili\n\n");
        return 0;
    }
    if(M2[x][y]==1)
    {
        printf("\nE' gia' presente una nave a queste coordinate\n\n");
        return 0;
    }
    M2[x][y]=1;
    return 1;
}

void pnaviG1 (void)
{
    int rig,col,con;

    for(int c=1; c<=5; c++)
    {
        system("cls");
        scriviMatriceG1();
        printf("Giocatore 1, inserisci le tue 5 navi inserendo le coordinate\n\n");
        printf("Nave %d\n", c);

        do
        {
            printf("Riga: ");
            scanf("%d", &rig);
            printf("Colonna: ");
            scanf("%d", &col);
            con=cmatrix1(rig, col);
        }
        while(con==0);
    }
    system("cls");
    scriviMatriceG1();
    system("pause");
}

void pnaviG2 (void)
{
    int rig,col,con;

    for(int c=1; c<=5; c++)
    {
        system("cls");
        scriviMatriceG2();
        printf("Giocatore 2, inserisci le tue 5 navi inserendo le coordinate\n\n");
        printf("Nave %d\n", c);

        do
        {
            printf("Riga: ");
            scanf("%d", &rig);
            printf("Colonna: ");
            scanf("%d", &col);
            con=cmatrix2(rig, col);
        }
        while(con==0);
    }

    system("cls");
    scriviMatriceG2();
    system("pause");
}

void scriviMatriceG1 (void)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
             printf("%3d-%d",i, j);
             if (M1[i][j]==1)
                printf("#");
        }

        printf("\n\n");
    }
}
void scriviMatriceG2 (void)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
             printf("%3d-%d",i, j);
             if (M2[i][j]==1)
                printf("#");
        }

        printf("\n\n");
    }
}

void scriviMatrice1 (void)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
             printf("%3d-%d",i, j);
             if (M1[i][j]==-1)
                printf("!");
             if (M1[i][j]==-2)
                printf("X");
             if (M1[i][j]==1||M1[i][j]==0)
                printf("~");
        }

        printf("\n\n");
    }
}

void scriviMatrice2 (void)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
             printf("%3d-%d",i, j);
             if (M2[i][j]==-1)
                printf("!");
             if (M2[i][j]==-2)
                printf("X");
             if (M2[i][j]==1||M2[i][j]==0)
                printf("~");
        }

        printf("\n\n");
    }
}

int turnog1 (void)
{
    int rig,col,con,fin;

    do
    {
        system("cls");
        con=cdigioco1(2);

        if(con==0)
            return 2;

        printf("Tabella di gioco:\n\n");

        scriviMatrice2();

        printf("\n\nTurno di Attacco, Giocatore 1\n\n");
        printf("Coordinate Bombardamento\n");
        printf("Riga: ");
        scanf("%d", &rig);
        printf("Colonna: ");
        scanf("%d", &col);

        fin=cdigioco2(rig,col,1);

        system("pause");
    }
    while(fin==1||fin==0);

    return 0;
}

int turnog2 (void)
{
    int rig,col,con,fin;

    do
    {
        system("cls");
        con=cdigioco1(1);

        if(con==0)
            return 3;

        printf("Tabella di gioco:\n\n");

        scriviMatrice1();

        printf("\n\nTurno di Attacco, Giocatore 2\n\n");
        printf("Coordinate Bombardamento\n");
        printf("Riga: ");
        scanf("%d", &rig);
        printf("Colonna: ");
        scanf("%d", &col);

        fin=cdigioco2(rig,col,2);

        system("pause");
    }
    while(fin==1||fin==0);

    return 0;
}

int cdigioco1 (int x)
{
    if (x==1)
    {
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                 if(M1[i][j]==1)
                    return 1;
            }
        }
    }
    else
    {
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                 if(M2[i][j]==1)
                    return 1;
            }
        }
    }

    return 0;
}

int cdigioco2 (int x, int y, int z)
{
    if(z==1)
    {
        if(x>4||x<0||y>4||y<0)
        {
            printf("\n\nCoordinate non disponibili\n\n");
            return 1;
        }
        if(M2[x][y]<0)
        {
            printf("\nLa coordinata e' gia' stata bombardata\n\n");
            return 1;
        }
        if (M2[x][y]==0)
        {
            M2[x][y]=-2;
            printf("\nNon e' stata colpita nessuna nave\n\n");
            return 2;
        }
        if(M2[x][y]==1)
        {
            M2[x][y]=-1;
            printf("\nE' stata colpita una nave\n\n");
        }
        return 0;
    }
    else
    {
        if(x>4||x<0||y>4||y<0)
        {
            printf("\n\nCoordinate non disponibili\n\n");
            return 1;
        }
        if(M1[x][y]<0)
        {
            printf("\nLa coordinata e' gia' stata bombardata\n\n");
            return 1;
        }
        if (M1[x][y]==0)
        {
            M1[x][y]=-2;
            printf("\nNon e' stata colpita nessuna nave\n\n");
            return 2;
        }
        if(M1[x][y]==1)
        {
            M1[x][y]=-1;
            printf("\nE' stata colpita una nave\n\n");
        }
        return 0;
    }

}
