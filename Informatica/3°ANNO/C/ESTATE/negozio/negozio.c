/** **************************************************************************
*\mainpage
*@brief Scrivi un programma per la gestione di un negozio di guanti di velo
*       Dopo aver fatto scrivere la quantita di guanti serviti mostrare il
*       prezzo per ogni tipo di materiale
*       cotone = 10 eur, pelle = 25 eur, neoprene = 30 eur
*       Scrivere il programma in due funzioni (lettura e elaborazione)
*
*@author Buongallino Alessandro
*@date 27/08/23
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

void qguanti (void);
void prezzi (int);

int main ()
{
    qguanti();

    return 0;
}

void qguanti (void)
{
    int n;

    printf("Benvenuto al negozio di guanti\n\n***ATTENZIONE*** SI PREGA DI INSERIRE UN NUMERO POSITIVO\n");
    do
    {
        printf("\nInserire la quantita' di guanti necessari: ");
        scanf("%d", &n);
    } while(n<1);


    prezzi(n);
}

void prezzi (int x)
{
    printf("\n1. %d guanto/i in cotone: %d eur\n2. %d guanto/i in pelle: %d eur\n3. %d guanto/i in neoprene: %d eur\n\n",x,x*10,x,x*25,x,x*30);
    system("pause");
}
