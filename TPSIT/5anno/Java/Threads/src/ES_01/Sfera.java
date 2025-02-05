package ES_01;

public class Sfera implements Runnable {
    double raggio;
    double volumeSfera;

    public Sfera (double raggio){
        this.raggio = raggio;
    }

    public void run(){
        volumeSfera = 4/3 * Math.PI * Math.pow(raggio, 3);
    }

    public double getVolume(){
        return volumeSfera;
    }
}
