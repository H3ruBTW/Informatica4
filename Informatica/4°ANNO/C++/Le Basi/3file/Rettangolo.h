#ifndef RETTANGOLO_H
#define RETTANGOLO_H

class Rettangolo {

    private:
        double base;
        double altezza;
    public:
        Rettangolo();
        Rettangolo(double);
        Rettangolo(double, double);

        void setAltezza(double);
        void setBase(double);

        double getAltezza();
        double getBase();

        double calcoloPerimetro();
        double calcoloArea();
        double calcolaDiagonale();

        void setTutto(double altezza=1, double base=1)
        {
            this->altezza=altezza;
            this->base=base;
        }
};

#endif 