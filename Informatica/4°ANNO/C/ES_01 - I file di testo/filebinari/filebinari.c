/** ****************************************************************************************
* \mainpage filebinari
*
* @brief Scrivere funzioni descritte su classroom
*
* @author Buongallino Alessandro
* @date 14/11/2023
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
* @brief Funzione che scrive N record in un file binario
* @param  directory
* @retval no return
*
* @author Buongallino Alessandro
*/
void fbinaryw (char []);

/** ****************************************************************************************
* @brief Funzione che legga un file binario e lo scriva su monitor
* @param  directory
* @retval no return
*
* @author Buongallino Alessandro
*/
void fbinaryr (char []);

/** ****************************************************************************************
* @brief Funzione che legga un file binario e restituisce l'ultima volta che compare
* @retval n record
*
* @author Buongallino Alessandro
*/
int fbinarynumr(char []);

int main ()
{
    char dir[]={"studenti.dat"};
    int r;

    srand(time(NULL));

    //fbinaryw(dir);

    fbinaryr(dir);

    r=fbinarynumr(dir);

    printf("\n\nIl file binario e' stato letto %d volte", r);

    return 0;
}

void fbinaryw (char dir[])
{
    int err;
    FILE *in;
    stud s;

    err=fopen_s(&in, dir, "wb");

    if(err==0)
    {
        printf("Copia in un file binario\n\n");

        for(int i=0; i<N; i++)
        {
            printf("Cognome: ");
            scanf("%s", s.cog);

            s.nas.gg=rand()%30+1;
            s.nas.mm=rand()%12+1;
            s.nas.aa=rand()%30+1990;

            for(int j=0; j<N2; j++)
            {
                s.voti[j]=rand()%8+2;
            }

            fwrite(&s, sizeof(stud), 1, in);

            system("cls");
        }
    }

    fclose(in);
}

void fbinaryr (char dir[])
{
    int err;
    FILE *out;
    stud s;

    err=fopen_s(&out, dir, "rb");

    printf("Lettura di un file binario\n\n");

    if(err==0)
    {
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

int fbinarynumr (char dir[])
{
    int err, i;
    FILE *out;
    stud s;

    err=fopen_s(&out, dir, "rb");

    if(err==0)
    {
        for(i=0; fread(&s, sizeof(stud), 1, out)>0; i++);
    }
    fclose(out);
    return i;
}
