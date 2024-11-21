package ESBNEW;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Cliente {
    private static int ordinazione;
    private static int ordinazioneNOW;
    private static final int PORT1 = 8888;
    private static final int PORT2 = 8889;
    private static int PORTComunicazione = 8890;
    private static final String IP1 = "127.0.0.1";
    private static final String IP2 = "235.1.1.1";
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
            System.out.println(msg);

            ReceiveSocket.close();
            

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
