package ES_C;

import java.util.Scanner;

public class ES_C {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s = new String();

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        s.trim();

        //1
        if(s.startsWith("+39"))
        {
            if(s.length()==12)
            {
                if(s.charAt(3)=='0' && s.charAt(4)=='6')
                {
                    System.out.println("Il numero è valido");
                }
                else
                {
                    System.out.println("Il numero non è valido");
                }
            }
            else if(s.length()==13)
            {
                if(s.charAt(3)=='3')
                {
                    System.out.println("Il numero è valido");
                }
                else
                {
                    System.out.println("Il numero non è valido");
                }
            }
            else
            {
                System.out.println("Il numero non è valido");
            }
        }
        else
        {
            System.out.println("Il numero non è valido");
        }

        //2
        int n;

        if((n=s.indexOf('@'))!=-1)
        {
            if(s.indexOf('.', n)!=-1)
            {
                System.out.println("L'email è valida");
            }
            else
            {
                System.out.println("L'email non è valida");
            }
        }
        else
        {
            System.out.println("L'email non è valida");
        }

        //3
        if(s.startsWith("http://") || s.startsWith("https://"))
        {
            System.out.println("L'URL è valido");
        }

        //4
        
        //5
        
    }
}
