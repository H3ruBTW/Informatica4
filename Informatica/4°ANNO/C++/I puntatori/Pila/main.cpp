#include "pila.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int menu();

int main()
{
    Pila p1, p2(5);
    int dec, n;

    while (dec=menu())
    {
        switch (dec)
        {
        case 1:
            cout << endl
                 << "Inserisci un numero da mettere nell'array: ";

            cin >> n;

            p1.push(n);
            cout << endl;
            system("pause");
            break;
        case 2:
            cout << endl
                 << "Inserisci un numero da mettere nell'array: ";

            cin >> n;

            p2.push(n);
            cout << endl;
            system("pause");
            break;
        case 3:
            p1.pop();
            cout << endl;
            system("pause");
            break;
        case 4:
            p2.pop();
            cout << endl;
            system("pause");
            break;
        case 5:
            n=p1.top();

            cout << "L'elemento visualizzato e' " << n
                 << endl;
            system("pause");
            break;
        case 6:
            n=p2.top();

            cout << "L'elemento visualizzato e' " << n
                 << endl;
            system("pause");
            break;
        case 0:
            cout << endl 
                 << "Stai per uscire dal programma";
            break;
        default:
            cout << endl 
                 << "Hai inserito un numero non esistente nella lista" << endl;
            system("pause");
            break;
        }
    }
}

int menu()
{   
    int d;
    system("cls");
    cout << "Inserire 1 per inserire l'elemento nella Pila1" << endl
         << "Inserire 2 per inserire l'elemento nella Pila2" << endl
         << "Inserire 3 per eliminare l'ultimo elemento nella Pila1" << endl
         << "Inserire 4 per eliminare l'ultimo elemento nella Pila2" << endl
         << "Inserire 5 per vedere l'ultimo elemento nella Pila1" << endl
         << "Inserire 6 per vedere l'ultimo elemento nella Pila2" << endl
         << "Inserire 0 per uscire" << endl
         << endl
         << "Inserimento: ";
    
    cin >> d;
    return d;
}