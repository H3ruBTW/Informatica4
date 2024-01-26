/* exec01_execl.c - © FB - 12/03/17  
 * Esempio di utilizzo della istruzione execl
 * int execl(char *pathname, char *arg0, ..char *argN, (char*)0);
 * - pathname è il nome (assoluto o relativo) dell’eseguibile da caricare
 * - arg0 è il nome del programma (argv[0]) 
 * - arg1, …, argN sono gli argomenti da passare al programma
 * - (char *)0 è il puntatore nullo che termina la lista
 */
#include <stdlib.h>  // exit
#include <stdio.h>   // printf
#include <unistd.h>  // execl

int main(int argc, char **argv) {

  int r=-1;

  for(int i=0; i<3; i++)
  {
    int pid = fork();

    if(pid==0)
    {
      r=i+1;
      break;
    }
  }

  if(r==1)
  {
    printf("\n[Figlio 1] Ho avviato il programma\n");
    if(execl("/home/4HINF_2023_24/buongallino.alessandro/ES_01/a_outs/a.out", "a.out", "rosso", "4", "1", (char *)0)==-1)
    {
      printf("exec fallita!\n");
      exit(112);
    }
  }
  else if(r==2)
  {
    printf("\n[Figlio 2] Ho avviato il programma\n");
    if(execl("/home/4HINF_2023_24/buongallino.alessandro/ES_01/a_outs/a.out", "a.out", "verde", "2", "1", (char *)0)==-1)
    {
        printf("exec fallita!\n");
        exit(112);
    }
  }
  else if(r==3)
  {
    printf("\n[Figlio 3] Ho avviato il programma\n");
    if(execl("/home/4HINF_2023_24/buongallino.alessandro/ES_01/a_outs/a.out", "a.out", "blu", "5", "1", (char *)0)==-1)
      {
          printf("exec fallita!\n");
          exit(112);
      }
  }
  else
    printf("\n[Padre] Ho creato i tre figli\n");

  exit(10);
}
 