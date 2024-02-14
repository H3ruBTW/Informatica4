package Main;
public class Main {
    public static void main(String[] args) {
        Veicolo v1 = new Veicolo("Fiat", 1987);
        Auto a1 = new Auto("Lamborghini", 2016, 2);
        Moto m1 = new Moto("Kawasaki", 2007, 649);

        v1.descrizione();
        System.out.println();
        a1.descrizione();
        System.out.println();
        m1.descrizione();
    }
}

class Veicolo {

    protected String marca;
    protected int annoProduzione;

    public Veicolo(String marca, int annoProduzione) {
        this.marca = marca;
        this.annoProduzione = annoProduzione;
    }

    public String getMarca() {
        return marca;
    }

    public int getAnnoProduzione() {
        return annoProduzione;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setAnnoProduzione(int annoProduzione) {
        this.annoProduzione = annoProduzione;
    }

    public void descrizione() {
        System.out.println("Veicolo");
        System.out.println("Marca: " + marca);
        System.out.println("Anno di Produzione: " + annoProduzione);
    }
}

class Auto extends Veicolo {

    private int numeroPosti;

    public Auto(String marca, int annoProduzione, int numeroPosti) {
        super(marca, annoProduzione);
        this.numeroPosti=numeroPosti;
    }

    public int getNumeroPosti()
    {
        return numeroPosti;
    }

    public void setNumeroPosti(int numeroPosti)
    {
        this.numeroPosti=numeroPosti;
    }

    @Override
    public void descrizione()
    {
        System.out.println("Veicolo");
        System.out.println("Tipo: Automobile");
        System.out.println("Marca: " + marca);
        System.out.println("Anno di Produzione: " + annoProduzione);
        System.out.println("Numero di posti: " + numeroPosti);
    }
}

class Moto extends Veicolo {

    private int cilindrata;

    public Moto(String marca, int annoProduzione, int cilindrata) {
        super(marca, annoProduzione);
        this.cilindrata=cilindrata;
    }

    public int getCilindrata()
    {
        return cilindrata;
    }

    public void setCilindrata(int cilindrata)
    {
        this.cilindrata=cilindrata;
    }

    @Override
    public void descrizione()
    {
        System.out.println("Veicolo");
        System.out.println("Tipo: Motocicletta");
        System.out.println("Marca: " + marca);
        System.out.println("Anno di Produzione: " + annoProduzione);
        System.out.println("Cilindrata: " + cilindrata);
    }
}