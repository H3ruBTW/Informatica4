package InputOutput;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class AulaStudentiLeggi {
    public static void main(String[] args) throws Exception{
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/studente.txt"));
        Studente s = (Studente) in.readObject();
        System.out.println(s.id + " " + s.name);
        in.close();
    }
    
}
