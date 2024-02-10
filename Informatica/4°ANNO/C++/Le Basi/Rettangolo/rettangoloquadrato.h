#ifndef RETTANGOLOQUADRATO_H
#define RETTANGOLOQUADRATO_H

class Rettangolo
{
private:
    double l1, l2, l3, l4; //1 e 3 base, 2 e 4 altezza

public:
    
    Rettangolo(double base=1, double altezza=1)
    {
        l1=base;
        l3=base;
        l2=altezza;
        l4=altezza;
    }
   
    void setBase(double);

    void setAltezza(double);

    double calcolaPerimetro();

    double calcolaArea();

    double calcolaDiagonale();

};

class Quadrato: public Rettangolo {

public:
    Quadrato(double lato = 1): Rettangolo(lato, lato);

    void setLati(double);

    double calcolaPerimetro();

    double calcolaArea();

    double calcolaDiagonale();
};

#endif