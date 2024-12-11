package Termometro;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;

class server{
    public static void main(String[] args) {
        final int SERVER_PORT=8765;
		String clientMsg = "";
		
		try {			 
			// Creazione del socket sul server e ascolto sulla porta
			ServerSocket serverSocket = new ServerSocket(SERVER_PORT);
			System.out.println("Server: in ascolto sulla porta " + SERVER_PORT);

			boolean endConn=false;
			while(!endConn) {
				// Attesa della connessione con il client
				System.out.println("Attesa ricezione dati dal client ....................... \n");
				Socket clientSocket = serverSocket.accept();
				
				// Create output stream to write data and input stream to read data from socket
				DataOutputStream outStream = new DataOutputStream(clientSocket.getOutputStream());	
				BufferedReader inStream = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

				String contenuto = "";
				String percorsoFile = "Termometro/Termometro.html";
				String percorsoFile2 = "Termometro/termo.png";

				//Invio dei dati su stream di rete al client
				clientMsg = "HTTP/1.1 200 OK\r\n";
				//clientMsg += "Connection: close\r\n";
				while ((clientMsg=inStream.readLine()).length() != 0) {
					if(clientMsg.contains("GET /favicon.ico")){
						clientMsg += "Content-Type: image/x-icon\r\n";
						clientMsg += "\r\n";
						contenuto = new String(Files.readAllBytes(Paths.get(percorsoFile2)));
					} else {
						clientMsg += "Content-Type: text/html\r\n";
						clientMsg += "\r\n";			

						try {
							// Legge tutto il contenuto del file in una stringa
							contenuto = new String(Files.readAllBytes(Paths.get(percorsoFile)));

							// Stampa il contenuto
							System.out.println("Contenuto del file:");
							System.out.println(contenuto);
						} catch (IOException e) {
							// Gestisce eventuali errori di lettura
							System.err.println("Errore durante la lettura del file: " + e.getMessage());
						}
					}
					clientMsg+=contenuto;
					break;
				}
				
				outStream.write(clientMsg.getBytes());
				outStream.flush();

				System.out.println("\n....................... Fine ricezione dati\n");
				// Close resources
				clientSocket.close();
				inStream.close();
				outStream.close();
			}

			// Close resources
			serverSocket.close();

		} catch (Exception e) {
			System.out.println(e);
		}
	
    }
}
