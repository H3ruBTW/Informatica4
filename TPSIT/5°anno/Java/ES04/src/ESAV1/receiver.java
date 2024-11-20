package ESAV1;

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class receiver {
    private static final String RECEIVER_IP = "127.0.0.1";
    private static final String MULTICAST_IP = "230.0.0.1";
    private static final int MULTICAST_PORT = 19876;

    public static void main(String[] args) {
        try 
        {
            //Creo il MulticastSocket per lo scambio dei dati con il client
            MulticastSocket socket = new MulticastSocket(MULTICAST_PORT);
            InetAddress group = InetAddress.getByName(MULTICAST_IP);
            socket.setInterface(InetAddress.getByName(RECEIVER_IP));
            socket.joinGroup(group);

            //Mi preparo alla ricezione dei dati
            byte[] buffer = new byte[1024];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            System.out.println("Receiver in ascolto. Ctrl+C per terminare.");
            
            //Ricevo il DatagramPacket dal client e lo stampo a schermo
            String message = "";
            while (message != "exit") {
                socket.receive(packet);
                message = new String(packet.getData(), 0, packet.getLength());
                System.out.println(message);
            }

            //Fine della comunicazione
            socket.leaveGroup(group);
            socket.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
