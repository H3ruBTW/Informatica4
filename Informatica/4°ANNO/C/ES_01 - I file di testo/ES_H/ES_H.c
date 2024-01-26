/** ****************************************************************************************
* \mainpage ES_E
*
* @brief Scrivere due funzioni che criptano e decriptano utilizzando l'algoritmo di Cesare
*
* @author Buongallino Alessandro
* @date 25/10/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <logs.h> //libreria personalizzata per la creazione dei log
                  //le funzioni presenti sono le stesse dell'esercizio F e G

/** ****************************************************************************************
* @brief Funzione che cripta utilizzando l'algoritmo di Cesare
* @param  directory file, chiave
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int cesareCrypt (char [], char [], int);

/** ****************************************************************************************
* @brief Funzione che decripta utilizzando l'algoritmo di Cesare
* @param  directory file, chiave
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int cesareDecrypt (char [], char [], int);

int main(int argc, char *argv[])
{
    int r, ch=atoi(argv[3]);

    parametersLog(argc, argv);

    if(argc==5)
    {
        if(argv[4][0]=='c')
        {
            r=cesareCrypt(argv[1], argv[2], ch);

            if(r==0)
            {
                printf("\n\nOperazione effettuata correttamente\n\nIl file e' stato criptato\n\n");
                return 0;
            }
            else
            {
                printf("\n\n\n***Errore***");
                return -1;
            }
        }

        if(argv[4][0]=='d')
        {
            r=cesareDecrypt(argv[1], argv[2], ch);

            if(r==0)
            {
                printf("\n\nOperazione effettuata correttamente\n\nIl file e' stato decriptato\n\n");
                return 0;
            }

            else
            {
                printf("\n\n\n***Errore***");
                return -1;
            }
        }
    }
    else
    {
        if(argc>5)
        {
            printf("Troppi argomenti inseriti\n");
        }
        if(argc<5)
        {
            printf("Troppo pochi argomenti inseriti\n");
        }

        printf("L'inserimento dei parametri argv deve essere:\n");
        printf("[Directory File Source] [Directory File Destination] [Chiave] [c/d] (crypt/decrypt)");
    }

    return -2;
}

int cesareCrypt (char filein[], char fileout[], int ch)
{
    FILE *in, *out;
    int c;
    int err1, err2;

    err1=fopen_s(&in, filein, "r");
    err2=fopen_s(&out, fileout, "w");

    fopenLog2f(err1, err2);

    if(err1+err2==0)
    {
        printf("\n\nApertura con successo\n\n");
        system("pause");

        while ((c=fgetc(in))!=EOF)
        {
            getcLog(c, filein);

            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                //se l'addizione tra il codice ascii del carattere e la chiave
                //ha come risultato l'ascii tra questi caratteri significa che
                //la criptazione andrebbe oltre le lettere quindi effettua un decremento
                //cosicche rimanga nel regime delle lettere
                if((c+ch>'Z' && c+ch<'a') || c+ch>'z')
                {
                    fputc(c+ch-26, out);
                    putcLog(c+ch-26, fileout);
                }
                else
                {
                    fputc(c+ch, out);
                    putcLog(c+ch, fileout);
                }
            }
            else
            {
                fputc(c, out);
                putcLog(c, fileout);
            }
        }

        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);

        return 0;
    }
    else
    {
        printf("\n\nErrore nell'apertura");

        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);

        return -1;
    }
}

int cesareDecrypt (char filein[], char fileout[], int ch)
{
    FILE *in, *out;
    int c;
    int err1, err2;

    err1=fopen_s(&in, filein, "r");
    err2=fopen_s(&out, fileout, "w");

    fopenLog2f(err1, err2);

    if(err1+err2==0)
    {
        printf("\n\nApertura con successo\n\n");
        system("pause");

        while ((c=fgetc(in))!=EOF)
        {
            getcLog(c, filein);

            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                //se la sottrazione  tra il codice ascii del carattere e la chiave
                //ha come risultato l'ascii tra questi caratteri significa che
                //la decriptazione andrebbe oltre le lettere quindi effettua un incremento
                //cosicche rimanga nel regime delle lettere
                if((c-ch>'Z' && c-ch<'a') || c-ch<'A')
                {
                    fputc(c-ch+26, out);
                    putcLog(c-ch+26, fileout);
                }
                else
                {
                    fputc(c-ch, out);
                    putcLog(c-ch, fileout);
                }
            }
            else
            {
                fputc(c, out);
                putcLog(c, fileout);
            }
        }

        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);

        return 0;
    }
    else
    {
        printf("\n\nErrore nell'apertura");

        fclose(in);
        fcloseLog(filein);
        fclose(out);
        fcloseLog(fileout);

        return -1;
    }
}

