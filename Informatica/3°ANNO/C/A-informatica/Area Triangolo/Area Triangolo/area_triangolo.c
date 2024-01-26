/* Buongallino Alessandro

   Trovare l'area del triangolo sia in caso di altezza e base
   sia in caso dei 3 lati di quest'ultimo e infine stampare il risultato

   Input: 2 interi (base e altezza) o 3 interi (lati del triangolo)
   Elaborazione: Formule per calcolo dell'area del triangolo
   Outout: 1 intero (area del triangolo)
*/

#include <stdio.h>//include printf, scanf, switch
#include <math.h>//include sqrt(radice quadrata), pow (potenza)

int main (){
// dichiaramo le variabili
float bas, alt; //caso base e altezza
float l1, l2, l2div2, l2pot2; // caso lati del triangolo
float ris; //output

int caso1, casl; //indicare il caso base e altezza o lati (variabili di lavoro)

    printf("Calcolo area triangolo\nSe si posseggono la base e l'altezza scrivere con la tastiera il numero 1\nse invece si posseggono i lati scrivere il numero 2\n");
    scanf("%d", &caso1);

    //indico le due possibilita (altezza e base o i lati)
  switch (caso1) {
    //indico il caso in cui si utilizza la base e l'altezza
    case 1:
        printf("Triangolo\nScrivere il valore dell'altezza\n");
        scanf("%f", &alt);
        printf("Scrivere il valore della base\n");
        scanf("%f", &bas);

        //assegno il risultato
        ris=alt*bas/2;

        printf("L'area del triangolo e' uguale a %.10f", ris);

        //termino il programma
        break;
    //indico il caso in cui si utilizzano i lati
    case 2:
        printf("Calcolo dell'area del triangolo avendo i lati\nSe si ha un triangolo equilatero scrivere 1\nse si ha un triangolo isoscele scrivere 2\n");
        printf("se si ha un triangolo rettangolo scrivere 3\n");
        scanf("%d", &casl);
            //indico i casi per capire il triangolo che ha l'utente
            switch (casl) {
              //indico il caso in cui, l'utente, ha un triangolo equilatero
              case 1:
                printf("Triangolo equilatero\nScrivere il valore del lato\n");
                scanf("%f", &l1);

                //assegno il teorema di pitagora per trovare il risultato
                l2=l1;
                l1= pow (l1, 2);
                l2div2= l2/2;
                l2pot2= pow (l2div2, 2);
                ris=sqrt(l1+l2pot2)*l2/2;

                printf("L'area del triangolo e' uguale a %.10f", ris);

                //termino il programma
             //   goto fine;
                break;
              //indico il caso in cui, l'utente, ha un triangolo isoscele
              case 2:
                printf("Triangolo isoscele\nScrivere il valore del lato lungo\n");
                scanf("%f", &l1);
                printf("Scrivere il valore della base\n");
                scanf("%f", &l2);

                //assegno il teorema di pitagora per trovare il risultato
                l1= pow (l1, 2);
                l2div2= l2/2;
                l2pot2= pow (l2div2, 2);
                ris=sqrt(l1+l2pot2)*l2/2;

                printf("L'area del triangolo e' uguale a %.10f", ris);

                //termino il programma
             //   goto fine;
                break;
              //indico il caso in cui, l'utente, ha un triangolo rettangolo
              case 3:
                printf("Triangolo rettangolo\nScrivere il valore del primo lato (non ipotenusa)\n");
    			scanf("%f", &l1);
    			printf("Scrivere il valore del secondo lato (non ipotenusa)\n");
    			scanf("%f", &l2);

    			//assegno il risultato dato dai due lati
    			ris=l1*l2/2;

    			printf("L'area del triangolo e' uguale a %.10f", ris);

    			//termino il programma
    		//	goto fine;
    			break;
              default:
                printf("La scelta è inesistente, riavviare il programma");
                return 0;
             }



        default:
        printf("La scelta è inesistente, riavviare il programma");
        return 0;
  }
        //termino il programma
      //  fine:
        return 0;
}
