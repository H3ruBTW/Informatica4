#include <iostream>
#include <math.h>
using namespace std;

class Frazione
{
public:
    Frazione(){};

    int numeratore;
    int denominatore;

    void setNumDen(int a, int b)
    {
        numeratore=a;
        denominatore=b;
    }

    void stampa()
    {
        float x=(float)numeratore, y=(float)denominatore;

        cout << "\n" << numeratore << "\n";

        if(numeratore>denominatore)
        {
            for(int i=0; numeratore%(int)pow(10, i)!=numeratore; i++)
            {
                cout << "-";
            }
        }
        else
         {
            for(int i=0; denominatore%(int)pow(10, i)!=denominatore; i++)
            {
                cout << "-";
            }
        }

        cout << " = " << x/y << "\n" << denominatore;
    }
};

int main()
{
    Frazione f1, f2;

    int n1, n2;

    //1
    cout << "Inserire numeratore frazione 1: ";
    cin >> n1;
    cout << "Inserire denominatore frazione 1: ";
    cin >> n2;
    f1.setNumDen(n1, n2);
    cout << "Inserire numeratore frazione 2: ";
    cin >> n1;
    cout << "Inserire denominatore frazione 2: ";
    cin >> n2;
    f2.setNumDen(n1,n2);

    f1.stampa();
    cout << "\n";
    f2.stampa();
    cout << "\n\n";

    //2
    cout << "Inserire numeratore frazione 1: ";
    cin >> f1.numeratore;
    cout << "Inserire denominatore frazione 1: ";
    cin >> f1.denominatore;
    cout << "Inserire numeratore frazione 2: ";
    cin >> f2.numeratore;
    cout << "Inserire denominatore frazione 2: ";
    cin >> f2.denominatore;

    f1.stampa();
    cout << "\n";
    f2.stampa();
    cout << "\n\n";

    return 0;
}

