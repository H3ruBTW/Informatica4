package ESBNEW;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class Cliente {
    private static int ordinazione;
    private static int ordinazioneNOW;
    private static final int PORT1 = 8888;
    private static final int PORT2 = 8889;
    private static int PORTComunicazione = 8890;
    private static final String IP1 = "127.0.0.1";
    private static final String IP2 = "224.0.0.1";
    public static void main(String[] args) throws IOException {
        try {
            DatagramSocket SendSocket = new DatagramSocket();
            DatagramSocket ReceiveSocket;

            while (true) { 
                try {
                    ReceiveSocket = new DatagramSocket(PORTComunicazione);
                    System.out.println("Comunicazione da ricevere su: " + PORTComunicazione);
                    break;
                } catch (Exception e) {
                    PORTComunicazione++;
                }
            }

            //Create Datagram packet and send
            String message = "Number Request on:" + PORTComunicazione;
            System.out.println("Sender: starting on port " + PORT1);
            InetAddress destIpAddr = InetAddress.getByName(IP1);
            DatagramPacket sendPacket = new DatagramPacket(message.getBytes(), message.length(), destIpAddr, PORT1);
            SendSocket.send(sendPacket);
            
            SendSocket.close();

            byte[] buf = new byte[1024];
		    DatagramPacket packet = new DatagramPacket(buf, 1024);

            ReceiveSocket.receive(packet);

            String msg = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Ti è stato assegnato il numero: " + msg.substring(msg.indexOf("-")+1));
            System.out.println("In questo momento e' chiamato il numero: " + msg.substring(0, msg.indexOf("-")));
            ordinazione = Integer.parseInt(msg.substring(msg.indexOf("-")+1));
            ordinazioneNOW = Integer.parseInt(msg.substring(0, msg.indexOf("-")));

            ReceiveSocket.close();

            MulticastSocket socket = new MulticastSocket(PORT2);
            InetAddress group = InetAddress.getByName(IP2);
            socket.setInterface(InetAddress.getByName(IP1));
            socket.joinGroup(group);

            while(ordinazione > ordinazioneNOW){
                socket.receive(packet);
                message = new String(packet.getData(), 0, packet.getLength());
                ordinazioneNOW = Integer.parseInt(msg.substring(msg.indexOf("-")+1));
                System.out.println(message);
            } 

            System.out.println("E' stato chiamato il tuo numero!");            

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
