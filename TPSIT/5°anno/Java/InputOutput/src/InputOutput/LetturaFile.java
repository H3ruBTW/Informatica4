package InputOutput;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class LetturaFile {
    public static void main(String[] args) throws IOException{
        File doc = new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\Java\\InputOutput\\src\\InputOutput\\testo\\lettura.txt");
        Scanner sc = new Scanner(doc);

        while (sc.hasNextLine()) {
            System.out.println(sc.nextLine());
        }

        sc.close();
    }
}
