/** **************************************************************************
\mainpage MCD DIVISORI AREA RETTANGOLO
@brief creazione di 4 funzioni che creino all'inizio un menu di navigazione,
       calcolino il MCD, l'area del rettangolo etrovino i divisori,
       in seguito chiedere all'utente di inserire
       i valori necessari per ogni funzione e stampare poi il risultato

@author Buongallino Alessandro
@date 13/01/23
@version 1.0
**/

#include <stdio.h>
#include <stdlib.h>

//funzione che trova il MDC di 2 numeri interi messi in input utilizzando l'algoritmo
//di Euclide
int mcd (int, int);

//funzione che prende in input un numero intero e restituisce la somma dei
//suoi divisori
int somma_divisori (int);

//funzione che prende in input 2 numeri interi (rispettivamente l'altezza e la base)
//e trova l'area di un rettangolo
int area_rettangolo (int,int);

//Scrivere la funzione “int menu()” che visualizzi un menù e che chieda all’utente
//un numero corrispondente all’operazione eseguire, 0 per uscire. Questo valore va restituito.
int menu(void);

int main()
{
    int sce; //variabile "scelta" serve come variabile
             //di uscita della funzione "menu"
    int n1,n2;
    int ris;//variabile "risultato"

    do
    {
        //chiamata della funzione "menu"
        sce=menu();

        switch (sce)
        {
            case 0:
                printf("\nUscita in corso");

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
                //sezione del MCD
                printf("\nMCD\nInserire il primo numero\n");
                scanf("%d", &n1);
                printf("Inserire il secondo numero\n");
                scanf("%d", &n2);

                //chiamata della funzione "mcd"
                ris=mcd(n1,n2);

                printf("Il MCD di %d e %d e' %d\n\n", n1, n2, ris);
                //questa istruzione utilizza un comando del CMD per fermare il programma
                //finche non viene premuto un qualsiasi tasto
                system ("pause");
                //questa istruzione utilizza un comando del CMD per rimuovere tutto quello
                //scritto sullo schermo
                system ("cls");
                break;
            case 2:
                //sezione della somma di divisori
                printf("\nSomma di divisori\nInserire un numero\n");
                scanf("%d", &n1);

                //chiamata della funzione "somma_divisori"
                ris=somma_divisori(n1);

                printf("La somma dei divisori di %d e' %d\n\n", n1, ris);
                //questa istruzione utilizza un comando del CMD per fermare il programma
                //finche non viene premuto un qualsiasi tasto
                system ("pause");
                //questa istruzione utilizza un comando del CMD per rimuovere tutto quello
                //scritto sullo schermo
                system ("cls");
                break;
            case 3:
                //sezione dell'area del rettangolo
                printf("\nArea del rettangolo\nInserire l'altezza\n");
                scanf("%d", &n1);
                printf("Inserire la base\n");
                scanf("%d", &n2);

                //chiamata della funzione "area_rettangolo"
                ris=area_rettangolo(n1,n2);

                printf("L'area del rettangolo con altezza %d e base %d e' %d\n\n", n1, n2, ris);
                //questa istruzione utilizza un comando del CMD per fermare il programma
                //finche non viene premuto un qualsiasi tasto
                system ("pause");
                //questa istruzione utilizza un comando del CMD per rimuovere tutto quello
                //scritto sullo schermo
                system ("cls");
                break;
            default:
                printf("\n***Errore***\n\n");
                //questa istruzione utilizza un comando del CMD per fermare il programma
                //finche non viene premuto un qualsiasi tasto
                system ("pause");
                //questa istruzione utilizza un comando del CMD per rimuovere tutto quello
                //scritto sullo schermo
                system ("cls");
        }
    }
    while (sce!=0);

    return 0;
}
int mcd (int x, int y)
{
    int resto;

    //algoritmo di euclide
    while (y!=0)
    {
        resto=x%y;
        x=y;
        y=resto;
    }

    return x;
}
int somma_divisori(int x)
{
    int cont;
    int ris=0;

    //per velocizzare il programma aggiungo subito al risultato
    //la variabile "x" perchè nel ciclo "for"
    //successivo verrà effettuato il controllo dal numero
    //1 fino alla metà di "x"
    ris+=x;

    for(cont=1;cont<=x/2;cont++)
    {
        if(x%cont==0)
            ris+=cont;
    }

    return ris;
}
int area_rettangolo(int x, int y)
{
    int ris;

    ris=x*y;

    return ris;
}
int menu(void)
{
    int ris;//variabile per la risposta

    printf("Funzioni\nInserire 1 per effettuare il MCD\nInserire 2 per effettuare la somma fra divisori\n");
    printf("Inserire 3 per effettuare il calcolo dell'area del rettangolo\nInserire 0 per uscire dal programma\n");
    scanf("%d", &ris);

    return ris;
}
