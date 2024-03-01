#include "coda.h"
#include <iostream>
using namespace std;

int menu();

int main()
{
    Coda c1, c2(5);
    int dec, n;

    while (dec=menu())
    {
        switch (dec)
        {
        case 1:
            cout << endl
                 << "Inserisci un numero da mettere nell'array: ";

            cin >> n;

            c1.push(n);
            cout << endl;
            break;
        case 2:
            cout << endl
                 << "Inserisci un numero da mettere nell'array: ";

            cin >> n;

            c2.push(n);
            cout << endl;
            break;
        case 3:
            c1.pop();
            cout << endl;
            break;
        case 4:
            c2.pop();
            cout << endl;
            break;
        case 5:
            n=c1.top();

            cout << "L'elemento visualizzato e' " << n
                 << endl;
            break;
        case 6:
            n=c2.top();

            cout << "L'elemento visualizzato e' " << n
                 << endl;
            break;
        default:
            cout << endl 
                 << "Hai inserito un numero non esistente nella lista" << endl;
        }
    }
}

int menu()
{
    int d;
    system("cls");
    cout << "Inserire 1 per inserire l'elemento nella Coda1" << endl
         << "Inserire 2 per inserire l'elemento nella Coda2" << endl
         << "Inserire 3 per eliminare il primo elemento nella Coda1" << endl
         << "Inserire 4 per eliminare il primo elemento nella Coda2" << endl
         << "Inserire 5 per vedere il primo elemento nella Coda1" << endl
         << "Inserire 6 per vedere il primo elemento nella Coda2" << endl
         << "Inserire 0 per uscire" << endl
         << endl
         << "Inserimento: ";
    
    cin >> d;
    return d;
}