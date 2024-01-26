#ifndef CONTATORE_H
#define CONTATORE_H

class Contatore {

    private:
        int passo;
        int valore;
    public:
        Contatore();
        Contatore(int valore);
        Contatore(int valore, int passo);
        ~Contatore();

        int getValore();
        void setValore(int);
        int getPasso();
        void setPasso(int);

        void reset();    //pone valore a zero
        void inc();       //incrementa l'attributo valore di tante unità quanto indicato nell'attributo passo
        void dec();      //decrementa l'attributo valore di tante unità quanto indicato nell'attributo passo
        void stampa();      //stampa il valore dei due attributi privati

};

#endif