/** ****************************************************************************************
* \mainpage ES_C
*
* @brief Scrivere una funzione che conta il numero di caratteri presenti nel file di testo
*
* @author Buongallino Alessandro
* @date 23/10/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/** ****************************************************************************************
* @brief funzione che conta i caratteri del file (esclusi spazi e a capo)
* @param  directory file
* @retval corretta apertura
*
* @author Buongallino Alessandro
*/
int contacharf(char []);

int main()
{
    int r;

    char filein[]={"in.txt"};

    r=contacharf(filein);

    if(r!=-1)
    {
        printf("\n\nOperazione effettuata con successo");
        return 0;
    }
    else
    {
        printf("\n\n***ERRORE***");
        system("pause");
        return -1;
    }
}

int contacharf(char filein[])
{
    int let=0, par=1, rig=1, err; //par e rig sono settati ad uno perchè non incrementano se c'è il carattere EOF
    int car;
    FILE *in;

    err=fopen_s(&in, filein, "r");

    if(err==0)
    {
        printf("Il file e' stato aperto correttamente\n\n");
        system("pause");

        while((car=fgetc(in))!=EOF)
        {
            if(car!='\n' && car!=' ')
                let++;
            if(car==' ')
                par++;
            if(car=='\n')
            {
                rig++;
                par++;
            }
        }

        fclose(in);

        printf("\n\nLettere: %d\nParole: %d\nRighe: %d", let, par, rig);

        return 1;
    }
    else
    {
        printf("Codici d'errore: %d", err);

        fclose(in);

        return -1;
    }
}
