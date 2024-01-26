/** LIBRERIA DEI MESSAGGI LOG DI BUONGALLINO **/

#include <time.h>

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

void getcLog (int c, char dir [])
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

void putcLog (int c, char dir [])
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

        fprintf(LOG, "%.2d/%.2d %.2d:%.2d:%.2d - Inserito il carattere '%c' da \"%s\"\n", timeinfo->tm_mday, timeinfo->tm_mon+1,
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
