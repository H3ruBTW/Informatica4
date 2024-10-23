package ES_01;

import java.util.Scanner;

public class CalcolaVolume {
    public static void main(String[] args) throws InterruptedException {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserisci il lato del cubo: ");
        double latoCubo = scanner.nextDouble();

        System.out.print("Inserisci il raggio della sfera: ");
        double raggioSfera = scanner.nextDouble();

        System.out.print("Inserisci il lato del tetraedro: ");
        double latoTetraedro = scanner.nextDouble();

        Cubo cubo = new Cubo(latoCubo);
        Thread t1 = new Thread(cubo); 
        
        Sfera sfera = new Sfera(raggioSfera);
        Thread t2 = new Thread(sfera); 

        Tetraedro tetraedro = new Tetraedro(latoTetraedro);
        Thread t3 = new Thread(tetraedro); 
  
        t1.start();
        t2.start();
        t3.start();

        System.out.println("\nVolume del cubo: " + cubo.getVolume());
        System.out.println("Volume della sfera: " + sfera.getVolume());
        System.out.println("Volume del tetraedo: " + tetraedro.getVolume());

        scanner.close();
    }
}
