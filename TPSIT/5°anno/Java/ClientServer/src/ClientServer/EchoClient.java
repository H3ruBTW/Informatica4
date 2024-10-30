package ClientServer;

import java.net.*;
import java.io.*;
import java.io.BufferedReader;

public class EchoClient extends ClientServer {
	protected Socket socket;
	public BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public EchoClient(String url, int port) throws UnknownHostException, IOException {//COSTRUTTORE
		socket = new Socket(url, port);
		System.out.println("CLIENT: Sono connesso a " + url + ": " + port);
	} // EchoClient()

    public void run() {//METODO RUN PROPRIO DELLA CLASSE THREAD
		try {
			requestAService(socket);
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();		
		}
	} // run()

	protected void requestAService(Socket socket) throws IOException {
		String servStr = readFromSocket(socket); // SVOLGE UNA PRIMA LETTURA DI CONTROLLO DEL MESSAGGIO
		if (servStr.substring(0, 4).equals("Ciao")) {
			System.out.println("SERVER: " + servStr);
			String userStr = "";
			do {
				userStr = in.readLine(); // legge l�input
				writeToSocket(socket, userStr + "\n"); // lo scrive sul socket per inviare il messaggio al server
				servStr = readFromSocket(socket); // legge la risposta ricdevuta dal server
				System.out.println("SERVER: " + servStr);// e la visualizza
			} while (!userStr.toLowerCase().equals("goodbye")); //se riceve un �goodbye� chiude la comunicazione
		}   //IF
	}  //requestAService()
}