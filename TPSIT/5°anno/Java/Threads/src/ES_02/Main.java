package ES_02;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserisci il lato della base della piramide: ");
        double lato = scanner.nextDouble();

        System.out.print("Inserisci l'altezza della piramide: ");
        double altezza = scanner.nextDouble();

        Piramide piramide = new Piramide(lato, altezza);
        
        System.out.println("\nArea della base della piramide: " + piramide.areaQuadrato()); 
        System.out.println("\nArea della faccia triangolare: " + piramide.areaTriangolo()); 
        System.out.println("Perimetro della faccia triangolare: " + piramide.perimetroTriangolo()); 
        System.out.println("\nArea superficiale della piramide: " + piramide.superficiePiramide()); 
        System.out.println("Volume della piramide: " + piramide.volumePiramide());
    }
}
