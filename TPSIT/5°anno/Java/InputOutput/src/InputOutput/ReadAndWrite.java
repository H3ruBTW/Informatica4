package InputOutput;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class ReadAndWrite{
    public static void main() throws IOex{
        BufferedReader legge = new BufferedReader(new FileReader("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/lettura.txt"));
        BufferedWriter scrive = new BufferedWriter(new FileWriter("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/lettura.txt"));

    }
}