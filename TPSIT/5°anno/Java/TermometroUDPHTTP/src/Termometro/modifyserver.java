package Termometro;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class modifyserver {
    private static final int PORT = 8766;
    public static void main(String[] args) throws InterruptedException {
        float temp = 20;
        String percorsoFile = "Termometro/Termometro.html";

        try {
            //Opens a datagram socket on the specified port
            DatagramSocket socket = new DatagramSocket(PORT);

            while (true) { 
                //Constructs a datagram packet for receiving the packets of specified length
                byte[] buf = new byte[1024];
                DatagramPacket packet = new DatagramPacket(buf, 1024);

                //Receives a datagram packet from this socket
                socket.receive(packet);  
                System.out.println("Ricevuto pacchetto da: " + packet.getAddress().getHostAddress());          

                String msg = new String(packet.getData(), 0, packet.getLength());
                temp = Float.parseFloat(msg);

                //prende le righe del file html è le piazza in una lista che poi controlla per poi riscrivere il file
                try {
                    List<String> righe = Files.readAllLines(Paths.get(percorsoFile));
                    for (int i = 0; i < righe.size(); i++) {
                        String riga = righe.get(i);
    
                        if(riga.contains("let temp =")){                               
                            righe.set(i, "    let temp = " + temp);
                            break;
                        }
                    }
    
                    Files.write(Paths.get(percorsoFile), righe);
    
                    System.out.println("Scrittura avvenuta con successo");
                } catch (IOException e) {
                    System.out.println("Errore...");
                }
            }
            
        } catch (IOException | NumberFormatException e) {
            e.printStackTrace();
        }        
    }
}
