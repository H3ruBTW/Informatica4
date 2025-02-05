package ESAV1;

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class sender {

    private static final String SENDER_IP = "127.0.0.1";
    private static final String MULTICAST_IP = "230.0.0.1";
    private static final int MULTICAST_PORT = 19876;
    public static void main(String[] args) {
        String username;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserire il proprio username che verrà visualizzato:");
        username = scanner.nextLine();

        if(username.isBlank())
            username = "Utente";

        try 
        {
            //Creo il MulticastSocket per lo scambio dei dati con il client
            MulticastSocket socket = new MulticastSocket();
            InetAddress group = InetAddress.getByName(MULTICAST_IP);
            socket.setInterface(InetAddress.getByName(SENDER_IP));
            socket.joinGroup(group); 

            //Invio il DatagramPacket al gruppo di multicast
            String message = username + ": Messaggio da Sender";
            DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), group, MULTICAST_PORT);
            socket.send(packet);

            //Fine della comunicazione
            socket.leaveGroup(group);
            socket.close();

            System.out.println("Messaggio inviato al gruppo di multicast.");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
