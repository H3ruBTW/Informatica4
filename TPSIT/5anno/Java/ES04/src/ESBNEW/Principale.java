package ESBNEW;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class Principale {
    private static int ordinazione = 1;
    private static int ordinazioneMAX = 1;
    private static final int PORT1 = 8888;
    private static final int PORT2 = 8889;
    private static int PORTComunicazione;
    private static final String IP1 = "127.0.0.1";
    private static final String IP2 = "224.0.0.1";
    public static void main(String[] args) throws IOException {
        Thread AccettaRichiesteThread = new Thread(new Runnable() {
            @Override
            public void run(){
                try {
                    DatagramSocket socket = new DatagramSocket(PORT1);

                    byte[] buf = new byte[1024];
                    DatagramPacket packet = new DatagramPacket(buf, 1024);
                    while (true) { 
                        socket.receive(packet);
                        
                        String msg = new String(packet.getData(), 0, packet.getLength());

                        if(msg.startsWith("Number Request on:")){
                            PORTComunicazione = Integer.parseInt(msg.substring(msg.indexOf(":")+1));
                            System.out.println("Received Request on: " + PORTComunicazione + "\nGli è stato dato il numero: " + ordinazioneMAX);
                        } else {
                            continue;
                        }

                        msg = ordinazione + "-" + ordinazioneMAX;

                        InetAddress destIpAddr = InetAddress.getByName(IP1);
                        DatagramPacket sendPacket = new DatagramPacket(msg.getBytes(), msg.length(), destIpAddr, PORTComunicazione);
		                socket.send(sendPacket);
                        ordinazioneMAX++;
                    }                  
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        });
        AccettaRichiesteThread.start();

        Thread InviaNumeroThread = new Thread(new Runnable() {
            @Override
            public void run(){
                try {
                    MulticastSocket socket = new MulticastSocket(PORT2);
                    InetAddress group = InetAddress.getByName(IP2);
                    socket.setInterface(InetAddress.getByName(IP1));
                    socket.joinGroup(group);
                    Scanner scanner = new Scanner(System.in);

                    while (true) { 
                        System.out.println("Premi Invio per chiamare il cliente N°" + (ordinazione+1));
                        scanner.nextLine();
                        ordinazione++;
                        String message = "E' stato chiamato il numero:" + (ordinazione+1);
                        DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), group, PORT2);
                        socket.send(packet);
                        
                    }
                    
                } catch (Exception e) {
                    System.err.println(e);
                }
            }
        });
        InviaNumeroThread.start();
    }
}
