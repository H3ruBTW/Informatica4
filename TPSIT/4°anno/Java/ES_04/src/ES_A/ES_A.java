package ES_A;

import java.util.Scanner;

public class ES_A {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] Args)
    {
        String s = new String();

        System.out.print("Inserire una parola: ");

        s = scanner.nextLine();
        
        //1 - LUNGHEZZA
        System.out.println("\nLa lunghezza è: " + s.length());

        //2 - CARATTERE CENTRALE
        System.out.println("Il carattere centrale della parola è: " + s.charAt(s.length()/2));

        //3 - PRIMA LETTERA MAIUSCOLA
        String subString1 = s.substring(0, 1);

        String subString2 = s.substring(1);

        subString1 = subString1.toUpperCase();

        System.out.println("La parola con prima lettera maiuscola: " + subString1 + subString2);

        //4 - NUMERO DI A
        int n=0;

        char[] string = new char[s.length()];

        string = s.toCharArray();

        for (char c : string) {

            if(c == 'a' || c == 'A')
                n++;
        }

        System.out.println("Il numero di \"A\" trovate è: " + n);

        //5 - LE PRIME 4 LETTERE
        if(s.length()>=4)
        {
            subString1 = s.substring(0, 4);
            System.out.println("La substring dal 1° al 4° carattere è: " + subString1);
        }
        else
        {
            System.out.println("La stringa è troppo piccola per questa operazione");
        }

        //6 - LA STRINGA IN MAIUSCOLO
        System.out.println("La stringa maiuscola: " + s.toUpperCase());

        //7 - LA STRINGA IN MINUSCOLO
        System.out.println("La stringa minuscola: " + s.toLowerCase());

        //8 - STRINGHE PALINDROMA
        if(s.length() > 1)
        {
            String subString3 = "";

            if(s.length() % 2 == 0) //caso con numero di lettere pari
            {
                subString1 = s.substring(0, s.length()/2);
                subString2 = s.substring((int) Math.floor(s.length()/2), s.length());

                for (int i=subString2.length()-1; i>=0; i--) {
                    subString3 = subString3 + subString2.charAt(i);
                }

                if(subString1.compareToIgnoreCase(subString3) == 0)
                    System.out.println("La parola è palindroma");
                else
                    System.out.println("La parola non è palindroma");

            }
            else //caso con numero di lettere dispari
            {
                subString1 = s.substring(0, s.length()/2);
                subString2 = s.substring((int) Math.floor(s.length()/2)+1, s.length());

                for (int i=subString2.length()-1; i>=0; i--) {
                    subString3 = subString3 + subString2.charAt(i);
                }

                if(subString1.compareToIgnoreCase(subString3) == 0)
                    System.out.println("La parola è palindroma");
                else
                    System.out.println("La parola non è palindroma");
            }
        }
        else
        {
            System.out.println("La parola ha meno di una lettera.");
        }
    }
}