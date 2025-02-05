package ES_01;

public class Tetraedro implements Runnable {
    double lato;
    double volumeTetraedo;

    public Tetraedro (double lato){
        this.lato = lato;
    }

    public void run(){
        volumeTetraedo = (Math.sqrt(2)/12)*Math.pow(lato, 3);
    }

    public double getVolume(){
        return volumeTetraedo;
    }
    
}
