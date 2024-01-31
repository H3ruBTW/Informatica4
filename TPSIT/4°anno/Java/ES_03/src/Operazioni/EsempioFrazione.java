package Operazioni;

import java.util.Scanner;

public class EsempioFrazione {

    public static void main(String[] args) {
        int n1, n2, d1, d2;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Scrivi il numeratore della frazione 1: ");
        n1 = scanner.nextInt();
        System.out.print("Scrivi il denominatore della frazione 1: ");
        d1 = scanner.nextInt();
        System.out.print("Scrivi il numeratore della frazione 2: ");
        n2 = scanner.nextInt();
        System.out.print("Scrivi il denominatore della frazione 2: ");
        d2 = scanner.nextInt();

        // Creazione di due frazioni
        Frazione frazione1 = new Frazione(n1, d1);
        Frazione frazione2 = new Frazione(n2, d2);

        // Stampa delle frazioni
        System.out.println("Frazione 1: " + frazione1);
        System.out.println("Frazione 2: " + frazione2);

        /*Somma delle frazioni*/
        Frazione somma = frazione1.somma(frazione2);
        System.out.println("\nSomma: " + somma + " (semplificata)");

        /*Sottrazione delle frazioni*/
        Frazione sottrazione = frazione1.sottrai(frazione2);
        System.out.println("\nSottrazione: " + sottrazione + " (semplificata)");
        
        /*Moltiplicazione delle frazioni */
        Frazione moltiplica = frazione1.moltiplica(frazione2);
        System.out.println("\nMoltiplica: " + moltiplica + " (semplificata)");

        /*Somma delle frazioni*/
        Frazione dividi = frazione1.dividi(frazione2);
        System.out.println("\nDividi: " + dividi + " (semplificata)");

        scanner.close();
    }
}
