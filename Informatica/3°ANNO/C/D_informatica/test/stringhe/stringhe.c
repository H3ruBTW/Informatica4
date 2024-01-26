#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

void caricastr(char []);
void scrivistr(char []);

int main()
{
    char str1[N], str2[N];
    int ris, r;

    do
    {
        ris=menu();

        switch(ris)
        {
        case 0:
            printf("\nUscita in corso");

            //funzione sleep: il programma aspetta "x" secondi prima di passare alla prossima istruzione
            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);

            printf(".");

            fflush(stdout);
            sleep(1);
            break;

        case 1:
            caricastr(str1);
            system("pause");
            break;

        case 2:
            caricastr(str2);
            system("pause");
            break;

        case 3:
            scrivistr(str1);
            system("pause");
            break;

        case 4:
            scrivistr(str2);
            system("pause");
            break;

        case 5:
            system("cls");
            r=strlen(str1);
            printf("Il numero di lettere all'interno della stringa 2 e': %d\n\n", r);
            system("pause");
            break;

        case 6:
            system("cls");
            r=strlen(str2);
            printf("Il numero di lettere all'interno della stringa 2 e': %d\n\n", r);
            system("pause");
            break;

        case 7:
            system("cls");
            strcpy(str2, str1);
            break;

        case 8:
            system("cls");
            strcpy(str1, str2);
            break;

        case 9:
            system("cls");
            r=strcmp(str1, str2);
            if (r==-1)
                printf("La prima stringa parte prima\n");
            if (r==0)
                printf("La due stringhe sono uguali\n");
            if (r==1)
                printf("La seconda stringa parte prima\n");
            break;

        default:
            printf("\n|**|ERRORE|**|\n\nIl numero inserito non e' nell'elenco\n\n");
            system("pause");
            system("cls");
            break;
        }
    }while(ris!=0);
}
int menu(void)
{
    system("cls");
    int sce; //"scelta"

    printf("Menu' d'interazione\n");
    printf("Inserire 1 per caricare stringa 1\n");
    printf("Inserire 2 per caricare stringa 2\n");
    printf("Inserire 3 per scrivere quello che c'e all'interno della stringa 1\n");
    printf("Inserire 4 per scrivere quello che c'e all'interno della stringa 2\n");
    printf("Inserire 5 per vedere quante lettere sono presenti all'interno della stringa 1\n");
    printf("Inserire 6 per vedere quante lettere sono presenti all'interno della stringa 2\n");
    printf("Inserire 7 per copiare la stringa 1 nella stringa 2\n");
    printf("Inserire 8 per copiare la stringa 2 nella stringa 1\n");
    printf("Inserire 9 per confrontare le stringhe\n");
    printf("Inserire 0 per uscire dal programma\n");

    scanf("%d", &sce);

    return sce;
}
void caricastr(char st[])
{
    system("cls");
    printf("Carica stringa\n");
    scanf("%s", st);
}
void scrivistr(char st[])
{
    system("cls");
    printf("Scrittura di quello che c'e all'interno della stringa...\n\n");
    printf("%s\n\n", st);
}
