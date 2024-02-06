#include <iostream>
#include "Contatore.h"
using namespace std;

int main()
{
    Contatore c1(0, 10);
    ContatoreDoppio c2;

    c2.setPasso(5);

    cout << "-- Pre Incremento --" << endl
         << "Oggetto C1:" << endl
         << "Valore: " << c1.getValore() << endl
         << "Passo: " << c1.getPasso();
    cout << "\n\nOggetto C2:" << endl
         << "Valore: " << c2.getValore() << endl
         << "Passo: " << c2.getPasso() << endl;

    cout << "C1:";
    c1.inc();

    cout << "C2:";
    c2.incrementaDoppio();

    cout << endl
         << "-- Post Incremento / Pre Decremento -- " << endl
         << "Oggetto C1:" << endl
         << "Valore: " << c1.getValore() << endl
         << "Passo: " << c1.getPasso() << endl
         << endl
         << "\n\nOggetto C2:" << endl
         << "Valore: " << c2.getValore() << endl
         << "Passo: " << c2.getPasso() << endl;

    cout << "C1:";
    c1.dec();

    cout << "C2:";
    c2.decrementaDoppio();

    cout << endl
         << "-- Post Decremento -- " << endl
         << "Oggetto C1:" << endl
         << "Valore: " << c1.getValore() << endl
         << "Passo: " << c1.getPasso() << endl
         << endl
         << "Oggetto C2:" << endl
         << "Valore: " << c2.getValore() << endl
         << "Passo: " << c2.getPasso() << endl;

    return 0;
}