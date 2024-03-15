package ES_D;

import java.util.Scanner;

public class ES_D {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        
        String s = new String();
        String subString = "";
        String subLavString = "";
        int d=0, j;
        int k=0; //indice d'inizio della substring

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        //rimuove gli spazi iniziali
        do
        {
            if(s.charAt(0) == ' ')
            {
                s=s.replaceFirst(" ", "");
            }
                
        }while (s.charAt(0) == ' ');

        //rimuove gli spazi finali
        char[] car = s.toCharArray();

        for(j=car.length-1; d==0; j--)
        {
            if(car[j] != ' ')
            {
                d=1;
            }
        }

        s = "";

        for(int i=0; i<j+2; i++)
        {
            s = s + car[i];
        }

        //rimuove gli spazi doppi e superiori nel mezzo tra le parole
        for(int i=0; i<s.length(); i++)
        {
            if(i-1>0) //evita l'errore "java.lang.StringIndexOutOfBoundsException"
            {
                //deve rimuovere solo quando lo spazio è presente anche prima
                if(s.charAt(i) == ' ' && s.charAt(i-1) != ' ') 
                {
                    subString = subString + s.substring(k, i) + " ";
                }
                
                //alla fine scrive l'ultima parola
                if(i == s.length()-1)
                {
                    subString = subString + s.substring(k, i+1);
                }

                //questo pezzo di codice è spiegato meglio nel collaudo su Docs
                if(s.charAt(i-1) == ' ')
                {
                    k=i;
                }
            }
            
        }

        //1 - Kebab-Case

        //rimpiazza semplicemente gli spazi con "-"
        System.out.println("Kebab-Case: " + subString.replaceAll(" ", "-"));

        //2 - Snake_Case

        //rimpiazza semplicemente gli spazi con "_"
        System.out.println("Snake-Case: " + subString.replaceAll(" ", "_"));

        //3 - camelCase
        k=0;
        d=0;
        String subString2 = "";

        subString = subString.toLowerCase();

        for(int i=0; i<subString.length(); i++)
        {
            if(subString.charAt(i) == ' ')
            {
                if(d==0) //non inserisce la prima lettera maiuscola
                {
                    subString2 = subString.substring(k, i);
                    d=1;
                }
                else
                {
                    //la prima lettera maiuscola
                    subLavString = subString.substring(k, k+1);
                    subLavString = subLavString.toUpperCase();

                    //unione della parola con la prima lettera maiuscola
                    subString2 = subString2 + subLavString + subString.substring(k+1, i);
                }

                k=i+1; //mette subito l'indice+1 da dove è stato trovato lo spazio
            }
            else if(i == subString.length()-1) //alla fine aggiunge l'ultima parola
            {
                //la prima lettera maiuscola
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

                //unione della parola con la prima lettera maiuscola
                subString2 = subString2 + subLavString + subString.substring(k+1, i+1);
            }
        }

        System.out.println("camelCase: " + subString2);

        //4 - PascalCase
        k=0;

        subString2 = "";

        for(int i=0; i<subString.length(); i++)
        {
            if(subString.charAt(i) == ' ')
            {
                //la prima lettera maiuscola
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

                //unione della parola con la prima lettera maiuscola
                subString2 = subString2 + subLavString + subString.substring(k+1, i);

                k=i+1; //mette subito l'indice+1 da dove è stato trovato lo spazio
            }
            else if(i == subString.length()-1) //alla fine aggiunge l'ultima parola
            {
                //la prima lettera maiuscola
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

                //unione della parola con la prima lettera maiuscola
                subString2 = subString2 + subLavString + subString.substring(k+1, i+1);
            }
        }

        System.out.println("PascalCase: " + subString2);
    }
}
