package ES_C;

import java.util.Scanner;

public class ES_C {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s = new String();

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        s=s.replaceAll(" ", "");

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
        else
        {
            System.out.println("L'URL non è valido");
        }

        //4
        n=0;
        int k=-1, j=0, d=0;

        for (int i = 0; i < s.length(); i++) 
        {
            if(s.charAt(i)=='.')
                n++;
        }

        if(n==3)
        {
            for (int i = 0; i < s.length() && d==0; i++) 
            {
                if(s.charAt(i)=='.')
                {
                    if(s.charAt(k+1)=='.')
                    {
                        d=1;
                        continue;
                    }

                    k=i;

                    if(Integer.parseInt(s.substring(j, k))<0 && Integer.parseInt(s.substring(j, k))>255)
                    {
                        d=1;
                        continue;
                    }

                    j=k+1;
                }
            }

            if(d==0)
            {
                System.out.println("L'indirizzo IP è valido");
            }
            else
            {
                System.out.println("L'indirizzo IP non è valido");
            }
        }
        else
        {
            System.out.println("L'indirizzo IP non è valido");
        }
        
        //5

    }
}
