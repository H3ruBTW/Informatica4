#include <iostream>
#include <math.h>
using namespace std;

class Frazione
{
private:
    int numeratore;
    int denominatore;

public:
    Frazione(){};

    void setNumeratore(int a)
    {
        numeratore = a;
    }

    void setDenominatore(int a)
    {
        denominatore = a;
    }

    int getNumeratore()
    {
        return numeratore;
    }

    int getDenominatore()
    {
        return denominatore;
    }

    void setNumDen(int a, int b)
    {
        numeratore = a;
        denominatore = b;
    }

    int semplifica()
    {
        int r;

        r = trovaMCD(numeratore, denominatore);

        return r;
    }

    int trovaMCD(int x, int y)
    {
        int r;

        if (x < y)
        {
            int z = x;
            x = y;
            y = z;
        }

        do
        {
            r = x % y;

            if (r != 0)
            {
                x = y;
                y = r;
            }

        } while (r != 0);

        return y;
    }

    void stampa()
    {
        float x = (float)numeratore, y = (float)denominatore;

        cout << "\n"
             << numeratore << "\n";

        if (numeratore > denominatore)
        {
            for (int i = 0; numeratore % (int)pow(10, i) != numeratore; i++)
            {
                cout << "-";
            }
        }
        else
        {
            for (int i = 0; denominatore % (int)pow(10, i) != denominatore; i++)
            {
                cout << "-";
            }
        }

        cout << " = " << x / y << "\n"
             << denominatore;
    }
};

int main()
{
    Frazione f1, f2;

    int n1, n2;

    cout << "Inserire numeratore frazione 1: ";
    cin >> n1;
    cout << "Inserire denominatore frazione 1: ";
    cin >> n2;
    f1.setNumeratore(n1);
    f1.setDenominatore(n2);
    cout << "Inserire numeratore frazione 2: ";
    cin >> n1;
    cout << "Inserire denominatore frazione 2: ";
    cin >> n2;
    f2.setNumeratore(n1);
    f2.setDenominatore(n2);

    f1.stampa();
    cout << "\n";
    f2.stampa();

    cout << "\n\nL'MCD della prima frazione e': " << f1.semplifica();
    cout << "\nL'MCD della seconda frazione e': " << f2.semplifica() << endl;

    return 0;
}
