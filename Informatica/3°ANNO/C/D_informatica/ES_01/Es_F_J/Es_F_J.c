/** **************************************************************************
*\mainpage MCD DIVISORI AREA RETTANGOLO
*@brief scrivere 5 funzione che hanno il compito di creare un menu, scrivere a
*       schermo x numeri della sequenza di fibonacci, una che trovi se il numero
*       è pari o dispari,uno che sommi e mostri i divisori di un numero inserito
*       e uno che trovi le coppie di numeri amicabili da 0 a 1500
*
*@author Buongallino Alessandro
*@date 27/01/23
*@version 1.0
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/** ****************************************************************************************
* @brief Scrivere la funzione “int menu()” che visualizzi un menù e che chieda all’utente
*        un numero corrispondente all’operazione eseguire, 0 per uscire. Restituendo tale
*        valore al termine.  Aggiungere alla funzione main le chiamate alle quattro funzioni
*        per testarle. Chiedere all'utente di inserire i valori necessari per ogni funzione
*        e stampare il risultato ottenuto.
*
* @param  No parametri
* @retval Scelta del utente (tipologia di funzione da eseguire)
*
*@author Buongallino Alessandro
*@date 27/01/23
*@version 1.0
*/
int menu(void);

/** ****************************************************************************************
* @brief Scrivere una funzione che prende in input un numero intero e restituisce la sua
*        sequenza di Fibonacci corrispondente stampandola a schermo.
*
* @param  La quantità di numeri della sequenza di fibonacci da scrivere
* @retval No return
*
*@author Buongallino Alessandro
*@date 03/02/23
*@version 1.0
*/
void testfibonacci (void);
void fibonacci (int);

/** ****************************************************************************************
* @brief Scrivere la funzione int pari_dispari(in numero), attraverso sottrazioni successive
*        determinare se il numero passato alla funzione è pari o dispari, restituire 0 se il
*        numero è pari, 1 se dispari.
*
* @param  Un numero intero
* @retval 1 o 0 dipendente se il numero è pari o dispari
*
*@author Buongallino Alessandro
*@date 03/02/23
*@version 1.0
*/
void testparidispari (void);
int paridispari (int);

/** ****************************************************************************************
* @brief Scrivere la funzione void stampa_divisori(int num) che stampi a schermo i suoi
*        divisori e la loro somma.
*
* @param Un numero intero (il numero di cui bisogna trovare i divisori)
* @retval La somma dei divisori
*
*@author Buongallino Alessandro
*@date 13/02/23
*@version 1.0
*/
void testdivisori (void);
int divisori (int);

/** ****************************************************************************************
* @brief Scrivere una funzione che trovi le coppie di numeri amici tra i numeri compresi
*        da 0 a 1500 e li visualizzi sullo schermo. Un numero amico è un numero intero
*        per il quale la somma dei divisori propri (escluso il numero stesso) è uguale
*        ad un altro numero intero, chiamato numero amico. Ad esempio, i numeri 220 e 284
*        sono amici perché la somma dei divisori propri di 220 è 1 + 2 + 4 + 5 + 10 + 11 +
*        20 + 22 + 44 + 55 + 110 = 284 e la somma dei divisori propri di 284 è 1 + 2 + 4 + 71
*        + 142 = 220.
*
*
* @param  No parametri
* @retval No return
*
*@author Buongallino Alessandro
*@date 13/02/23
*@version 1.0
*/
void numamici (void);

/** ****************************************************************************************
* @brief Effettua la somma divisori per facilitare l'utilizzo della funzione "numamici"
*
*
* @param  il numero di cui bisogna trovare la somma dei divisori
* @retval la somma dei divisori
*
*@author Buongallino Alessandro
*@date 13/02/23
*@version 1.0
*/
int sommadivisori (int);

int main()
{
    int ris; //"risultato"

    do
    {
        ris=menu();

        switch(ris)
        {
        case 0:printf("\nUscita in corso");

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

               testfibonacci();

               system("pause");
               system("cls");

               break;
        case 2:

               testparidispari();

               system("pause");
               system("cls");

               break;
        case 3:

               testdivisori();

               system("pause");
               system("cls");

               break;
        case 4:

               numamici();

               system("pause");
               system("cls");

               break;
        default:

                printf("\n|**|ERRORE|**|\n\nIl numero inserito non e' nell'elenco\n\n");

                system("pause");
                system("cls");

                break;
        }
    }while(ris!=0);

    return 0;
}
int menu(void)
{
    int sce; //"scelta"

    printf("Menu' d'interazione\n");
    printf("Inserire 1 per la sequenza di Fibonacci\n");
    printf("Inserire 2 per vedere se il numero e' pari o dispari\n");
    printf("Inserire 3 per vedere i divisori di un numero e le loro somme\n");
    printf("Inserire 4 per i numeri amici\n");
    printf("Inserire 0 per uscire dal programma\n");

    scanf("%d", &sce);

    return sce;
}
void testfibonacci (void)
{
    int qnum; //"quantità numeri"

    printf("\nFibonacci\nScrivere la quantita' di numeri da scrivere\n");
    scanf("%d", &qnum);

    fibonacci(qnum);
}
void fibonacci (int x)
{
    int n1=0, n2=1, cont;
    int ris;

    printf("\n%d ", n1);

    for(cont=1; cont<x; cont++)
    {
        ris=n1+n2;
        n2=n1;
        n1=ris;

        printf("%d ",ris);
    }

    printf("\n");
}
void testparidispari(void)
{
    int num, pari=0;
    printf("\nPari o Dispari\nInserire un numero\n");
    scanf("%d",&num);

    pari=paridispari(num);

    if(pari==0)
        printf("Il numero e' pari\n");
    if(pari==1)
        printf("Il numero e' dispari\n");
}
int paridispari(int x)
{
    if(x<0)
        x*=-1;

    while(x>1)
        x-=2;

    return x;
}
void testdivisori (void)
{
    int n1;
    int r;//"risultato"
    printf("\nDivisori e la loro somma\nInserisci un numero: ");
    scanf("%d", &n1);

    r=divisori(n1);

    printf("\nLa somma dei divisori e' %d\n\n", r);
}
int divisori (int x)
{
    int cont, somma=0;

    printf("\n");

    somma+=x;

    for(cont=1;cont<=x/2;cont++)
    {
        if(x%cont==0)
        {
            printf("%d ", cont);
            somma+=cont;
        }
    }

    printf("%d\n", x);

    return somma;
}
void numamici (void)
{
    int n1, n2, n3;

    printf("\n");

    for(n1=1;n1<=1500;n1++)
    {
        n2=sommadivisori(n1);
        n3=sommadivisori(n2);

        if(n1==n3&&n1!=n2)
            printf("%d e %d\n\n", n1, n2);
    }
}
int sommadivisori(int x)
{
    int cont;
    int ris=0;

    for(cont=1;cont<=x/2;cont++)
    {
        if(x%cont==0)
            ris+=cont;
    }

    return ris;
}
