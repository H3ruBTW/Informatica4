package Coda;
import java.util.Scanner;

public class MainCoda {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        try{
            if(args.length!=1)
            {
                System.err.println("Non hai inserito il numero giusto di parametri da linea di comando");
                System.err.println("Sintassi: Numero Intero(grandezza del array)");
                scanner.close();
                System.exit(-1); 
            }

            int N = Integer.parseInt(args[0]);
            Coda coda = new Coda(N);
            int array[] = new int[N];

            int d, num;

            while ((d=menù())!=0) {
                
                switch (d) {
                    case 1:
                        System.out.print("Scrivere un numero da inserire nell'array: ");
                        num=scanner.nextInt();
                        System.out.println(" ");
                        coda.push(array, num);
                        break;
                    case 2:
                        System.out.println(" ");
                        coda.pop();
                        break;
                    case 3:
                        System.out.println(" ");
                        num=coda.top(array);
                        System.out.println("L'elemento visualizzato è " + num);
                        break;
                    default:
                        System.out.println(" ");
                        System.out.println("Hai inserito un numero non esistente nella lista");
                        break;
                }
            }

            System.out.print("");
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

    private static int menù()
    {
        int d;
        System.out.println("");
        System.out.println("Inserire 1 per inserire l'elemento nella Coda");
        System.out.println("Inserire 2 per eliminare il primo elemento nella Coda");
        System.out.println("Inserire 3 per vedere lil primo elemento nella Coda");
        System.out.println("Inserire 0 per uscire");
        System.out.print("Inserimento: ");

        d = scanner.nextInt();
        
        return d;
    }
}

class Coda {
    private final int N;
    private int inizio = -1, fine = -1; 

    public Coda(int N)
    {
        this.N = N;
    }

    public void push(int coda[], int num)
    {
        if(ifEmpty())
        {
            inizio = 0;
            fine = 0;
        }
        else
        {
            fine = (fine + 1) % N;

            if(fine == inizio)
            {
                inizio = (inizio+1) % N;
            }
        }

        coda[fine] = num;
        System.out.println("L'elemento è stato correttamente inserito");
    }
    
    public void pop()
    {
        if(!ifEmpty())
        {
            if(inizio == fine)
            {
                inizio = -1;
                fine = -1;
            }
            else
            {
                inizio = (inizio + 1) % N;
            }

           System.out.println("L'elemento e' stato poppato");
        }
        else
        {
            System.out.println("ERR 01 - L'ARRAY E' VUOTO - IMPOSSIBILE ELIMINARE L'ELEMENTO");
        }
    }

    public int top(int coda[])
    {
        if(!ifEmpty())
        {
            return coda[inizio];
        }
        else
        {
            System.out.println("ERR 02 - L'ARRAY E' VUOTO - IMPOSSIBILE PRENDERE L'ELEMENTO");
            return -1;
        }
    } 

    private boolean ifEmpty()
    {
        if(inizio == -1 && fine == -1)
            return true;
        else
            return false;
    }

}
