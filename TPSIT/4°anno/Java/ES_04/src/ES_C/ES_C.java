package ES_C;

import java.util.Scanner;

public class ES_C {

    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s = new String();

        System.out.print("Inserire una parola: ");
        s = scanner.nextLine();

        //rimpiazza tutti gli spazi con dei vuoti
        s=s.replaceAll(" ", "");

        //1 - NUMERO FISSO ITALIANO
        if(s.startsWith("+39"))
        {
            if(s.length()==12) //numeri fissi
            {
                if(s.charAt(3)=='0' && s.charAt(4)=='6') //+39 06
                {
                    System.out.println("Il numero è valido");
                }
                else
                {
                    System.out.println("Il numero non è valido");
                }
            }
            else if(s.length()==13) //numeri mobili
            {
                if(s.charAt(3)=='3') //+39 3
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

        //2 - EMAIL
        int n;

        if((n=s.indexOf('@'))!=-1) //controlla se presente la chiocciola
        {
            if(s.indexOf('.', n)!=-1) //controlla se c'è un punto dopo la @ ES.: @gmail.com
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

        //3 - URL

        //cerca se ha come prefisso l'HTTP
        if(s.startsWith("http://") || s.startsWith("https://"))
        {
            System.out.println("L'URL è valido");
        }
        else
        {
            System.out.println("L'URL non è valido");
        }

        //4 - INDIRIZZO IP
        n=0;
        int k=-1, j=0, d=0;

        for (int i = 0; i < s.length(); i++) //quanti punti ha la stringa
        {
            if(s.charAt(i)=='.')
                n++;
        }

        if(n==3) //ES.: 192.168.1.0 ha 3 punti
        {
            for (int i = 0; i < s.length() && d==0; i++) 
            {
                if(s.charAt(i)=='.') 
                {
                    if(s.charAt(j)=='.') //per evitare che non ci sia un numero tra i '.'
                    {
                        d=1;
                        continue;
                    }

                    k=i; //si sposta al nuovo indice dove viene trovato il .

                    //controllare se il numero tra i punti è compreso tra 0 e 255
                    if(Integer.parseInt(s.substring(j, k))<0 && Integer.parseInt(s.substring(j, k))>255) 
                    {
                        d=1;
                        continue;
                    }

                    j=k+1; //sposta il punto iniziale del numero tra punti a quello successivo
                           //perchè k si trova dove c'è il punto in quel momento
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
        
        //5 - CODICE FISCALE
        d=0;

        if(s.length()==16) //formato da 16 caratteri, 9 lettere e 7 numeri
        {
            s=s.toUpperCase();

            //controllo uno ad uno la formattazione del codice fiscale
            for (int i = 0; i < 6 && d==0; i++) 
            {
                if(s.charAt(i)<'A' && s.charAt(i)>'Z')
                {
                    d=1;
                }
            }

            for (int i = 6; i < 8 && d==0; i++) 
            {
                if(s.charAt(i)<'0' && s.charAt(i)>'9')
                {
                    d=1;
                }
            }

            if(s.charAt(8)<'A' && s.charAt(8)>'Z' && d==0)
            {
                d=1;
            }

            for (int i = 9; i < 11 && d==0; i++) 
            {
                if(s.charAt(i)<'0' && s.charAt(i)>'9')
                {
                    d=1;
                }
            }

            if(s.charAt(11)<'A' && s.charAt(11)>'Z' && d==0)
            {
                d=1;
            }

            for (int i = 12; i < 15 && d==0; i++) 
            {
                if(s.charAt(i)<'0' && s.charAt(i)>'9')
                {
                    d=1;
                }
            }

            if(s.charAt(15)<'A' && s.charAt(15)>'Z' && d==0)
            {
                d=1;
            }

            if(d==0)
            {
                System.out.println("Il codice fiscale è valido");
            }
            else
            {
                System.out.println("Il codice fiscale non è valido");
            }
        }
        else
        {
            System.out.println("Il codice fiscale non è valido");
        }

        //6 - IBAN
        if(s.length()==27 && s.startsWith("IT")) //l'IBAN in italia è formato da 27 caratteri e ha suffiso "IT"
        {
            System.out.println("Il codice IBAN è valido");
        }
        else
        {
            System.out.println("Il codice IBAN non è valido");
        }

        //7 - ISBN-13
        d=0;

        if(s.length()==13) //formato da 13 caratteri, solo numeri
        {
            for(int i=0; i<s.length(); i++)
            {
                if(s.charAt(i)<'0' && s.charAt(i)>'9')
                {
                    d=1;
                    break;
                }
            }

            if(d==0)
            {
                System.out.println("Il codice ISBN-13 è valido");
            }
            else
            {
                System.out.println("Il codice ISBN-13 non è valido");
            }
        }
        else
        {
            System.out.println("Il codice ISBN-13 non è valido");
        }
    }
}
