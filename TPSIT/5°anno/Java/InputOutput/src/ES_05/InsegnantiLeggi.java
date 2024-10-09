package ES_05;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class InsegnantiLeggi {
    public static void main(String[] args) throws Exception{
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/ES_05/testo/studente.txt"));
        Insegnante s = (Insegnante) in.readObject();
        System.out.println(s.id + " " + s.name + " " + s.materia);
        in.close();
    }
    
}
