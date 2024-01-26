#include <iostream>
#include "Rettangolo.h"
using namespace std;

int main()
{
    Rettangolo r1, r2(5), r3(5,10), r4;
    int base, altezza;

    cout << "Rettangolo 1\nScrivere l'altezza: ";
    cin >> altezza;
    r1.setAltezza(altezza);
    cout << "Scrivere la base: ";
    cin >> base;
    r1.setBase(base);
    cout << "\nRettangolo 1\nBase = " << base << "\nAltezza = " << altezza;
    cout << "\nPerimetro = " << r1.calcoloPerimetro() << "\nArea = " << r1.calcoloArea() << "\nDiagonale = " << r1.calcolaDiagonale();

    cout << "\n\nRettangolo 2\nBase = " << r2.getBase() << "\nAltezza = " << r2.getAltezza();
    cout << "\nPerimetro = " << r2.calcoloPerimetro() << "\nArea = " << r2.calcoloArea() << "\nDiagonale = " << r2.calcolaDiagonale();

    cout << "\n\nRettangolo 3\nBase = " << r3.getBase() << "\nAltezza = " << r3.getAltezza();
    cout << "\nPerimetro = " << r3.calcoloPerimetro() << "\nArea = " << r3.calcoloArea() << "\nDiagonale = " << r3.calcolaDiagonale();

    r4.setTutto();

    cout << "\n\nRettangolo 4\nBase = " << r4.getBase() << "\nAltezza = " << r4.getAltezza();
    cout << "\nPerimetro = " << r4.calcoloPerimetro() << "\nArea = " << r4.calcoloArea() << "\nDiagonale = " << r4.calcolaDiagonale() << endl;


    return 0;
}