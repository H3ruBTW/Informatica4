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
          << "Passo: " << c1.getPasso() << endl
          << endl
          << "Oggetto C2:" << endl
          << "Valore: " << c2.getValore() << endl
          << "Passo: " << c2.getPasso() << endl;

     cout << endl
          << "C1:";
     c1.inc();

     cout << endl
          << "C2:";
     c2.inc();

     cout << endl
          << "-- Post Incremento / Pre Decremento -- " << endl
          << "Oggetto C1:" << endl
          << "Valore: " << c1.getValore() << endl
          << "Passo: " << c1.getPasso() << endl
          << endl
          << "Oggetto C2:" << endl
          << "Valore: " << c2.getValore() << endl
          << "Passo: " << c2.getPasso() << endl;

     cout << endl
          << "C1:";
     c1.dec();

     cout << endl
          << "C2:";
     c2.dec();

     cout << endl
          << "-- Post Decremento -- " << endl
          << "Oggetto C1:" << endl
          << "Valore: " << c1.getValore() << endl
          << "Passo: " << c1.getPasso() << endl
          << endl
          << "Oggetto C2:" << endl
          << "Valore: " << c2.getValore() << endl
          << "Passo: " << c2.getPasso() << endl
          << endl;

     return 0;
}