package Array;
import java.util.Scanner;

/**
 * EserciziArray
 */
public class EserciziArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n;

        do
        {
            System.out.print("\nScrivi il numero di elementi dell'array: ");
            n=scanner.nextInt();
        }while(n<=0);

        Array array = new Array(n);

        double a[]= new double[n];

        array.random(a);
        
        array.stampa(a);

        System.out.println();

        System.out.println("\nLa somma dei numeri trovati = " + array.somma(a));
        System.out.println("\nLa somma dei numeri negativi trovati = " + array.negativi(a));
        System.out.println("\nIl numero massimo nell'array = " + array.massimo(a));

        scanner.close();
    }
}

class Array 
{
    private int n;

    public Array(int n){this.n=n;};

    public double negativi(double a[])
    {
        double somma=0;

        System.out.println("\nNumeri negativi trovati:");

        for(double num : a)
        {
            if(num<0)
            {
                somma+=num;
                System.out.print(num + " ");
            }
        }

        return somma;
    }

    public double massimo (double a[])
    {
        double max=Double.NEGATIVE_INFINITY;

        for(double num : a)
        {
            if(num>max)
                max=num;  
        }

        return max;
    }

    public double somma(double a[])
    {
        double somma=0;

        for(int i=0; i<n; i++)
        {
            somma+=a[i];
        }

        return somma;
    }

    public void random(double a[])
    {
        for(int i=0; i<n; i++)
        {
            a[i]=Math.random()*21-10;
        }
    }

    public void stampa(double a[])
    {
        System.out.println("\nArray:");
        for(double num : a)
        {
            System.out.print(num + " ");
        }
    }
}