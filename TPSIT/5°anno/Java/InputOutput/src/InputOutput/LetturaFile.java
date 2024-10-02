package InputOutput;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class LetturaFile {
    public static void main(String[] args) throws IOException{
        //Percorso WSL (UBUNTU)
        File doc = new File("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/lettura.txt");
        //Percorso Windows
        //File doc = new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\Java\\InputOutput\\src\\InputOutput\\testo\\lettura.txt");
        Scanner sc = new Scanner(doc);

        System.out.println("Metodo scanner:");
        while (sc.hasNextLine()) 
            System.out.println(sc.nextLine());
        
        sc.close();

        System.out.println("\nMetodo InputStream:");
        InputStreamMethod Is = new InputStreamMethod();
        Is.InputStream_read();

        System.out.println("\nMetodo BufferReader:");
        BufferReader br = new BufferReader();
        br.BufferReader_read();
    }
}
