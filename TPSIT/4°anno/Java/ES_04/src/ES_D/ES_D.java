package ES_D;

import java.util.Scanner;

public class ES_D {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        
        String s = new String();
        String subString = "";
        String subLavString = "";
        int d=0, k=0, j;

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        do
        {
            if(s.charAt(0) == ' ')
            {
                s=s.replaceFirst(" ", "");
            }
                
        }while (s.charAt(0) == ' ');

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

        for(int i=0; i<s.length(); i++)
        {
            if(i-1>0)
            {
                if(s.charAt(i) == ' ' && s.charAt(i-1) != ' ')
                {
                    subString = subString + s.substring(k, i) + " ";
                }
                
                if(i == s.length()-1)
                {
                    subString = subString + s.substring(k, i+1);
                }

                if(s.charAt(i-1) == ' ')
                {
                    k=i;
                }
            }
            
        }

        //1 - Kebab-Case
        System.out.println("Kebab-Case: " + subString.replaceAll(" ", "-"));

        //2 - Snake_Case
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
                if(d==0)
                {
                    subString2 = subString.substring(k, i);
                    d=1;
                }
                else
                {
                    subLavString = subString.substring(k, k+1);
                    subLavString = subLavString.toUpperCase();

                    subString2 = subString2 + subLavString + subString.substring(k+1, i);
                }

                k=i+1;
            }
            else if(i == subString.length()-1)
            {
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

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
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

                subString2 = subString2 + subLavString + subString.substring(k+1, i);

                k=i+1;
            }
            else if(i == subString.length()-1)
            {
                subLavString = subString.substring(k, k+1);
                subLavString = subLavString.toUpperCase();

                subString2 = subString2 + subLavString + subString.substring(k+1, i+1);
            }
        }

        System.out.println("PascalCase: " + subString2);
    }
}
