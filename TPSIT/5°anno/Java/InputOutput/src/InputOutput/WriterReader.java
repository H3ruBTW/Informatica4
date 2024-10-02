package InputOutput;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class WriterReader{
    public static void main(String[] args) throws IOException {
        BufferedReader legge = new BufferedReader(new FileReader("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/read.txt"));
        BufferedWriter scrive = new BufferedWriter(new FileWriter("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/write.txt"));

        int next;

        do{
            next = legge.read();
            if (next != -1) {
                char c = (char) next;
                scrive.write(c);
            }
        }while(next != -1);

        legge.close();
        scrive.close();
    }
}