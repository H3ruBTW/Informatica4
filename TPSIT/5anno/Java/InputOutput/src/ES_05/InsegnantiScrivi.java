package ES_05;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class InsegnantiScrivi {
    public static void main(String[] args) throws Exception{
        Insegnante s1 = new Insegnante(1, "Bilardo", "Informatica - TPSIT");

        FileOutputStream fout = new FileOutputStream("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/ES_05/testo/studente.txt");
        ObjectOutputStream out = new ObjectOutputStream(fout);
        out.writeObject(s1);
        out.flush();
    }
}
