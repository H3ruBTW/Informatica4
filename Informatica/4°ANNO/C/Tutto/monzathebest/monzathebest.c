#include <stdio.h>
#include <math.h>

void deltapos (float [], float, float, float, float);
void deltazer (float [], float, float, float);

int main(int argc, char *argv[])
{
    float a=atoi(argv[1]), b=atoi(argv[2]), c=atoi(argv[3]), x[2], d;

    if(argc==4)
    {
        d=pow(b, 2)-4*a*c;

        if(d>0)
        {
            deltapos(x, a, b, c, d);
        }
        if(d==0)
        {
            deltazer(x, a, b, c);
        }
        if(d<0)
        {
            printf("Il delta e' negativo, l'equazione e' impossibile");
        }
    }
}

void deltapos (float x[], float a, float b, float c, float d)
{
    x[0]=(-1*b+sqrt(d))/(2*a);
    x[1]=(-1*b-sqrt(d))/(2*a);

    printf("x1 = %f\nx2 = %f", x[0], x[1]);
}

void deltazer (float x[], float a, float b, float c)
{
    x[0]=(-1*b)/(2*a);

    printf("x = %f\n", x[0]);
}
