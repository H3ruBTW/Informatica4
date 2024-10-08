/** **************************************************************************
*\mainpage
*@brief scrivere 8 funzioni
*
*@author Buongallino Alessandro
*@date 15/02/23
*@version 1.0
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/** ****************************************************************************************
* @brief Scrivere la funzione �int menu()� che visualizzi un men� e che chieda all�utente
*        un numero corrispondente all�operazione eseguire, 0 per uscire. Restituendo tale
*        valore al termine.
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
* @brief Scrivere una funzione che stampa i numeri palindromi a 2 cifre compresi tra 10 e 99
*
* @param  No parametri
* @retval No return
*
*@author Buongallino Alessandro
*@date 03/02/23
*@version 1.0
*/
void palidromi1099 (void);

/** ****************************************************************************************
* @brief Scrivere una funzione che stampa i numeri palindromi a 2 cifre compresi tra 100 e 999
*
* @param  No parametri
* @retval No return
*
*@author Buongallino Alessandro
*@date 01/03/23
*@version 1.0
*/
void palidromi100999 (void);

/** ****************************************************************************************
* @brief Scrivere una funzione che stampa i numeri palindromi a 2 cifre compresi tra 1000 e 9999
*
* @param  No parametri
* @retval No return
*
*@author Buongallino Alessandro
*@date 01/03/23
*@version 1.0
*/
void palidromi10009999 (void);

/** ****************************************************************************************
* @brief Scrivere una funzione che stampa i numeri palindromi a 2 cifre compresi tra 10 e 9999
*
* @param  No parametri
* @retval No return
*
*@author Buongallino Alessandro
*@date 01/03/23
*@version 1.0
*/
void palidromi109999 (void);


/** ****************************************************************************************
* @brief Scrivere una funzione che prende in input un numero intero e restituisce la sua
*        forma in binario.
*
* @param  il numero da trasformare in binario
* @retval No return
*
*@author Buongallino Alessandro
*@date 03/03/23
*@version 1.0
*/
void testbinario (void);
void binario (int);

/** ****************************************************************************************
* @brief scrive il contenuto del vettore
*
* @param  l'array e il numero di spazi dell'array utilizzati
* @retval No return
*
*@author Buongallino Alessandro
*@date 03/03/23
*@version 1.0
*/
void scrivivett (int [], int);

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

               palidromi1099();

               system("pause");
               system("cls");

               break;

        case 2:

               palidromi100999();

               system("pause");
               system("cls");

               break;

        case 3:

               palidromi10009999();

               system("pause");
               system("cls");

               break;
        case 4:

               palidromi109999();

               system("pause");
               system("cls");

               break;
        case 5:

               testbinario();

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
    printf("Inserire 1 per i numeri palindromi da 10 a 99\n");
    printf("Inserire 2 per i numeri palindromi da 100 a 999\n");
    printf("Inserire 3 per i numeri palindromi da 1000 a 9999\n");
    printf("Inserire 4 per i numeri palindromi da 10 a 9999\n");
    printf("Inserire 5 per il calcolatore binario\n");
    printf("Inserire 0 per uscire dal programma\n");

    scanf("%d", &sce);

    return sce;
}
void palidromi1099(void)
{
    int num, c1, c2;

    printf("\n");

    for(num=10; num<100; num++)
    {
        c1=num/10;
        c2=num%10;

        if(c1==c2)
            printf("%d ",num);
    }
    printf("\n\n");
}
void palidromi100999 (void)
{
    int num, c1, c2;

    printf("\n");

    for(num=100; num<1000; num++)
    {
        c1=num/100;
        c2=num%10;

        if(c1==c2)
            printf("%d ",num);
    }
    printf("\n\n");
}
void palidromi10009999(void)
{
    int n,a1,b1,b2,a2;

    printf("\n");

    for(n=1000;n<=9999;n++)
    {
        a1=n/1000;
        b1=(n-(a1*1000))/100;
        b2=(n-((a1*1000)+(b1*100)))/10;
        a2=n-((a1*1000)+(b1*100)+(b2*10));

        if(a1==a2&&b1==b2)
        {
            printf("%d ", n);
        }
    }

    printf("\n\n");
}
void palidromi109999(void)
{
    int n,c1,c2,c3,c4;

    printf("\n");

    for(n=10;n<10000;n++)
    {
        if(n<100)
        {
            c1=n/10;
            c2=n%10;

            if(c1==c2)
                printf("%d ",n);
        }
        else
        {
            if(n<1000)
            {
                c1=n/100;
                c2=n%10;

                if(c1==c2)
                    printf("%d ",n);
            }
            else
            {
                c1= n/1000;
                c2=(n-(c1*1000))/100;
                c3=(n-((c1*1000)+(c2*100)))/10;
                c4= n-((c1*1000)+(c2*100)+(c3*10));

                if(c1==c4&&c2==c3)
                {
                    printf("%d ", n);
                }
            }
        }

        if (n==100)
            printf("\n");

        if (n==1000)
            printf("\n");
    }

    printf("\n\n");
}
void testbinario(void)
{
    int n;

    printf("\nCalcolatore binario\nInserire un numero da trasformare: ");
    scanf("%d",&n);

    binario(n);
}
void binario(int x)
{
    int vett[1000], cont;

    if(x==0)
        printf("0");

    for(cont=0; x>0;cont++)
    {
        vett[cont]=x%2;
        x/=2;
    }

    scrivivett(vett,cont);

    printf("\n");
}
void scrivivett(int vet[], int x)
{
    int cont;

    for(cont=x-1; cont>=0; cont--)
    {
        printf("%d", vet[cont]);
    }
}
