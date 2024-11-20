package ESB;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;



public class Cliente {
	private int ordinazione;
    private static final String DEST_IP = "127.0.0.1";
    private static final int DEST_PORT = 8698;
	private static final String LOCAL_IP = "127.0.0.1";
    private static final String MULTICAST_IP = "235.1.1.1";
    private static final int MULTICAST_PORT = 8888;
    public static void main(String[] args) throws IOException 
	{	
		//Create Datagram socket that binds to any available port in localhost
		DatagramSocket socket = new DatagramSocket();

		//Create Datagram packet and send
		String message = "Request Number";
		System.out.println("Sender: starting on port " + DEST_PORT);
		InetAddress destIpAddr = InetAddress.getByName(DEST_IP);
		DatagramPacket sendPacket = new DatagramPacket(message.getBytes(), message.length(), destIpAddr, DEST_PORT);
		socket.send(sendPacket);
		System.out.println("E' stata inviata una richiesta di numero");
		
		//Close the socket
		socket.close();
	}
}
