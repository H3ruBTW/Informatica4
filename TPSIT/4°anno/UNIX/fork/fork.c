#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//il programma non � completo oppure sbagliato, NON ESEGUIRE
int main()
{
    printf("PID processo padre: %d\n", getpid());

    int pid=fork();

    if(pid==0)
    {
        printf("PID processo figlio: %d\n", getpid());
        exit(10);
    }
    else if(pid>0)
    {
        printf("PID processo padre: %d\n", getpid());
    }
    else if(pid<0)
    {
        printf("Errore");
    }

    return 0;
}
