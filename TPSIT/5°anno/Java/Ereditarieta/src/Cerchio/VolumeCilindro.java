package Cerchio;

public class VolumeCilindro extends AreaCerchio {
    float altezza;

    public VolumeCilindro(float raggio, float altezza) {
        super(raggio);
        this.altezza = altezza;
    }

    public void SetAltezza(float altezza) {
        this.altezza = altezza;
    }

    public float GetAltezza() {
        return altezza;
    }

    public float Volume(float raggio, float altezza) {
        float ris = super.Area(raggio) * altezza;
        return ris;
    }
}
