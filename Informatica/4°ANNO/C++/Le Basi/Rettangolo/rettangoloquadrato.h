#ifndef RETTANGOLOQUADRATO_H
#define RETTANGOLOQUADRATO_H

class Rettangolo
{
private:
    int base;
    int altezza;

public:
    Rettangolo();

    Rettangolo(double, double);
   
    void setBase(double base)
    {
        this->base = base;
    }

    void setAltezza(double altezza)
    {
        this->altezza = altezza;
    }

    double calcolaPerimetro()
    {
        return (base + altezza) * 2;
    }

    double calcolaArea()
    {
        return base * altezza;
    }

    double calcolaDiagonale()
    {
        return sqrt(pow(altezza, 2) + pow(base, 2));
    }

    void stampaTutto()
    {
        cout << "\nIl rettangolo con base " << base << " e altezza " << altezza << "\n\n";
        cout << "Perimetro: " << calcolaPerimetro() << "\n";
        cout << "Area: " << calcolaArea() << "\n";
        cout << "Diagonale: " << calcolaDiagonale() << "\n\n";
    }
}

#endif