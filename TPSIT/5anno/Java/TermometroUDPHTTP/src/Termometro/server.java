package Termometro;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;

class server {
    public static void main(String[] args) {
        final int SERVER_PORT = 8765;

        try (ServerSocket serverSocket = new ServerSocket(SERVER_PORT, 50, InetAddress.getByName("0.0.0.0"))) {
            System.out.println("Server: in ascolto sulla porta " + SERVER_PORT);

            while (true) {
                System.out.println("Attesa ricezione dati dal client...");
                try (Socket clientSocket = serverSocket.accept();
                     DataOutputStream outStream = new DataOutputStream(clientSocket.getOutputStream());
                     BufferedReader inStream = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {

                    String InputString;
                    String contenuto = "";
                    String percorsoFile = "Termometro/Termometro.html";
                    String percorsoFile2 = "Termometro/favicon.ico";

                    boolean isFaviconRequest = false;

                    // Lettura della richiesta HTTP
                    while ((InputString = inStream.readLine()) != null && InputString.length() != 0) {
                        if (InputString.contains("GET /favicon.ico")) {
                            isFaviconRequest = true;
                        }
                        System.out.println("Richiesta ricevuta: " + InputString);
                    }

                    // Composizione della risposta HTTP
                    String clientMsg = "HTTP/1.1 200 OK\r\n";
                    
                    //comunicazione della favicon
                    if (isFaviconRequest) {
                        if (Files.exists(Paths.get(percorsoFile2))) {
                            byte[] icoContent = Files.readAllBytes(Paths.get(percorsoFile2));
                            clientMsg += "Content-Type: image/x-icon\r\n";
                            clientMsg += "Content-Length: " + icoContent.length + "\r\n";
                            clientMsg += "\r\n";
                            outStream.write(clientMsg.getBytes());
                            outStream.write(icoContent);
                        } else {
                            clientMsg += "Content-Type: text/plain\r\n";
                            clientMsg += "\r\nFile favicon.ico non trovato";
                            outStream.write(clientMsg.getBytes());
                        }
                    //comunicazione del file html
                    } else {
                        if (Files.exists(Paths.get(percorsoFile))) {
                            contenuto = new String(Files.readAllBytes(Paths.get(percorsoFile)));
                        } else {
                            contenuto = "<html><body><h1>File non trovato</h1></body></html>";
                        }
                        clientMsg += "Content-Type: text/html\r\n";
                        clientMsg += "Content-Length: " + contenuto.length() + "\r\n";
                        clientMsg += "\r\n" + contenuto;
                        outStream.write(clientMsg.getBytes());
                    }

                    outStream.flush();
                    System.out.println("Risposta inviata al client.");
                } catch (Exception e) {
                    System.err.println("Errore durante la gestione della connessione: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println("Errore nell'avvio del server: " + e.getMessage());
        }
    }
}