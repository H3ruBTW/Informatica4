package ES_B;

import java.util.Scanner;

public class ES_B {
    
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s1 = new String();
        String s2 = new String();

        System.out.print("Inserire una parola: ");
        s1 = scanner.nextLine();

        System.out.print("Inserire una parola: ");
        s2 = scanner.nextLine();
        
        //1 - STRINGHE UGUALI
        if(s1.compareToIgnoreCase(s2) == 0)
        {
            System.out.println("Le due stringhe sono uguali");
        }
        else
        {
            System.out.println("Le due stringhe sono diverse");
        }

        //2 - TRASFORMA LA STRINGA IN NUMERO INTERO
        try {
            System.out.println(Integer.parseInt(s1));
        } catch (Exception e) {
            System.out.println("Impossibile trasformare la stringa in numero");
        }

        //3 - TRASFORMA LA STRINGA IN NUMERO DECIMALE
        try {
            System.out.println(Double.parseDouble(s1));
        } catch (Exception e) {
            System.out.println("Impossibile trasformare la stringa in numero");
        }

        //4 - DIVIDE LE PAROLE DELLA STRINGA IN PIù RIGHE
        int k=0; //indice d'inizio della subString

        System.out.println("La stringa divisa in righe");

        for(int i=0; i<s1.length(); i++)
        {
            if(s1.charAt(i) == ' ')
            {
                System.out.println(s1.substring(k, i));

                k = i + 1;
            }
        }

        System.out.println(s1.substring(k, s1.length()));

        //5 - SCRIVE LE PRIME 5 LETTERE
        if(s1.length()>4)
        {
            System.out.println("Le prime 5 lettere: " + s1.substring(0, 5));
        }
        else
        {
            System.out.println("Impossibile stampare le prime 5 lettere, parola troppo corta");
        }

        //6 - SCRIVE LE ULTIME 5 LETTERE
        if(s1.length()>4)
        {
            System.out.println("Le ultime 5 lettere: " + s1.substring(s1.length()-5, s1.length()));
        }
        else
        {
            System.out.println("Impossibile stampare le ultime 5 lettere, parola troppo corta");
        }

        //7 - LA PAROLA PIù LUNGA
        k=0;    
        int d=0; //vediamo se il ciclo viene effetuato una volta
                 //cosi da vedere se la stringa è formata da una parola o da tante

        String subString = "";

        for(int i=0; i<s1.length(); i++)
        {
            if(s1.charAt(i) == ' ')
            {
                if(subString.isEmpty())
                {
                    subString = s1.substring(k, i);
                    k = i + 1;
                    d=1;
                }
                else
                {
                    if(s1.substring(k, i).length()>subString.length())
                    {
                        subString = s1.substring(k, i);
                        k = i + 1;
                    }
                }    
            }
        }

        if(d == 1)
        {
            System.out.println("La parola più lunga è: " + subString);
        }
        else
        {
            System.out.println("La stringa è formata da una sola parola: " + s1);
        }

        //8 - ACRONIMO?
        d=0;
        char[] car = s1.toCharArray();

        for (char c : car) {
            if(Character.isLowerCase(c)) //generalmente gli acronimi sono formati da solo lettere maiuscole
            {
                d=1;
                break;
            }
        }

        if(d==0)
        {
            System.out.println("La parola è un acronimo");
        }
        else
        {
            System.out.println("La parola non è un acronimo");
        }

        //9 - STRINGHE ANAGRAMMI
        int nc1=0, nc2=0;

        if(s1.length()==s2.length())
        {
            d=1;

            for(int i=0; i<s1.length(); i++)
            {
                if(s1.indexOf(s1.charAt(i))==i) //controlla se il carattere è la prima ricorrenza
                {
                    nc1=0;
                    nc2=0;

                    for (int j = i; j < s1.length(); j++) {
                        if (Character.toLowerCase(s1.charAt(j))==Character.toLowerCase(s1.charAt(i))) {
                            nc1++;
                        }
                    }

                    for (int j = 0; j < s2.length(); j++) {
                        if (Character.toLowerCase(s2.charAt(j))==Character.toLowerCase(s1.charAt(i))) {
                            nc2++;
                        }
                    }

                    if(nc1!=nc2) //controlla se il numero di una certa lettere è lo stesso
                    {
                        d=0;
                        break;
                    }     
                }
            }
        }

        if(d==0)
        {
            System.out.println("Le stringhe non sono anagrammi");
        }
        else
        {
            System.out.println("Le stringhe sono anagrammi");
        }
    }
}
