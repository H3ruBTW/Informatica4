package Operazioni;

import java.util.Scanner;

public class EsempioFrazione {

    public static void main(String[] args) {
        int n1, n2, d1, d2;
        Frazione frazione1 = new Frazione();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Scrivi il numeratore della frazione 1: ");
        n1 = scanner.nextInt();
        System.out.print("Scrivi il denominatore della frazione 1: ");
        d1 = scanner.nextInt();
        System.out.print("Scrivi il numeratore della frazione 2: ");
        n2 = scanner.nextInt();
        System.out.print("Scrivi il denominatore della frazione 2: ");
        d2 = scanner.nextInt();

        // Set della frazione 1
        frazione1.setNumeratore(n1);
        frazione1.setDenominatore(d1);

        // Creazione di una frazione con costruttore con due parametri
        Frazione frazione2 = new Frazione(n2, d2);

        // Controllo per vedere se è stato inserito 0 tra le frazioni
        if(frazione1.getDenominatore()==0 || frazione1.getNumeratore()==0)
        {
            System.out.println("\nHai inserito uno 0 nella frazione1, il programma verrà chiuso per evitare eventuali errori.");
            System.exit(-1);
        }
        if(frazione2.getDenominatore()==0 || frazione2.getNumeratore()==0)
        {
            System.out.println("\nHai inserito uno 0 nella frazione2, il programma verrà chiuso per evitare eventuali errori.");
            System.exit(-2);
        }

        // Stampa delle frazioni
        System.out.println("\nFrazione 1: " + frazione1);
        System.out.println("Frazione 2: " + frazione2);

        /* Somma delle frazioni */
        Frazione somma = frazione1.somma(frazione2);
        System.out.println("\nSomma: " + somma + " (semplificata)");

        /* Sottrazione delle frazioni */
        Frazione sottrazione = frazione1.sottrai(frazione2);
        System.out.println("\nSottrazione: " + sottrazione + " (semplificata)");

        /* Moltiplicazione delle frazioni */
        Frazione moltiplica = frazione1.moltiplica(frazione2);
        System.out.println("\nMoltiplica: " + moltiplica + " (semplificata)");

        /* Somma delle frazioni */
        Frazione dividi = frazione1.dividi(frazione2);
        System.out.println("\nDividi: " + dividi + " (semplificata)");

        scanner.close();
    }
}
