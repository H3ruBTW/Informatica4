package Termometro;

import java.io.*;
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class modifyserver {

    private static final int PORT = 60000;

    public static void main(String[] args) throws InterruptedException {
        float temp;
        float hum;
        String percorsoFile = "Termometro\\Termometro.html";

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server TCP in ascolto sulla porta " + PORT);

            while (true) {
                try (Socket clientSocket = serverSocket.accept(); BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {

                    System.out.println("Connessione accettata da: " + clientSocket.getInetAddress().getHostAddress());

                    // Leggi i messaggi dal client in un ciclo
                    String msg;
                    while ((msg = in.readLine()) != null) {
                        // Verifica se il messaggio è valido
                        if (msg.isEmpty()) {
                            System.out.println("Messaggio vuoto ricevuto, salto.");
                            continue;
                        }

                        try {
                            // Converte il messaggio in un numero e aggiorna la temperatura
                            temp = Float.parseFloat(msg.substring(0, msg.indexOf(".")+1));
                            System.out.println("Temperatura ricevuta: " + temp);
                            hum = Float.parseFloat(msg.substring(msg.indexOf(".")+3));
                            System.out.println("Umidità ricevuta: " + hum);

                            // Legge il file HTML e aggiorna il valore della temperatura
                            try {
                                List<String> righe = Files.readAllLines(Paths.get(percorsoFile));
                                boolean updated = false;

                                // Aggiorna il valore della temperatura nella riga appropriata
                                for (int i = 0; i < righe.size(); i++) {
                                    String riga = righe.get(i);
                                    if (riga.contains("let temp =")) {
                                        righe.set(i, "    let temp = " + temp); // Aggiorna il valore della temperatura
                                        updated = true;
                                    }

                                    if (riga.contains("let humid =")) {
                                        righe.set(i, "    let humid = " + hum); // Aggiorna il valore della temperatura
                                        updated = true;
                                    }
                                }

                                // Se è stato aggiornato, riscrive il file HTML
                                if (updated) {
                                    Files.write(Paths.get(percorsoFile), righe);
                                    System.out.println("Scrittura avvenuta con successo");
                                    out.println("Temperatura aggiornata con successo.");
                                } else {
                                    System.out.println("Impossibile trovare la riga per aggiornare la temperatura.");
                                    out.println("Errore nell'aggiornamento della temperatura.");
                                }
                            } catch (IOException e) {
                                System.out.println("Errore durante la lettura/scrittura del file HTML: " + e.getMessage());
                                out.println("Errore durante l'aggiornamento del file HTML.");
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("Errore nel parsing della temperatura: " + msg);
                            out.println("Errore nel parsing della temperatura.");
                        }
                    }

                    System.out.println("Connessione chiusa dal client.");
                } catch (IOException e) {
                    System.out.println("Errore di connessione: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Errore nel server: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
