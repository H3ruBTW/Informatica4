/** **************************************************************************
*\mainpage
*@brief Esercizi sull'utilizzo delle stringhe
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------------------
//=== COSTANTI =============================================================================
//------------------------------------------------------------------------------------------
#define R 10
#define C 20

/** ****************************************************************************************
* @brief nella funzione si chiedano all’utente R stringhe di lunghezza massima C-1
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
void carica(char [][C]);

/** ****************************************************************************************
* @brief stampa sul monitor le stringhe seguite dalla loro lunghezza. Curare la
*        visualizzazione su monitor
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
void stampa(char [][C]);

/** ****************************************************************************************
* @brief la funzione restituisce l’indice della riga dove è memorizzata la stringa più lunga
*        e visualizza nel main la stringa
*
* @param  Stringa
* @retval Indice della riga della stringa piu lunga
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
int piuLunga(char [][C]);

/** ****************************************************************************************
* @brief nella funzione si scambiano tra di loro le stringhe di indice k e t .
*        Eseguita la funzione la stringa della riga k+1 (indice k)  si trovi nella riga t+1
*        e quella della riga t+1 si trovi nella riga k+1
*
* @param  Stringa e due righe dell'array di stringhe
* @retval No return
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
void scambia(char [][C], int, int);

/** ****************************************************************************************
* @brief la funzione restituisce l’indice della stringa che è la prima in ordine alfabetico
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
int primaAlfabeto(char [][C]);

/** ****************************************************************************************
* @brief terminata l’esecuzione della funzione, tutte le stringhe sono in ordine alfabetico
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 26/09/23
*@version 1.0
*/
void ordina(char [][C]);



int main()
{
    char as[R][C]={"Cazzo", "Negro", "nAzista", "fascistA", "Comunista", "Immigrato", "Salvini", "BERLUSCONI", "Juventus", "MONZAMERDA"};
    int r;
    int n1,n2;

     stampa(as);

    /*1 e 2
    carica(as);
    stampa(as);

    //3
    r=piuLunga(as);

    printf("La stringa piu' lunga rilevata e' %s(%d)", as[r], strlen(as[r]));

    //4
    printf("Inserire due indici di riga tra 0 e 9 da scambiare (le scelte devono essere staccate da uno spazio):");
    do
    {
        scanf("%d%d", &n1, &n2);

    } while(n1>9&&n2>9&&n1<0&&n2<0);

    scambia(as, n1, n2);
    stampa(as);

    //5
    r=primaAlfabeto(as);

    printf("La stringa prima nell'ordine alfabetico e' %s(%d)", as[r], strlen(as[r]));*/

    //6
    ordina(as);
    stampa(as);

    return 0;
}

void carica (char as[][C])
{
    for(int i=0; i<R; i++)
    {
        printf("\nScrivere una parola (Numero %d). Max 19 Caratteri. \n\nInserimento: ", i+1);
        scanf("%s", as[i]);
    }
}

void stampa (char as[][C])
{
    printf("\n\n");

    for(int i=0; i<R; i++)
    {
        printf("%s(%d characters)\n", as[i], strlen(as[i]));
    }
}

int piuLunga (char as[][C])
{
    int max=strlen(as[0]), ind=0;

    for(int i=1; i<R; i++)
    {
        if(strlen(as[i])>max)
        {
            max=strlen(as[i]);
            ind=i;
        }
    }

    return ind;
}

void scambia (char as[][C], int k, int t)
{
    char sl[C];

    strcpy(sl, as[k]);
    strcpy(as[k], as[t]);
    strcpy(as[t], sl);
}

int primaAlfabeto(char as[][C])
{
    char max=as[0][0];
    int ind=0;

    for(int i=0; i<R; i++)
    {
        if(as[i][0]<max)
        {
            max=as[i][0];
            ind=i;
        }
    }
    return ind;
}

void ordina(char as[][C])
{
    int n, f1, f2, f3, m1, m2, m3, m4;

    for(int i=0; i<R-1; i++)
    {
        for(int j=i+1; j<C; j++)
        {
            n=1;
            m1=0;
            m2=0;
            f1=0;
            f2=0;
            if(as[i][0]>='A'&&as[i][0]<='Z')
            {
                m1=1;
            }
            if(as[j][0]>='A'&&as[j][0]<='Z')
            {
                m2=1;
            }
            if((m1==0&&m2==0)||(m1==1&&m2==1))
            {
                if(as[j][0]<as[i][0])
                    scambia(as, i, j);
                else
                {
                    if(as[j][0]==as[i][0])
                        f2=1;
                }
                f1=1;
            }
            if(m1==1&&m2==0&&f1==0)
            {
                if(as[j][0]<as[i][0]+32)
                    scambia(as, i, j);
                else
                {
                    if(as[j][0]==as[i][0]+32)
                        f2=1;
                }
                f1=1;
            }
            if(m1==0&&m2==1&&f1==0)
            {
                if(as[j][0]+32<as[i][0])
                    scambia(as, i, j);
                else
                {
                    if(as[j][0]+32==as[i][0])
                        f2=1;
                }
            }
            if(f2==1)
            {
                do
                {
                    f3=0;
                    m3=0;
                    m4=0;
                    if(as[i][n]>='A'&&as[i][n]<='Z')
                    {
                        m3=1;
                    }
                    if(as[j][n]>='A'&&as[j][n]<='Z')
                    {
                        m4=1;
                    }
                    if(as[j][n]=='\0'||as[i][n]=='\0')
                        f3--;
                    if((m3==0&&m4==0&&f3!=-1)||(m3==1&&m4==1&&f3!=-1))
                    {
                        if(as[j][n]<as[i][n])
                            scambia(as, i, j);
                        else
                        {
                            if((as[j][n]==as[i][n])&&(f3!=-1))
                                f3=1;
                        }
                    }
                    if((m3==1&&m4==0)&&(f3!=-1))
                    {
                        if(as[j][n]<as[i][n]+32)
                            scambia(as, i, j);
                        else
                        {
                            if((as[j][n]==as[i][n]+32)&&(f3!=-1))
                                f3=1;
                        }
                    }
                     if((m3==0&&m4==1)&&(f3!=-1))
                    {
                        if(as[j][n]+32<as[i][n])
                            scambia(as, i, j);
                        else
                        {
                            if((as[j][n]+32==as[i][n])&&(f3!=-1))
                                f3=1;
                        }
                    }
                    n++;
                }
                while(f3==1);
            }
        }
    }
}
