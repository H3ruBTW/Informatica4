#include "calcolatrice.h"
#include <iostream>
using namespace std;

int main()
{
    double n;
    char c = ' ';
    cout << "Scrivi il primo numero: ";
    cin >> n;

    calcolatrice c1(n);

    while(c!='|')
    {
        cout << "\n\nPer uscire dal programma scrivere \"|\"" << endl;
        cout << "Inseririsci il segno dell'operazione piu' il numero (es.: \"+ 25\"): ";
        cin >> c;
        if(c!='|')
            cin >> n;
        fflush(NULL);

        switch(c)
        {
            case '+':
                c1.addizione(n);
                break;
            case '-':
                c1.sottrazione(n);
                break;
            case '*':
                c1.moltiplicazione(n);
                break;
            case '/':
                c1.divisione(n);
                break;
            case '|':
                break;
            default:
                cout << "\nHai inserito \"" << c << "\", ma non e' un carattere valido" << endl;   
        }
    }

    cout << "\n\nIl risultato ricavato dalla calcolatrice c1 e' uguale a " << c1.getRis() << endl;

    return 0;
}