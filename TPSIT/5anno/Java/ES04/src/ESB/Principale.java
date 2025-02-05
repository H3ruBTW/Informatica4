package ESB;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class Principale {
    private static int ordinazione = 1;
    private static int ordinazioneMAX = 1;
    private static final int PORT = 8698;
    private static final String LOCAL_IP = "127.0.0.1";
    private static final String MULTICAST_IP = "235.1.1.1";
    private static final int MULTICAST_PORT = 8888;

    public static void main(String[] args) throws IOException {

        try {
                
            Thread ManagementThread = new Thread(new Runnable(){
                @Override
                public void run(){
                    try {
                        //Opens a datagram socket on the specified port
                        DatagramSocket socket = new DatagramSocket(PORT);

                        while (true) { 
                            //Constructs a datagram packet for receiving the packets of specified length
                            byte[] buf = new byte[1024];
                            DatagramPacket packet = new DatagramPacket(buf, 1024);

                            //Receives a datagram packet from this socket
                            socket.receive(packet);
                            System.out.println("\nRicevuta richiesta da: " + packet.getAddress() + "\nGli è stato assegnato il numero: " + ordinazioneMAX);
                            
                            String message = ordinazioneMAX + " " + ordinazione;
                            DatagramPacket sendPacket = new DatagramPacket(message.getBytes(), message.length(), packet.getAddress(), PORT);
                            ordinazioneMAX++;

                            socket.send(sendPacket);
                        }
                        
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
            ManagementThread.start();

            
            Thread ChiamataThread = new Thread(new Runnable(){
                @Override
                public void run(){
                    try{
                        MulticastSocket socket = new MulticastSocket();
                        InetAddress group = InetAddress.getByName(MULTICAST_IP);
                        socket.setInterface(InetAddress.getByName(LOCAL_IP));
                        socket.joinGroup(group);

                        while (true) { 
                            System.out.print("Premi Invio per chiamare il cliente N°" + ordinazione);
                            Scanner scanner = new Scanner(System.in);
                            scanner.nextLine();
                            
                            String message = "E' stato chiamato il numero: " + ordinazione;
                            DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), group, MULTICAST_PORT);
                            socket.send(packet);
                            ordinazione++;
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });
            ChiamataThread.start();

        } catch (Exception e) {
            e.printStackTrace();
        }
        
        
    }
}
