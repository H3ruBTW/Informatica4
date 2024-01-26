#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(void);

void testcarica(int [], int [], int, int);
void carica(int [], int);

void testcrandom(int [],int [], int, int);
void crandom(int [], int, int, int);

void scrivi(int [], int);

void scambia (int [], int [], int);

void testordina(int [],int [], int, int);
void ordina(int [], int);

void bubble (int [], int [], int, int);

int main()
{
    srand(time(NULL));
    int sce1, slot, sce2, car=0, e;

    printf("Quanti slot per i vettori: ");
    scanf("%d", &slot);

    int vet1[slot], vet2[slot];

    do
    {
        sce1=menu();

        switch(sce1)
        {
        case 0:
            system("cls");

            printf("Uscita dal programma");
            //funzione sleep: il programma aspetta "x" secondi prima di passare alla prossima istruzione
            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);
            break;

        case 1:
            //carica basico
            system("cls");

            printf("Caricare Vettore1 o Vettore2, inserire 1 o 2: ");
            scanf("%d", &sce2);

            if(sce2==1||sce2==2)
            {
                testcarica(vet1, vet2, slot, sce2);
                car=1;
            }
            else
                printf("\nNon è stato inserito un numero indicato\n\n");

            break;

        case 2:
            //carica random
            system("cls");

            printf("Caricare Vettore1 o Vettore2, inserire 1 o 2: ");
            scanf("%d", &sce2);

            if(sce2==1||sce2==2)
            {
                testcrandom(vet1, vet2, slot, sce2);
                car=1;
            }
            else
                printf("\nNon è stato inserito un numero indicato\n\n");

            break;

        case 3:
           //scrivi
            system("cls");

            if(car==1)
            {
                printf("Primo vettore:\n");
                scrivi(vet1, slot);

                printf("Secondo vettore:\n");
                scrivi(vet2, slot);
            }
            else
                printf("I vettori/e non sono stato caricati\n");

            break;
        case 4:
            //scambia
            system("cls");

            if (car==1)
                scambia(vet1, vet2, slot);
            else
                printf("I vettori/e non sono stati caricati\n");
        case 5:
            //ordina
            system("cls");

            if(car==1)
            {
                printf("Ordinare Vettore1 o Vettore2, inserire 1 o 2: ");
                scanf("%d", &sce2);

                if(sce2==1||sce2==2)
                {
                    testordina(vet1, vet2, slot, sce2);
                }
                else
                    printf("\nNon è stato inserito un numero indicato\n\n");
            }
            else
                printf("I vettori/e non sono stati caricati\n");

            break;
        case 6:
            //ordina
            system("cls");

            if(car==1)
            {
                printf("Ordinare Vettore1 o Vettore2, inserire 1 o 2: ");
                scanf("%d", &sce2);

                if(sce2==1||sce2==2)
                {
                    bubble(vet1, vet2, slot, sce2);
                }
                else
                    printf("\nNon è stato inserito un numero indicato\n\n");
            }
            else
                printf("I vettori/e non sono stati caricati\n");

            break;
        }

    } while(sce1!=0);

}
int menu(void)
{
    system("pause");
    system("cls");

    int sce;

    printf("Menu\nInserire 1 per caricare il vettore\n");
    printf("Inserire 2 per caricare casualmente il vettore\n");
    printf("Inserire 3 per scrivere il vettore\n");
    printf("Inserire 4 per scambiare i valori dei vettori\n");
    printf("Inserire 5 per ordina i vettori\n");
    printf("Inserire 6 per ordina i vettori col BubbleSort\n");
    printf("Inserire 0 per uscire dal programma\n");

    scanf("%d", &sce);

    return sce;
}
void scrivi(int v[], int x)
{
    //system("cls");

    for(int cont=0; cont<x; cont++)
    {
        printf("%d ", v[cont]);
    }
    printf("\n");
}
void testcarica (int v1[], int v2[], int x, int y)
{
    system("cls");

    int sce;

    if(y==1)
    {
        carica(v1, x);

        system("pause");
    }
    else
    {
        if(y==2)
        {
            carica(v2, x);

            system("pause");
        }
    }

    system("cls");

    printf("Si vuole caricare anche l'altro vettore?\nInserire 1 se SI o 0 per NO: ");
    scanf("%d", &sce);

    if(sce==1)
    {
        if(y==1)
        {
            carica(v2, x);
        }
        else
        {
            if(y==2)
            {
                carica(v1, x);
            }
        }
    }

}
void carica(int v[], int x)
{
    int i;

    system("cls");

    for(i=0;i<x;i++)
    {
        printf("Inserire il numero da mettere nello slot %d: ", i);
        scanf("%d", &v[i]);
    }
}
void testcrandom(int v1[], int v2[], int x, int y)
{
    system("cls");

    int sce, min, max;

    printf("Intervallo dei numeri casuali (solo positivi)\nInserire l'intervallo minimo: ");
    scanf("%d", &min);
    printf("Inserire l'intervallo maggiore: ");
    scanf("%d", &max);

    system("cls");

    if(y==1)
    {
        crandom(v1, x, min, max);

        printf("Primo vettore:\n");
        scrivi(v1, x);

        system("pause");
    }
    else
    {
        if(y==2)
        {
            crandom(v2, x, min, max);

            printf("Secondo vettore:\n");
            scrivi(v2, x);

            system("pause");
        }
    }

    system("cls");

    printf("Si vuole caricare anche l'altro vettore?\nInserire 1 se SI o 0 per NO: ");
    scanf("%d", &sce);

    system("cls");

    if(sce==1)
    {
        if(y==1)
        {
            crandom(v2, x, min, max);

            printf("Secondo vettore:\n");
            scrivi(v2, x);
        }
        else
        {
            if(y==2)
            {
                crandom(v1, x, min, max);

                printf("Primo vettore:\n");
                scrivi(v1, x);
            }
        }
    }
}
void crandom(int v[], int x, int mi, int ma)
{
    int i;

    for(i=0; i<x; i++)
    {
        v[i]=(rand()%(ma+1-mi))+mi;
    }
}
void scambia(int v1[], int v2[], int x)
{
    int i, l;

    for(i=0; i<x; i++)
    {
        l=v1[i];
        v1[i]=v2[i];
        v2[i]=l;
    }
    printf("Primo vettore:\n");
    scrivi(v1, x);

    printf("\nSecondo vettore:\n");
    scrivi(v2, x);
}
void testordina (int v1[], int v2[], int x, int y)
{
    int sce;

    system("cls");

    if(y==1)
    {
        ordina(v1, x);

        scrivi(v1, x);
    }
    else
    {
        ordina (v2, x);

        scrivi(v1, x);
    }
    system("cls");

    printf("Si vuole caricare anche l'altro vettore?\nInserire 1 se SI o 0 per NO: ");
    scanf("%d", &sce);

    system("cls");

    if(sce==1)
    {
        if(y==1)
        {
            ordina(v2, x);

            scrivi(v2, x);
        }
        else
        {
            ordina(v1, x);

            scrivi(v1, x);
        }
    }

}
void ordina (int v[], int x)
{
    int n1, n2, lav;

    for(n1=0; n1<x; n1++)
    {
        for(n2=n1+1; n2<x; n2++)
        {
            if(v[n1]>v[n2])
            {
                lav=v[n1];
                v[n1]=v[n2];
                v[n2]=lav;
            }
        }
    }
}
void bubble (int v1[], int v2[], int x, int y)
{
    int fine=x, fine2=x, scambio, z;
    if(y==1)
    {
        do
        {
            scambio=0;

            fine=fine2;

            for(int i=0; i<fine; i++)
            {
                if(v1[i]>v1[i+1])
                {
                    scambio=1;

                    fine2=i;

                    z=v1[i];
                    v1[i]=v1[i+1];
                    v1[i+1]=z;
                }
            }
        }while(scambio==1);

        system("cls");

        printf("Vettore ordinato:\n");
        scrivi(v1, x);
    }
    else
    {
        do
        {
            scambio=0;

            fine=fine2;

            for(int i=0; i<fine; i++)
            {
                if(v2[i]>v2[i+1])
                {
                    scambio=1;

                    fine2=i;

                    z=v2[i];
                    v2[i]=v2[i+1];
                    v2[i+1]=z;
                }
            }

        }while(scambio==1);

        system("cls");

        printf("Vettore ordinato:\n");
        scrivi(v2, x);
    }
}
