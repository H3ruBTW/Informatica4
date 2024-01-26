/** **************************************************************************
*\mainpage
*@brief Esercizi sull'utilizzo delle stringhe (No string.h)
*
*@author Buongallino Alessandro
*@date 27/09/23
*@version 1.0
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

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

/** ****************************************************************************************
* @brief strlen()
*
* @param  Stringa
* @retval Lunghezza della stringa
*
*@author Buongallino Alessandro
*@date 27/09/23
*@version 1.0
*/
int lengstr (char []);

/** ****************************************************************************************
* @brief strcpy()
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 27/09/23
*@version 1.0
*/
void copystr (char [], char []);

/** ****************************************************************************************
* @brief strcmp()
*
* @param  Stringa
* @retval 1=s1>s2; -1=s1<s2; 0=(s1=s2)
*
*@author Buongallino Alessandro
*@date 11/10/23
*@version 1.0
*/
int cmpstr(char [], char []);

/** ****************************************************************************************
* @brief strcat()
*
* @param  Stringa
* @retval No return
*
*@author Buongallino Alessandro
*@date 11/10/23
*@version 1.0
*/
void catstr (char [], char []);

int main()
{
    char as[R][C]={"ciao", "Casa", "Solfanelli", "albero", "codice", "C", "computer", "cAlcolo", "stringa", "collaudo"};
    int r;
    int n1,n2;

    //1 e 2
    //carica(as);
    //stampa(as);

    /*3
    r=piuLunga(as);

    printf("La stringa piu' lunga rilevata e' %s(%d)", as[r], lengstr(as[r]));*/

    /*4
    printf("Inserire due indici di riga tra 0 e 9 da scambiare (le scelte devono essere staccate da uno spazio):");
    do
    {
        scanf("%d%d", &n1, &n2);

    } while(n1>9&&n2>9&&n1<0&&n2<0);

    scambia(as, n1, n2);
    stampa(as);*/

    /*5
    r=primaAlfabeto(as);

    printf("La stringa prima nell'ordine alfabetico e' %s(%d)", as[r], lengstr(as[r]));*/

    /*6
    ordina(as);
    stampa(as);
    */

    catstr(as[2], as[0]);

    printf("%s", as[2]);

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
        printf("%s(%d characters)\n", as[i], lengstr(as[i]));
    }
}

int piuLunga (char as[][C])
{
    int max=lengstr(as[0]), ind=0;

    for(int i=1; i<R; i++)
    {
        if(lengstr(as[i])>max)
        {
            max=lengstr(as[i]);
            ind=i;
        }
    }

    return ind;
}

void scambia (char as[][C], int k, int t)
{
    char sl[C];

    copystr(sl, as[k]);
    copystr(as[k], as[t]);
    copystr(as[t], sl);
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
    for(int i=0; i<R; i++)
    {
        for(int j=i+1; j<R; j++)
        {
            if(cmpstr(as[i], as[j])>0)
                scambia(as, i, j);
        }
    }
}

int lengstr (char s[])
{
    int i;

    for(i=0; s[i]!='\0'; i++);

    return i;
}

void copystr (char s1[], char s2[])
{
    int i;

    for(i=0; s2[i]!='\0'; i++)
    {
        s1[i]=s2[i];
    }

    s1[i]='\0';
}

int cmpstr(char s1[], char s2[])
{
    if(s1[0]>s2[0])
        return 1;
    else
    {
        if(s1[0]<s2[0])
            return -1;
        else
        {
            if(s1[0]==s2[0])
            {
                for(int i=1; s1[i]!='\0' && s2[i]!='\0'; i++)
                {
                    if(s1[i]>s2[i])
                        return 1;
                    if(s1[i]<s2[i])
                        return -1;
                }
            }
        }
    }

    return 0;
}

void catstr(char s1[], char s2[])
{
    int i=lengstr(s1);

    for(int j=0; s2[j]!='\0'; j++)
    {
        s1[i+j]=s2[j];
    }
}
