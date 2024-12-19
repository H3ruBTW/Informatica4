package Termometro;

import java.io.*;
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class modifyserver {
    private static final int PORT = 8766;

    public static void main(String[] args) throws InterruptedException {
        float temp = 20;
        String percorsoFile = "Termometro/Termometro.html";

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server TCP in ascolto sulla porta " + PORT);

            while (true) {
                try (Socket clientSocket = serverSocket.accept();
                     BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {

                    System.out.println("Connessione accettata da: " + clientSocket.getInetAddress().getHostAddress());

                    String msg = in.readLine();
                    temp = Float.parseFloat(msg);

                    // Prende le righe del file html e le piazza in una lista che poi controlla per poi riscrivere il file
                    try {
                        List<String> righe = Files.readAllLines(Paths.get(percorsoFile));
                        for (int i = 0; i < righe.size(); i++) {
                            String riga = righe.get(i);

                            if (riga.contains("let temp =")) {
                                righe.set(i, "    let temp = " + temp);
                                break;
                            }
                        }

                        Files.write(Paths.get(percorsoFile), righe);

                        System.out.println("Scrittura avvenuta con successo");
                    } catch (IOException e) {
                        System.out.println("Errore...");
                    }
                } catch (IOException | NumberFormatException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}