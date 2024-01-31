package Operazioni;

public class Frazione {
    // Campi
    private int numeratore;
    private int denominatore;
    // Costruttore

    public Frazione(int numeratore, int denominatore) {
        this.numeratore = numeratore;
        this.denominatore = denominatore;
    }

    // Metodo per ottenere il numeratore
    public int getNumeratore() {
        return numeratore;
    }

    // Metodo per ottenere il denominatore
    public int getDenominatore() {
        return denominatore;
    }

    // Metodo per ottenere la rappresentazione testuale della frazione
    @Override
    public String toString() {
        return numeratore + "/" + denominatore;
    }

    // Metodo per semplificare la frazione 
    private Frazione semplifica(Frazione fraction)
    {
        int div;
        
        do
        {
            div=calcolaMCD(fraction.numeratore, fraction.denominatore);
            fraction.numeratore/=div;
            fraction.denominatore/=div;
        }while(div!=1);

        return fraction;
    }
    // Metodo per trovare l'MCD fra 2 numeri
    private int calcolaMCD(int x, int y) {

        int r;

        if (x < y) {
            int z = x;
            x = y;
            y = z;
        }

        do {
            r = x % y;

            if (r != 0) {
                x = y;
                y = r;
            }

        } while (r != 0);

        return y;
    }

    // Metodo per sommare due frazioni
    public Frazione somma(Frazione altraFrazione) {
        int nuovoNumeratore = this.numeratore * altraFrazione.denominatore
                + altraFrazione.numeratore * this.denominatore;
        int nuovoDenominatore = this.denominatore * altraFrazione.denominatore;

        Frazione nuovaFrazione = semplifica(new Frazione(nuovoNumeratore, nuovoDenominatore));

        return nuovaFrazione;
    }
    // Metodo per sottrarre due frazioni
    public Frazione sottrai(Frazione altraFrazione) {
        int nuovoNumeratore = this.numeratore * altraFrazione.denominatore
                - altraFrazione.numeratore * this.denominatore;
        int nuovoDenominatore = this.denominatore * altraFrazione.denominatore;

        Frazione nuovaFrazione = semplifica(new Frazione(nuovoNumeratore, nuovoDenominatore));

        return nuovaFrazione;
    }
    // Metodo per moltiplicare due frazioni
    public Frazione moltiplica(Frazione altraFrazione) {
        int nuovoNumeratore = this.numeratore * altraFrazione.numeratore;
        int nuovoDenominatore = this.denominatore * altraFrazione.denominatore;

        Frazione nuovaFrazione = semplifica(new Frazione(nuovoNumeratore, nuovoDenominatore));

        return nuovaFrazione;
    }
    // Metodo per dividere due frazioni
    public Frazione dividi(Frazione altraFrazione) {
        int nuovoNumeratore = this.numeratore * altraFrazione.denominatore;
        int nuovoDenominatore = this.denominatore * altraFrazione.numeratore;

        Frazione nuovaFrazione = semplifica(new Frazione(nuovoNumeratore, nuovoDenominatore));

        return nuovaFrazione;
    }
}
