/**
 * Implementazione di un server web utilizzando la comunicazione tramite socket.
 * Lettura dati multi riga provenienti dal client
 * 
 * from folder network/..
 * javac network/TcpServer.java; java network.TcpServer 
 */
package Server;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class TcpServer {
	public static void main(String[] args) throws Exception {
		
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
				
				String substring;
				int cond = -1;

				// ---------------------------------------------------------
				//Lettura dati dal client un righa alla volta   
				while ((clientMsg=inStream.readLine()).length() != 0) {
					System.out.println(clientMsg);	
					if(clientMsg.contains("GET") || clientMsg.contains("POST")){
						
						if(clientMsg.indexOf("HTTP/1.1")-2 - clientMsg.indexOf("/")+1 > 0){

							substring = clientMsg.substring(clientMsg.indexOf("/")+1, clientMsg.indexOf("HTTP/1.1")-1);

							if(substring.toLowerCase().compareTo("accendi") == 0){
								cond = 1;
							} else if (substring.toLowerCase().compareTo("spegni") == 0){
								cond = 0;
							}
						}
					}
				} 

				// Elaborare qui i dati ricevuti dal client 
				// ---------------------------------------------------------
				//Invio dei dati su stream di rete al client
				clientMsg = "HTTP/1.1 200 OK\r\n";
				//clientMsg += "Connection: close\r\n";
				//clientMsg += "Content-Type: text/plain\r\n";
				clientMsg += "\r\n";
				switch (cond) {
					case 1:
						clientMsg += "ACCESO";
						break;
					case 0:
						clientMsg += "SPENTO";
						break;
					default:
						clientMsg += "CONDIZIONE NON ESISTENTE O NON ASSEGNATA";
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