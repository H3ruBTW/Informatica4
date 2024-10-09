package Cerchio;

import java.util.*;

public class Principale {
    public static void main(String[] args) {
        float raggio, altezza;

        try(Scanner scanner = new Scanner(System.in)){
            System.out.print("Scrivere il raggio: ");
            raggio = scanner.nextFloat();
            System.out.print("Scrivere l'altezza: ");
            altezza = scanner.nextFloat();
        }

        AreaCerchio ObjCerchio = new AreaCerchio(raggio);
        VolumeCilindro ObjCilindro = new VolumeCilindro(raggio, altezza);
        VolumeSfera ObjSfera = new VolumeSfera(raggio);

        try {
            System.out.println("\nCalcolo...");
            System.out.println("\nArea del cerchio:    " + ObjCerchio.Area(raggio));
            System.out.println("Volume del Cilindro: " + ObjCilindro.Volume(raggio, altezza));
            System.out.println("Volume della sfera:  " + ObjSfera.Volume(raggio));
        } catch (Exception e) {
            System.err.println("Errore nel calcolo...\n" + e);
        }
    }
}
