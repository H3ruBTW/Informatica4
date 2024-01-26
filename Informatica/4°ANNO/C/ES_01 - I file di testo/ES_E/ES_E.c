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

int main()
{
    char filein[]={"in.txt"}, fileout1[]={"out1.txt"}, fileout2[]={"out2.txt"};
    int r, d1=0, d2, d3, ch;

    while(1)
    {
        if(d1==0)
        {
            system("cls");
            printf("Programma Crypt Decrypt Cesare\nInserire la chiave: ");
            scanf("%d", &ch);
            d1=1;
        }

            r=cesareCrypt(filein, fileout1, ch);

        if(r==0)
            printf("\n\nOperazione effettuata correttamente\n\nIl file e' stato criptato\n\n");
        else
        {
            printf("\n\n\n***Errore***");
            return -1;
        }
        system("pause");

        do
        {
            system("cls");
            printf("\n\nEffettuare una decriptazione in un'altro file? [1=si|0=no]\nInserimento: ");
            scanf("%d", &d2);

        }while(d2!=0 && d2!=1);

        if(d2==1)
        {
            r=cesareDecrypt(fileout1, fileout2, ch);
        }
        else
        {
            return 0;
        }

        do
        {
            system("cls");
            printf("\n\nContinuare? [1=si|0=no]\nInserimento: ");
            scanf("%d", &d3);

        }while (d3!=1 && d3!=0);

        if(d3==1)
        {
            do
            {
            system("cls");
            printf("\n\nSi vuole utilizzare la stessa chiave? [1=si|0=no]\nInserimento: ");
            scanf("%d", &d1);

            }while (d1!=0 && d1!=1);
        }
        else
        {
            return 0;
        }
    }
}

int cesareCrypt (char filein[], char fileout[], int ch)
{
    FILE *in, *out;
    int c;
    int err1, err2;

    err1=fopen_s(&in, filein, "r");
    err2=fopen_s(&out, fileout, "w");

    if(err1+err2==0)
    {
        printf("\n\nApertura con successo\n\n");
        system("pause");

        while ((c=fgetc(in))!=EOF)
        {
            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                //se l'addizione tra il codice ascii del carattere e la chiave
                //ha come risultato l'ascii tra questi caratteri significa che
                //la criptazione andrebbe oltre le lettere quindi effettua un decremento
                //cosicche rimanga nel regime delle lettere
                if((c+ch>'Z' && c+ch<'a') || c+ch>'z')
                {
                    fputc(c+ch-26, out);
                }
                else
                {
                    fputc(c+ch, out);
                }
            }
            else
            {
                fputc(c, out);
            }
        }

        fclose(in);
        fclose(out);

        return 0;
    }
    else
    {
        printf("\n\nErrore nell'apertura");

        fclose(in);
        fclose(out);

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

    if(err1+err2==0)
    {
        printf("\n\nApertura con successo\n\n");
        system("pause");

        while ((c=fgetc(in))!=EOF)
        {
            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                //se la sottrazione  tra il codice ascii del carattere e la chiave
                //ha come risultato l'ascii tra questi caratteri significa che
                //la decriptazione andrebbe oltre le lettere quindi effettua un incremento
                //cosicche rimanga nel regime delle lettere
                if((c-ch>'Z' && c-ch<'a') || c-ch<'A')
                {
                    fputc(c-ch+26, out);
                }
                else
                {
                    fputc(c-ch, out);
                }
            }
            else
            {
                fputc(c, out);
            }


        }

        fclose(in);
        fclose(out);
    }
    else
    {
        printf("\n\nErrore nell'apertura");

        fclose(in);
        fclose(out);

        return -1;
    }
}
