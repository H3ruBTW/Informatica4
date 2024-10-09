package Cerchio;

public class areaCerchio {
    float raggio;

    areaCerchio(float raggio){
        this.raggio = raggio;
    }

    public void Set_Raggio(float raggio) {
        this.raggio = raggio;
    }

    public float Get_Raggio() {
        return raggio;
    }

    public float Area(float raggio) {
        float ris = ((float)Math.PI * raggio * raggio);
        return ris;
    }
}