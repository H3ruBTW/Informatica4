/** ****************************************************************************************
* \mainpage ES_A
*
* @brief Scrivere una funzione che copia il file di testo in un altro
*
* @author Buongallino Alessandro
* @date 23/10/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "logs.h" //personalizzata per i messaggi di log

/** ****************************************************************************************
* @brief funzione che copia il file di testo in un altro
* @param  directory file
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int copiatxt (char [], char []);


int main()
{
    int r;


    r=copiatxt(NULL, NULL);

    if(r==0)
    {
        printf("\n\nOperazione effettuata con successo");
        return 0;
    }
    else
    {
        printf("\n\n***ERRORE***");
        return -1;
    }
}

int copiatxt (char filein[], char fileout[])
{
    FILE *in, *out;
    int err1, err2;
    char c;

    err1=fopen_s(&in, filein, "r");
    err2=fopen_s(&out, fileout, "w");

    fopenLog2f(err1, err2);

    if(err1+err2==0)
    {
        printf("Apertura con successo");
        while(!feof(in))
        {
            c=fgetc(in);
            getcLog(c, filein);
            if(c!=EOF)
            {
                fputc(c, out);
                putcLog(c, fileout);
            }

        }
        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);
    }
    else
    {
        printf("Codice errore: %d, %d", err1, err2);
        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);
        return -1;
    }

    return 0;
}
