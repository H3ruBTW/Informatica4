package Termometro;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Random;

public class modifyserver {
    public static void main(String[] args) throws InterruptedException {
        int temp = 20;
        String percorsoFile = "Termometro/Termometro.html";
        Random random = new Random();

        do { 
            try {
                List<String> righe = Files.readAllLines(Paths.get(percorsoFile));
                for (int i = 0; i < righe.size(); i++) {
                    String riga = righe.get(i);

                    if(riga.contains("let temp =")){
                        int n = random.nextInt(2);
                        int n2 = random.nextInt(5);

                        if(n==0){
                            temp = temp + n2;
                        } else {
                            temp = temp - n2;
                        }

                        righe.set(i, "let temp = " + temp);

                        break;
                    }
                }

                Files.write(Paths.get(percorsoFile), righe);

                System.out.println("Scrittura avvenuta con successo");
            } catch (Exception e) {
                System.out.println("Errore...");
            }
            Thread.sleep(5000);
        } while (true);
        
    }
}
