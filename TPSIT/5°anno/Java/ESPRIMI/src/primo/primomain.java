package primo;

public class primoMain {
    public static void main(String[] args) {
        primoFunc primo = new primoFunc();
        primoFunc primo2 = new primoFunc(5);
        primoFunc primo3 = new primoFunc(5,15);
        primoFunc primo4 = new primoFunc(5,7,9);
        primoFunc primo5 = new primoFunc(2,2,2,2);

        System.out.println("Il risultato è " + primo.somma2(3, 5));
        System.out.println("Il risultato è " + primo2.prod3(2, 2, 3));
    }
}
