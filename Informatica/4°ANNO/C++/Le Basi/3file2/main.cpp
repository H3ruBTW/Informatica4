#include <iostream>
#include "Contatore.h"

using namespace std;

int main()
{
    Contatore c1;
    Contatore c2(5);
    Contatore c3(10, 5);

    int n, n2;

    //set dei valori di c1
    cout << "C1\nScrivere il valore di partenza di \"c1\": ";
    cin >> n;
    cout << "Scrivere di quanto spostarsi da valore: ";
    cin >> n2;

    c1.setValore(n);
    c1.setPasso(n2);

    //incremento e decremento
    c1.inc();
    cout << endl;
    c1.dec();

    //stampa e distruttore
    cout << endl;
    c1.stampa();
    cout << endl;
    c1.~Contatore();
    cout << endl;

    //incremento e decremento
    cout << "C2\n";
    c2.inc();
    cout << endl;
    c2.dec();

    //stampa e distruttore
    cout << endl;
    c2.stampa();
    cout << endl;
    c2.~Contatore();
    cout << endl;

    //incremento e decremento
    cout << "C3\n";
    c3.inc();
    cout << endl;
    c3.dec();

    //stampa e distruttore
    cout << endl;
    c3.stampa();
    cout << endl;
    c3.~Contatore();
    cout << endl;

    Contatore c4(10, 5);
    cout << "C4\n";

    c4.stampa();
    cout << endl;
    c4.reset();
    cout << endl;
    c4.stampa();
    cout << endl;
    c4.~Contatore(); 
    cout << endl;

    return 0;
}