package Pila;
import java.util.Scanner;

public class EsPila {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        try{
            if(args.length!=1)
            {
                System.err.println("Non hai inserito il numero giusto di parametri da linea di comando");
                System.err.println("Sintassi: Numero Intero(grandezza del array)");
                System.exit(-1); 
            }

            int N = Integer.parseInt(args[0]);
            Pila pila = new Pila(N);
            int array[] = new int[N];

            int d, n;

            while ((d=menù())!=0) {
                
                switch (d) {
                    case 1:
                        System.out.print("Scrivere un numero da inserire nell'array: ");
                        n=scanner.nextInt();
                        pila.push(array, n);
                        break;
                    case 2:
                        pila.pop(array);
                        break;
                    case 3:
                        n=pila.top(array);
                        System.out.println("L'elemento visualizzato è " + n);
                        break;
                    default:
                        System.out.println("Hai inserito un numero non esistente nella lista");
                        break;
                }
            }

            System.out.println("Stai per chiudere il programma");
        
            scanner.close();
        }   
        catch (Exception e)
        {
            System.err.println("\nHai inserito un carattere non disponibile");
            System.err.println("Sintassi: Numero Intero(grandezza del array)");
            System.err.println("");
            System.err.println(e);

            scanner.close();

            System.exit(-1);
        }
    }

    private static int menù(){

        int d;
        System.out.println("Inserire 1 per inserire l'elemento nella Pila");
        System.out.println("Inserire 2 per eliminare l'ultimo elemento nella Pila");
        System.out.println("Inserire 3 per vedere l'ultimo elemento nella Pila");
        System.out.println("Inserire 0 per uscire");
        System.out.print("Inserimento: ");

        Scanner scanner2 = new Scanner(System.in);

        d = scanner2.nextInt();

        scanner2.close();
        
        return d;
    }
}

class Pila {
    private int fine=0;
    private final int N;

    public Pila (int N)
    {
        this.N=N;
    }

    public void push (int pila[],int num)
    {
        if(!ifFull())
        {
            pila[fine] = num;
            fine++;
            System.out.println("L'elemento è stato correttamente inserito");
        }
        else
        {
            System.out.println("ERR 01 - L'ARRAY E' PIENO - IMPOSSIBILE INSERIRE L'ELEMENTO");
        }
    }

    public void pop (int pila[])
    {
        if(!ifEmpty())
        {
            fine--;
            pila[fine] = 0;        
            System.out.println("L'elemento e' stato correttamente eliminato");
        }
        else
        {
            System.out.println("ERR 02 - L'ARRAY E' VUOTO - IMPOSSIBILE ELIMINARE L'ELEMENTO");
        }
    }

    public int top (int pila[])
    {
        if(!ifEmpty())
        {
            System.out.println("L'elemento e' stato correttamente preso");
            return pila[fine-1];         
        }
        else
        {
            System.out.println("ERR 03 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO");
            return -1;
        }
    }

    public Boolean ifEmpty()
    {
        if(fine==0)
            return true;
        else
            return false;
    }

    public Boolean ifFull()
    {
        if(fine==N)
            return true;
        else
            return false;
    }
}
