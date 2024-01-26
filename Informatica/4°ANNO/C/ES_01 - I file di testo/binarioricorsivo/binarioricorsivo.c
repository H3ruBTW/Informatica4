#include <stdio.h>

int binaryricorsiva (int[], int, int, int);

int main()
{
    int v[10], r;

    for(int i=0; i<10; i++)
    {
        v[i]=i+1;
    }

    r=binaryricorsiva(v, 0, 9, 2);

    if(r!=-1)
        printf("L'indice dove si trova il numero e': %d", r);
    else
        printf("Il numero non e' stato trovato");

    return 0;
}

int binaryricorsiva (int v[], int in, int fn, int n)
{
    int med=(in+fn)/2;

    if(in>fn)
        return -1;
    else
        if(v[med]==n)
            return med;
        else
            if(v[med]>n)
                return binaryricorsiva (v, in, med-1, n);
            else
                return binaryricorsiva (v, med+1, fn, n);
}
