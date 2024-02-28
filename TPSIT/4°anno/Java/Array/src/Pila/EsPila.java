package Pila;

public class EsPila {

    public static void main(String[] args) {
        try{
            

            
        }
    }

    private void menù(){

    }
}

class Pila {
    private int fine=0;
    private int N;

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
