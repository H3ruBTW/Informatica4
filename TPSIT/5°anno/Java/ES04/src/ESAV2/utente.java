package ESAV2;

import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class utente {
    private static final String LOCAL_IP = "127.0.0.1";
    private static final String MULTICAST_IP = "235.1.1.1";
    private static final int MULTICAST_PORT = 8888;
    private static String username;
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserire il proprio username che verrà visualizzato: ");
        username = scanner.nextLine();

        if(username.isBlank())
            username = "Utente";
        else
            username = username.replaceAll(" ", "");

        try {
            // Creazione del gruppo multicast
            InetAddress group = InetAddress.getByName(MULTICAST_IP);
            // Creazione della socket per la comunicazione multicast
            MulticastSocket socket = new MulticastSocket(MULTICAST_PORT);
            // Associazione della socket all'interfaccia di rete
            socket.setInterface(InetAddress.getByName(LOCAL_IP));
            // Associazione della socket al gruppo multicast
            socket.joinGroup(group);


            // Thread per la ricezione dei messaggi multicast
            Thread receiverThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        while (true) {
                            // Creazione del pacchetto per la ricezione dei dati
                            byte[] buffer = new byte[1024];
                            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                            // Ricezione del pacchetto
                            String message = "";
                            socket.receive(packet);
                            message = new String(packet.getData(), 0, packet.getLength());
                            //Stampo a schermo info e dati ricevuti
                            System.out.println(message);
                            // Se il messaggio è "exit" termina il programma
                            if(message.substring(message.indexOf(":")+1).equalsIgnoreCase("exit"))
                                break;
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
            receiverThread.start();

            // Thread per l'invio dei messaggi
            Thread senderThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        Scanner scanner = new Scanner(System.in);
                        while (true) {
                            String msg = scanner.nextLine();
                            // Creazione del pacchetto per l'invio dei dati
                            String message = username + ": " + msg;
                            DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), group, MULTICAST_PORT);
                            // Invio del pacchetto
                            socket.send(packet);
                            // Se il messaggio è "exit" termina il programma
                            if(msg.replaceAll(" ", "").equalsIgnoreCase("exit")){
                                scanner.close();
                                break;
                            }     
                        }
                        
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
            senderThread.start();

            // Attendi la terminazione dei thread
            receiverThread.join();
            senderThread.join();

            // Fine della comunicazione
            // Disassociazione della socket dal gruppo multicast
            // Chiusura della socket
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
