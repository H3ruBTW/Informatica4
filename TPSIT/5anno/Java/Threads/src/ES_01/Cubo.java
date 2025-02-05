package ES_01;

public class Cubo implements Runnable {
    double lato;
    double volumeCubo;

    public Cubo (double lato){
        this.lato = lato;
    }

    public void run(){
        volumeCubo = Math.pow(lato, 3);
    }

    public double getVolume(){
        return volumeCubo;
    }
}
