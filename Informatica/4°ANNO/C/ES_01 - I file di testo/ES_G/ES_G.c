/** ****************************************************************************************
* \mainpage ES_F e ES_G
*
* @brief Scrivere una funzione che copia il file di testo in un altro con inserimento parametri
*        argv e creazione di un file di Log
*
* @author Buongallino Alessandro
* @date 06/11/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** ****************************************************************************************
* @brief funzione che copia il file di testo in un altro
* @param  directory file
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int copiatxt (char [], char []);

/** ****************************************************************************************
* @brief scrittura in file log dei parametri argv
* @param  argv e argc
* @retval no return
*
* @author Buongallino Alessandro
*/
void parametersLog (int, char *[]);

/** ****************************************************************************************
* @brief scrittura in file log dei possibili errori di apertura
* @param  errori
* @retval no return
*
* @author Buongallino Alessandro
*/
void fopenLog2f (int, int);

/** ****************************************************************************************
* @brief scrittura in file log il carattere preso da un filein
* @param  carattere, nome file (directory)
* @retval no return
*
* @author Buongallino Alessandro
*/
void getcLog (char, char []);

/** ****************************************************************************************
* @brief scrittura in file log il carattere inserito in un fileout
* @param  carattere, nome file (directory)
* @retval no return
*
* @author Buongallino Alessandro
*/
void putcLog (char , char []);

/** ****************************************************************************************
* @brief scrittura in file log la chiusura dei file
* @param nome file (directory)
* @retval no return
*
* @author Buongallino Alessandro
*/
void fcloseLog (char []);

int main(int argc, char *argv[])
{
    int r;

    parametersLog(argc, argv);

    r=copiatxt(argv[1], argv[2]);

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

        while((c=fgetc(in)) != EOF)
        {
            getcLog(c, filein);
            fputc(c, out);
            putcLog(c, fileout);
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

void parametersLog (int argc, char *argv[])
{
    char dlog[]={"log.txt"};
    FILE *LOG;
    int err=0;

    err=fopen_s(&LOG, dlog, "a");

    if(err==0)
    {
        time_t rawtime;
        struct tm *timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );

        fprintf(LOG ,"%.2d/%.2d %.2d:%.2d:%.2d - I parametri sono ", timeinfo->tm_mday, timeinfo->tm_mon+1,
                                    timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

        for(int i=1; i<argc; i++)
        {
            fprintf(LOG, "%s ", argv[i]);
        }

        fprintf(LOG, "\n");
    }

    fclose(LOG);
}

void fopenLog2f (int e1, int e2)
{
    char dlog[]={"log.txt"};
    FILE *LOG;
    int err=0;

    err=fopen_s(&LOG, dlog, "a");

    if(err==0)
    {
        time_t rawtime;
        struct tm *timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );

        if(e1+e2==0)
        {
            fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Apertura con successo dei file\n", timeinfo->tm_mday, timeinfo->tm_mon+1,
                                                                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        }
        else
        {
            fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Errore apertura di uno dei file, Codice d'errore: %d %d\n", timeinfo->tm_mday,
                                                        timeinfo->tm_mon+1,timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, e1, e2);
        }
        fclose(LOG);
    }
}

void getcLog (char c, char dir [])
{
    char dlog[]={"log.txt"};
    FILE *LOG;
    int err=0;

    err=fopen_s(&LOG, dlog, "a");

    if(err==0)
    {
        time_t rawtime;
        struct tm * timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );

        fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Preso il carattere '%c' da \"%s\"\n", timeinfo->tm_mday, timeinfo->tm_mon+1,
                                                                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, c, dir);

        fclose(LOG);
    }
}

void putcLog (char c, char dir [])
{
    char dlog[]={"log.txt"};
    FILE *LOG;
    int err=0;

    err=fopen_s(&LOG, dlog, "a");

    if(err==0)
    {
        time_t rawtime;
        struct tm * timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );

        fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Inserito il carattere '%c' in \"%s\"\n", timeinfo->tm_mday, timeinfo->tm_mon+1,
                                                                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, c, dir);
        fclose(LOG);
    }
}

void fcloseLog (char dir [])
{
    char dlog[]={"log.txt"};
    FILE *LOG;
    int err=0;

    err=fopen_s(&LOG, dlog, "a");

    if(err==0)
    {
        time_t rawtime;
        struct tm * timeinfo;
        time( &rawtime );
        timeinfo = localtime( &rawtime );

        fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Chiuso il file \"%s\"\n", timeinfo->tm_mday, timeinfo->tm_mon+1,
                                                                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, dir);
        fclose(LOG);
    }
}


