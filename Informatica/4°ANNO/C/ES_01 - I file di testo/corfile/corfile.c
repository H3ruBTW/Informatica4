/** ****************************************************************************************
* \mainpage corfile
*
* @brief Scrivere funzioni descritte su classroom
*
* @author Buongallino Alessandro
* @date 22/11/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------------------
//=== COSTANTI =============================================================================
//------------------------------------------------------------------------------------------
#define N 10 //N record
#define N2 5 //N di voti

//------------------------------------------------------------------------------------------
//=== RECORDS ==============================================================================
//------------------------------------------------------------------------------------------
struct data
{
    int gg;
    int mm;
    int aa;

}typedef data;

struct stud
{
    char cog[20];
    data nas;
    int voti[N2];

}typedef stud;

/** ****************************************************************************************
* @brief Funzione che legga un file binario e sostituisca il cognome scritto dall'utente con
*        con un altro
* @param directory, cognome da sostituire, cognome sostituzione
* @retval n di cognomi modificati
*
* @author Buongallino Alessandro
*/
int fcorreggicog (char [], char [], char[]);

/** ****************************************************************************************
* @brief Funzione che fa riscrivere un record del file all'utente
* @param directory, numero di record
* @retval no return
*
* @author Buongallino Alessandro
*/
void friscrivir (char [], int);

int main()
{
    char cog[20], cog2[20];
    int r, n;

    srand(time(NULL));

    fbinaryr("studenti.dat");

    /*printf("\n\nScrivi il nome da sostituire: ");
    scanf("%s", cog);

    printf("Scrivi il cognome con cui vuoi sostituirlo: ");
    scanf("%s", cog2);

    r=fcorreggicog("studenti.dat", cog, cog2);

    printf("\n\nIl cognome %s e' stato sostituito %d volte\n\n", cog, r);
    */

    printf("\n\nScrivi quale record vuoi riscrivere: ");
    scanf("%d", &n);

    printf("\n");

    friscrivir("studenti.dat", n-1);

    printf("\n\n");

    fbinaryr("studenti.dat");

    return 0;
}

int fcorreggicog (char dir[], char cog[], char sub[])
{
    FILE *in;
    stud s;
    int err, c=0;

    if((fopen_s(&in, dir, "rb+"))==0)
    {
        while(fread(&s, sizeof(stud), 1, in))
        {
            if(strcmp(s.cog, cog)==0)
            {
                err=fseek(in, -sizeof(stud), SEEK_CUR);

                c++;

                if(err==0)
                {
                    strcpy(s.cog, sub);

                    fwrite(&s, sizeof(stud), 1, in);
                }

                fseek(in, 0, SEEK_CUR);
            }
        }
    }

    fclose(in);

    return c;
}

void fbinaryr (char dir[])
{
    int err;
    FILE *out;
    stud s;

    err=fopen_s(&out, dir, "rb");

    if(err==0)
    {
        printf("Lettura di un file binario\n\n");

        while(fread(&s,sizeof(stud),1, out)>0)
        {
            printf("%15s |", s.cog);
            printf(" %2d/%2d/%4d | ", s.nas.gg, s.nas.mm, s.nas.aa);

            for(int i=0; i<N2; i++)
            {
                printf("%2d ", s.voti[i]);
            }

            printf("\n");
        }
    }

    fclose(out);
}

void friscrivir (char dir[], int n)
{
    FILE *in;
    stud s;
    int err, c=0;

    if((fopen_s(&in, dir, "rb+"))==0)
    {
        for(int i=0; fread(&s, sizeof(stud), 1, in) && i<n; i++);

        fseek(in, -sizeof(stud), SEEK_CUR);

        printf("Cognome: ");
        scanf("%s", s.cog);
        printf("Data di nascita\nGiorno: ");
        scanf("%d", &s.nas.gg);
        printf("Mese: ");
        scanf("%d", &s.nas.mm);
        printf("Anno: ");
        scanf("%d", &s.nas.aa);

        for(int j=0; j<N2; j++)
        {
            s.voti[j]=rand()%8+2;
        }

        fwrite(&s, sizeof(stud), 1, in);

        fseek(in, 0, SEEK_CUR);
    }

    fclose(in);
}
