#include <stdio.h>
#include <stdlib.h>

#define N 20
#define V 5

struct data
{
    int giorno;
    char mese [N];
    int anno;
}
typedef data;

struct s_alunno
{
    char nom[N];
    char cog[N];
    data nascita;
    int voti[V];
}
typedef s_alunno;

void caricar (s_alunno *);
void stampar (s_alunno);

int main()
{
    srand(time(NULL));
    s_alunno stud1, stud2;

    caricar(&stud1);

    stud2=stud1;

    stampar(stud2);

    return 0;
}

void caricar(s_alunno *st)
{
    printf("Scrivere il nome dello studente: ");
    scanf("%s", st->nom);
    printf("\nScrivere il cognome dello studente: ");
    scanf("%s", st->cog);
    printf("\nScrivere la propria data di nascita\nGiorno: ");
    scanf("%d", &st->nascita.giorno);
    printf("Mese (accettato sia in modo numerico sia in modo scritto): ");
    scanf("%s", st->nascita.mese);
    printf("Anno: ");
    scanf("%d", &st->nascita.anno);
    for(int i=0; i<V; i++)
    {
        st->voti[i]=rand()%9+2;
    }
}

void stampar (s_alunno st)
{
    printf("\n\nCarta dello studente:\n\nNOME:%s %s", st.nom, st.cog);
    printf("\nDATA DI NASCITA:%d/%s/%d", st.nascita.giorno, st.nascita.mese, st.nascita.anno);
    printf("\nVOTI: ");
    for(int i=0; i<V; i++)
    {
        printf("%d ", st.voti[i]);
    }

}
