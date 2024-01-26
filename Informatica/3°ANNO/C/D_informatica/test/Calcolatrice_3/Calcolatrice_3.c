#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int menu (double);

void add (void);

void sot (void);

void mol (void);

void divi (void);

double ris=0;

int main()
{
    double num;
    int sce;

    printf("Calcolatrice v 3.0\nInserire il primo numero da calcolare: ");
    scanf("%lf", &num);

    ris+=num;

    do
    {
        sce=menu(ris);

        switch (sce)
        {
        case 0:
            system("cls");

            printf("Il risultato finale e' %lf\n\n", ris);

            system("pause");

            printf("\nUscita in corso");

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
            add();
            break;
        case 2:
            sot();
            break;
        case 3:
            mol();
            break;
        case 4:
            divi();
            break;
        default:
            printf("\nIl numero inserito non è nell'elenco\n");
            system("pause");
            break;
        }
    } while(sce!=0);
}
int menu (double x)
{
    int s;

    system("cls");

    printf("Il risultato e' %lf\n", x);
    printf("Inserire 1 per Addizione\n");
    printf("Inserire 2 per Sottrazione\n");
    printf("Inserire 3 per Moltiplicazione\n");
    printf("Inserire 4 per Divisione\n");
    printf("Inserire 0 per uscire\n\n");

    scanf("%d", &s);

    return s;
}
void add (void)
{
    double n;
    system("cls");

    printf("Addizione\nInserire un numero: ");
    scanf("%lf", &n);

    ris+=n;
}
void sot (void)
{
    double n;
    system("cls");

    printf("Sottrazione\nInserire un numero: ");
    scanf("%lf", &n);

    ris-=n;
}
void mol (void)
{
    double n;
    system("cls");

    printf("Moltiplicazione\nInserire un numero: ");
    scanf("%lf", &n);

    ris*=n;
}
void divi (void)
{
    double n;
    system("cls");

    printf("Divisione\nInserire un numero: ");
    scanf("%lf", &n);

    ris/=n;
}
