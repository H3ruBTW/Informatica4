//calcoloArea, calcoloPerimetro, calcoloDiagonale
#include <iostream>
#include <math.h>
using namespace std;

class Rettangolo {
private:
    double base;
    double altezza;
public:
    Rettangolo ()
    {
        base=1;
        altezza=1;
    };

    Rettangolo (double b, double h)
    {
        base=b;
        altezza=h;
    };

    void setBase(double n)
    {
        base=n;
    }

    void setAltezza(double n)
    {
        altezza=n;
    }

    void setBase2(double base)
    {
        this->base=base;
    }

    void setAltezza2(double altezza)
    {
        this->altezza=altezza;
    }

    double calcolaPerimetro ()
    {
        return (base+altezza)*2;
    }

    double calcolaArea ()
    {
        return base*altezza;
    }

    double calcolaDiagonale()
    {
        return sqrt(pow(altezza, 2)+pow(base, 2));
    }

    void stampaTutto ()
    {
        cout << "\nIl rettangolo con base " << base << " e altezza " << altezza << "\n\n";
        cout << "Perimetro: " << calcolaPerimetro() << "\n";
        cout << "Area: " << calcolaArea() << "\n";
        cout << "Diagonale: " << calcolaDiagonale() << "\n\n";
    }
};

int main()
{
    Rettangolo r1;
    int h, b;

    cout << "Scrivere la base: ";
    cin >> b;
    cout << "Scrivere l'altezza: ";
    cin >> h;

    r1.setBase(b);
    r1.setAltezza(h);

    r1.stampaTutto();

    cout << "Scrivere la base: ";
    cin >> b;
    cout << "Scrivere l'altezza: ";
    cin >> h;

    Rettangolo r2(b, h);

    r2.stampaTutto();

    Rettangolo r3;

    cout << "Scrivere la base: ";
    cin >> b;
    cout << "Scrivere l'altezza: ";
    cin >> h;

    r3.setBase2(b);
    r3.setAltezza2(h);

    r3.stampaTutto();

    return 0;
}



