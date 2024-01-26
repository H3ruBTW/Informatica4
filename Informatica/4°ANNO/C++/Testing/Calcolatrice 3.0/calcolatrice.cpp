#include "calcolatrice.h"
#include <iostream>
using namespace std;

calcolatrice::calcolatrice(double n=1)
{
    ris=n;
}

void calcolatrice::addizione(double num)
{
    cout << "\n\n" << ris << " + ";
    ris+=num;
    cout << num << " = " << ris << endl;
}

void calcolatrice::sottrazione(double num)
{
    cout << "\n\n" << ris << " - ";
    ris-=num;
    cout << num << " = " << ris << endl;
}

void calcolatrice::moltiplicazione(double num)
{
    cout << "\n\n" << ris << " * ";
    ris*=num;
    cout << num << " = " << ris << endl;
}

void calcolatrice::divisione(double num)
{
    if(num!=0)
    {
        cout << "\n\n" << ris << " / ";
        ris/=num;
        cout << num << " = " << ris << endl;
    }
    else
        cout << "\n\nImpossibile dividere per 0" << endl;
        
    exit(-1);
}

double calcolatrice::getRis()
{
    return ris;
}