package InputOutput;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class AulaStudentiScrivi {
    public static void main(String[] args) throws Exception{
        Studente s1 = new Studente(3, "Buongallino Alessandro");

        FileOutputStream fout = new FileOutputStream("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/studente.txt");
        ObjectOutputStream out = new ObjectOutputStream(fout);
        out.writeObject(s1);
        out.flush();
    }
}
