package ESB;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;



public class Cliente {
	private static int ordinazione;
	private static int ordinazioneNOW;
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

		//Constructs a datagram packet for receiving the packets of specified length
		byte[] buf = new byte[1024];
		DatagramPacket packet = new DatagramPacket(buf, 1024);
		//Receives a datagram packet from this socket
		socket.receive(packet);

		String msg = new String(packet.getData(), 0, packet.getLength());
		ordinazione = Integer.parseInt(msg.substring(0, msg.indexOf(" ")));
		ordinazioneNOW = Integer.parseInt(msg.substring(msg.indexOf(" ")+1));
		System.out.println("Ti è stato assegnato il numero: " + ordinazione);
		System.out.println("Adesso sta venendo chiamato il numero: " + ordinazioneNOW);
		//Close the socket
		socket.close();

		MulticastSocket socket2 = new MulticastSocket(MULTICAST_PORT);
		InetAddress group = InetAddress.getByName(MULTICAST_IP);
		socket2.setInterface(InetAddress.getByName(LOCAL_IP));
		socket2.joinGroup(group);

		byte[] buffer = new byte[1024];
        DatagramPacket packet2 = new DatagramPacket(buffer, buffer.length);

		//se il numero d'ordinazione tuo è minore del numero d'ordinazione chiamato
		while(ordinazione < ordinazioneNOW){
			socket.receive(packet);
			message = new String(packet.getData(), 0, packet.getLength());
			ordinazioneNOW = Integer.parseInt(msg.substring(msg.indexOf(":")+2));
			System.out.println(message);
		}

		socket2.leaveGroup(destIpAddr);
		socket2.close();
	}
}
