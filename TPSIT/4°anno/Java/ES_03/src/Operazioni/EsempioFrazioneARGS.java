package Operazioni;

public class EsempioFrazioneARGS {
    
    public static void main(String[] args) {
        
        if(args.length!=4)
        {
            System.out.println("Per avviare il programma, inserire 4 numeri interi indicanti i numeratori e i denominatori di due frazioni");
            System.out.println("Sintassi: numeratore1 denominatore1 numeratore2 denominatore2");
            System.exit(-3);
        }
        
        try
        {
            int n1 = Integer.parseInt(args[0]), d1 = Integer.parseInt(args[1]), n2 = Integer.parseInt(args[2]), d2 = Integer.parseInt(args[3]);
            
            Frazione frazione1 = new Frazione();

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
        }
        catch(Exception e)
        {
            System.out.println("Hai inserito un carattere non valido\nInserire solo numeri interi");
        } 
    }
}
