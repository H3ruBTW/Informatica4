package Cerchio;

public class volumeSfera extends areaCerchio {
    float altezza;

    volumeSfera(float raggio, float altezza){
        areaCerchio(raggio);
        this.altezza = altezza;
    }
}
