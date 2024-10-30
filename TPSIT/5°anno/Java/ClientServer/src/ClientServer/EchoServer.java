package ClientServer;

import java.io.*;
import java.net.*;

public class EchoServer extends ClientServer {
	private ServerSocket port;
	private Socket socket;
	private BufferedReader sv = new BufferedReader(new InputStreamReader(System.in));
	
	public EchoServer(int portNum, int nBacklog) throws IOException {
		port = new ServerSocket(portNum, nBacklog);
	}

	public void run() {
		while (true) {
			try {
		socket = port.accept();
		System.out.println("Accettata la connessione da " + socket.getInetAddress());
           //ESTRAE L�INDIRIZZO DEL CLIENT

				provideAService(socket);

				socket.close(); 
				System.out.println("Connessione chiusa \n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	} // run()        //CONTINUA ALLA PAGINA SUCCESSIVA 
	protected void provideAService(Socket socket) throws IOException {
		writeToSocket(socket, "Ciao, come stai? \n");
		String str;

		do {

			str = readFromSocket(socket);

			if (str.toLowerCase().equals("goodbye")) {
				writeToSocket(socket, "Goodbye");
			    System.out.println("CLIENT: " + str);}
			else {
				System.out.println("CLIENT: " + str);
				String servStr;
		servStr = sv.readLine(); // legge l�input da console	  
         writeToSocket(socket, "SERVER" + servStr + "\n");//LO INVIA AL CLIENT
			}
		} while (!str.toLowerCase().equals("goodbye"));

	} // provideAService()
}
	


