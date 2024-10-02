package InputOutput;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class BufferReader {
    void BufferReader_read() throws IOException{
        File doc = new File("/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/Java/InputOutput/src/InputOutput/testo/lettura.txt");
        
        BufferedReader br = new BufferedReader(new FileReader(doc));

        String st;

        while (st = br.readLine() != null) {
            System.out.println(st);
        }

        br.close();
    }
}
