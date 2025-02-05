package Cerchio;

public class AreaCerchio {
    float raggio;

    AreaCerchio(float raggio){
        this.raggio = raggio;
    }

    public void SetRaggio(float raggio) {
        this.raggio = raggio;
    }

    public float GetRaggio() {
        return raggio;
    }

    public float Area(float raggio) {
        float ris = (float)Math.PI * (float)Math.pow(raggio, 2);
        return ris;
    }
}