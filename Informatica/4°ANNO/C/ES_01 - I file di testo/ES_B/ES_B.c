/** ****************************************************************************************
* \mainpage ES_B
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

/** ****************************************************************************************
* @brief funzione che copia il file di testo in un altro e trasforma le lettere in maiuscoli
* @param  directory file
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int cpymaiutxt (char [], char []);

int main()
{
    int r;

    char filein[]={"nomi.txt"};
    char fileout[]={"nomi2.txt"};

    r=cpymaiutxt(filein, fileout);

    if(r==0)
    {
        printf("\n\nOperazione effettuata con successo\n\n");
        system("pause");
        return 0;
    }
    else
    {
        printf("\n\n***ERRORE***");
        return -1;
    }
}

int cpymaiutxt(char filein [], char fileout [])
{
    int err1, err2;
    FILE *in, *out;
    int c;

    err1=fopen_s(&in, filein, "r");
    err2=fopen_s(&out, fileout, "w");

    if(err1+err2==0)
    {
        printf("I file di testo sono stati aperti correttamente\n\n");
        system("pause");

        while(!feof(in))
        {
            c=fgetc(in);

            if(c>='a' && c<='z')
            {
                c-=32;
            }

            if(c!=EOF)
                fputc(c, out);
        }
        fclose(in);
        fclose(out);

        return 0;
    }
    else
    {
        printf("Codici d'errore: %d, %d", err1, err2);
        return -1;
    }
}
