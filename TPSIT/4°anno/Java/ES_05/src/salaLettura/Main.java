package salaLettura;

import java.util.Random;
import java.util.concurrent.Semaphore;

public class Main {
    public static void main(String[] args) {
        SalaLettura sala = new SalaLettura(2);

        for (int i = 0; i < 5; i++) {
            new Studente(sala).start();
        }
    }
}

class Studente extends Thread {
    private SalaLettura sala;

    public Studente (SalaLettura sala){
        this.sala = sala;
    }

    public void run(){
        sala.entra();
        sala.esce();
    }
}

class SalaLettura {
    
    private Semaphore semaphore;

    Random random = new Random();

    public SalaLettura(int posti){
        this.semaphore = new Semaphore(posti);
    }

    public void entra(){
        try {
            semaphore.acquire();
            System.out.println(Thread.currentThread().getName() + " è entrato nella sala");
            Thread.sleep((random.nextInt(4)+2)*1000);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void esce(){
        System.out.println(Thread.currentThread().getName() + " è uscito dalla sala");
        semaphore.release();
    }
}