#ifndef CALCOLATRICE_H
#define CALCOLATRICE_H

class calcolatrice {
    private:
        double ris;
    public:
        calcolatrice(double);

        void addizione (double);
        void sottrazione (double);
        void moltiplicazione (double);
        void divisione (double);

        double getRis ();
};

#endif