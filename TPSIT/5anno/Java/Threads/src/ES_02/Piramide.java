package ES_02;

public class Piramide extends Quadrato implements Triangolo {

    double altezza;  

    public Piramide(double lato, double altezza){
        super(lato);
        this.altezza = altezza;
    }

    @Override
    public double areaTriangolo(){
        return lato*altezza/2;
    }

    @Override
    public double perimetroTriangolo(){
        return lato*3;
    }

    public double superficiePiramide(){
        return (2*perimetroQuadrato()*altezza)/2;
    }

    public double volumePiramide(){
        return areaQuadrato()*altezza/3;
    }
}
