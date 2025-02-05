package ES_02;

public class Quadrato {
    double lato;

    public Quadrato(double lato){
        this.lato = lato;
    }

    public double areaQuadrato(){
        return lato*lato;
    }

    public double perimetroQuadrato(){
        return lato*4;
    }
}
