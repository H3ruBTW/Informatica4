#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N1 20
#define N2 5
#define V 5

struct data
{
    int gg;
    char mm [N1];
    int aa;
}
typedef data;

struct s_alunno
{
    char nom[N1];
    char cog[N1];
    data nas;
    int voti[V];
}
typedef s_alunno;

void caricar (s_alunno []);
void stampar (s_alunno []);
int ricercacog (s_alunno [], char []);
int mediavoti (s_alunno []);
int studenti10 (s_alunno []);
void caricatr (s_alunno []);
void stampatr (s_alunno []);
void carica2 (s_alunno *);
void stampa2 (s_alunno);
void ordina (s_alunno []);

int main()
{
    s_alunno st[N2];
    int r;
    char s[N1];

    srand(time(NULL));
    /*
    caricar(st);
    stampar(st);
    printf("\n");
    system("pause");
    system("cls");

    caricatr(st);
    stampatr(st);
    printf("\n");
    system("pause");
    system("cls");

    printf("Scrivi cognome da ricercare: ");
    scanf("%s", s);

    r=ricercacog(st, s);

    if(r!=-1)
    {
        printf("%s\n", st[r].nom);
    }
    else
    {
        printf("Nome non trovato\n");
    }
    system("pause");
    system("cls");

    r=mediavoti(st);

    printf("%d studente/i ha/hanno una media maggiore o uguale a 6", r);

    r=studenti10(st);
    printf("%d studente/i ha/hanno almeno un 10", r);
    */

    caricar(st);
    ordina(st);
    stampar(st);


    return 0;
}

void caricar(s_alunno st[])
{
    for(int i=0; i<N2; i++)
    {
        printf("Scrivere il nome dello studente (NUMERO DI MATRICOLA %d): ", i+1);
        scanf("%s", st[i].nom);
        printf("\nScrivere il cognome dello studente: ");
        scanf("%s", st[i].cog);
        printf("\nScrivere la propria data di nascita\nGiorno: ");
        scanf("%d", &st[i].nas.gg);
        printf("Mese (accettato sia in modo numerico sia in modo scritto): ");
        scanf("%s", st[i].nas.mm);
        printf("Anno: ");
        scanf("%d", &st[i].nas.aa);
        for(int j=0; j<V; j++)
        {
            st[i].voti[j]=rand()%9+2;
        }
        printf("\n\n");
    }
}

void stampar (s_alunno st[])
{
    printf("           Nome:|         Cognome:|    GG:|            Mese:|      AA:| Voti:\n");
    for(int i=0; i<N2; i++)
    {
        printf("%15s | %15s | %5d | %15s | %8d | ", st[i].nom, st[i].cog, st[i].nas.gg, st[i].nas.mm, st[i].nas.aa);

        for(int j=0; j<V; j++)
        {
            printf("%2d ", st[i].voti[j]);
        }
        printf("\n");
    }
}

int ricercacog (s_alunno st[], char s[])
{
    for(int i=0; i<N2; i++)
    {
        if(strcasecmp(st[i].cog, s)==0)
        {
            return i;
        }
    }
    return -1;
}

int mediavoti (s_alunno st[])
{
    float med;
    int c;

    for(int i=0; i<N2; i++)
    {
        med=0;

        printf("La media di %s: ", st[i].cog);

        for(int j=0; j<V; j++)
        {
            med+=st[i].voti[j];
        }
        med/=(float)V;

        printf("%f\n", med);

        if(med>=6)
            c++;
    }
    return c;
}

int studenti10(s_alunno st[])
{
    int con, c=0;

    for(int i=0; i<N2; i++)
    {
        con=0;

        for(int j=0; j<V&&con==0; j++)
        {
            if(st[i].voti[j]==10)
            {
                c++;
                con=1;
            }
        }
    }
    return c;
}

void caricatr(s_alunno st[])
{
    for(int i=0; i<N2; i++)
    {
        carica2(&st[i]);
    }
}

void carica2 (s_alunno *st)
{
    printf("Scrivere il nome dello studente: ");
    scanf("%s", st->nom);
    printf("\nScrivere il cognome dello studente: ");
    scanf("%s", st->cog);
    printf("\nScrivere la propria data di nascita\nGiorno: ");
    scanf("%d", &st->nas.gg);
    printf("Mese (accettato sia in modo numerico sia in modo scritto): ");
    scanf("%s", st->nas.mm);
    printf("Anno: ");
    scanf("%d", &st->nas.aa);
    for(int i=0; i<V; i++)
    {
        st->voti[i]=rand()%9+2;
    }
    printf("\n\n");
}

void stampatr(s_alunno st[])
{
    for(int i=0; i<N2; i++)
    {
        stampa2(st[i]);
    }
}

void stampa2(s_alunno st)
{
    printf("%15s | %15s | %5d | %15s | %8d | ", st.nom, st.cog, st.nas.gg, st.nas.mm, st.nas.aa);

    for(int i=0; i<V; i++)
    {
        printf(" %2d ", st.voti[i]);
    }
    printf("\n");
}

void ordina(s_alunno st[])
{
    s_alunno lav;

    for(int i=0; i<N2-1; i++)
    {
        for(int j=i+1; j<N2; j++)
        {
            if(strcasecmp(st[i].cog, st[j].cog)>0)
            {
                lav=st[i];
                st[i]=st[j];
                st[j]=lav;
            }
        }
    }
}
