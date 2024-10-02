package InputOutput;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Scanner;

public class InputStreamMethod {
    void InputStream_read() throws FileNotFoundException{
        InputStream ins = new FileInputStream("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/lettura.txt");
        Scanner sc = new Scanner(ins);

        while (sc.hasNextLine()) {
            System.out.println(sc.nextLine());
        }

        sc.close();
    }
}
