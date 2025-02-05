package Cerchio;

public class VolumeSfera extends AreaCerchio {
    
    public VolumeSfera(float raggio) {
        super(raggio);
    }
    
    float Volume(float raggio){
        float ris = 4/3 * (float)Math.PI * (float)Math.pow(raggio, 3);
        return ris;
    }
}