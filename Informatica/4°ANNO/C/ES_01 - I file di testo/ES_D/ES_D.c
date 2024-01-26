/** ****************************************************************************************
* \mainpage ES_D
*
* @brief Scrivere una funzione che divide i numeri in un file in pari e dispari e li scrive
*        nel file pari.txt e dispari.txt
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
* @brief funzione che divide i numeri in un file in pari e dispari e li scrive
*        nel file pari.txt e dispari.txt
* @param  directory file
* @retval corretta apertura dei file o errore
*
* @author Buongallino Alessandro
*/
int fparidis (char [], char [], char []);

int main()
{
    char fnum[]={"numeri.txt"}, fpar[]={"pari.txt"}, fdisp[]={"dispari.txt"};
    int r;

    r=fparidis(fnum, fpar, fdisp);

    if(r==0)
    {
        printf("\nTrasferimento effettuato con successo");
        return 0;
    }
    else
    {
        printf("\n\n***ERRORE***");
        system("pause");
        return -1;
    }
}

int fparidis (char fnum[], char fpar[], char fdisp[])
{
    FILE *num, *par, *dis;
    int c;
    int err1, err2, err3;

    err1=fopen_s(&num, fnum, "r");
    err2=fopen_s(&par, fpar, "w");
    err3=fopen_s(&dis, fdisp, "w");

    if(err1+err2+err3==0)
    {
        printf("Apertura con successo\n\n");
        system("pause");

        while ((c=fgetc(num))!=EOF)
        {
            if(c>='0' && c<='9')
            {
                if(c%2==0)
                {
                    fputc(c, par);
                    fputc(' ', par);
                }
                else
                {
                    fputc(c, dis);
                    fputc(' ', dis);
                }
            }

        }

        fclose(num);
        fclose(par);
        fclose(dis);

        return 0;
    }
    else
    {
        printf("Errore nell'apertura");

        fclose(num);
        fclose(par);
        fclose(dis);

        return -1;
    }
}
