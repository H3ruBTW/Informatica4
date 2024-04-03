package ES_C_Matches;

import java.util.Scanner;

public class ES_C {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s = new String();

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        //rimpiazza tutti gli spazi con dei vuoti
        s=s.replaceAll(" ", "");

        //1 - NUMERO DI TELEFONO ITALIANO
        if(s.matches("[+]39[3|0][\\d]{8,9}"))
            System.out.println("Il numero di telefono italiano è valido");
        else
            System.out.println("Il numero di telefono italiano non è valido");

        //2 - EMAIL
        if(s.matches("[\\w._-]+@[\\w]+.[\\p{Alpha}]{2,4}"))
            System.out.println("L'email è valida");
        else
            System.out.println("L'email non è valida");

        //3 - URL
        if(s.matches("http[s?]://([\\p{Alpha}]+.?)[\\w]+.[\\p{Alpha}]+[/]"))
            System.out.println("L'URL è valido");
        else
            System.out.println("L'URL non è valido");

        //4 - Indirizzo IP
        if(s.matches("([\\d]{1,3}+[.]){3}[\\d]"))
            System.out.println("L'IP è valido");
        else
            System.out.println("L'IP non è valido");

        //5 - Codice Fiscale
        String subString = s.toUpperCase();

        if(subString.matches("[\\p{Upper}]{6}[\\d]{2}[\\p{Upper}][\\d]{2}[\\p{Upper}][\\d]{3}[\\p{Upper}]"))
            System.out.println("Il codice fiscale è valido");
        else
            System.out.println("Il codice fiscale non è valido");

        //6 - IBAN
        if(subString.matches("IT[\\w]{25}"))
            System.out.println("L'IBAN è valido");
        else
            System.out.println("L'IBAN non è valido");
        
        //7 - ISBN-13
        if(s.matches("[\\d]{13}"))
            System.out.println("L'ISBN-13 è valido");
        else
            System.out.println("L'ISBN-13 non è valido");
    }
    
}
