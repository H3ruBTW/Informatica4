#include <stdio.h>  //utilizzo soppratutto del ciclo while utilizzando la variabile "conton" (funzione scritta nel commento della variabile)
#include <math.h>
#include <stdlib.h>

#define ADD 1
#define SOT 2
#define MOL 3
#define DIV 4

int main ()
{
    int tiposegno;  //input del tipo di segno definito dal #define
    double num;
    int conton=0;      //di input, indica i diversi numeri per il calcolo della espressione
    double ris;      //di output, il risultato

    printf("Calcolatrice\nSi prega di inserire il primo numero da calcolare\n");
    scanf("%lf", &num);
    ris=num;

    while (tiposegno!=5)
    {
        system("cls");
        printf("\nLa quantita' di numeri  inserita e' %d e il risultato e' %lf\nQuale tipo di operazione vuoi eseguire?\n\n", conton, ris);
        printf("Se si vuole fare una adduzione inserire 1\nSe si vuole fare una sottrazione inserire 2\n");
        printf("Se si vuole fare una moltiplicazione inserire 3\nSe si vuole fare una divisione inserire 4\n");
        printf("Se si vuole uscire dal programma inserire 5\n");
        printf("Se si inserire un'altro numeri diverso da 1 a 5, si ricevera' un messaggio di errore \ne si richiedera' di nuovo un inserimento di un numero\n\n");
        scanf("%d", &tiposegno);

        //switch che serve a dare tutti i casi di operazioni
        switch (tiposegno)
        {
            case ADD:
                printf("\nAddizione\nInserire il numero\n");
                scanf("%lf", &num);
                conton = conton + 1;
                ris = ris + num;
                break;
            case SOT:
                printf("\nSottrazione\nInserire il numero\n");
                scanf("%lf", &num);
                conton = conton + 1;
                ris = ris - num;
                break;
            case MOL:
                printf("\nMoltiplicazione\nInserire il numero\n");
                scanf("%lf", &num);
                conton = conton + 1;
                ris = ris * num;
                break;
            case DIV:
                printf("\nDivisione\nInserire il numero\n");
                scanf("%lf", &num);
                conton = conton + 1;
                ris = ris / num;
                break;
            case 5:
                printf("");
            default:
                printf("\nIl numero inserito non e' disponibile\n");
        }
    }
    printf("\nIl risultato della tua espressione e' %lf", ris);

    return 0;
}
