package ESBNEW;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Principale {
    private static int ordinazione = 1;
    private static int ordinazioneMAX = 1;
    private static final int PORT1 = 8888;
    private static final int PORT2 = 8889;
    private static int PORTComunicazione;
    private static final String IP1 = "127.0.0.1";
    private static final String IP2 = "235.1.1.1";
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
                            System.out.println("Received Request on: " + PORTComunicazione + " Gli è stato dato il numero: " + ordinazioneMAX);
                        } else {
                            continue;
                        }

                        msg = ordinazione + "-" + ordinazioneMAX;

                        InetAddress destIpAddr = InetAddress.getByName(IP1);
                        DatagramPacket sendPacket = new DatagramPacket(msg.getBytes(), msg.length(), destIpAddr, PORTComunicazione);
		                socket.send(sendPacket);
                        ordinazioneMAX++;
                    }                  
                } catch (Exception e) {}
            }
        });
        AccettaRichiesteThread.start();

        Thread InviaNumeroThread = new Thread(new Runnable() {
            @Override
            public void run(){

            }
        });
    }
}
