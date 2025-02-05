package UDP;

import java.net.*;

public class test {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            // Porta UDP su cui il server ascolta
            int port = 8766;
            socket = new DatagramSocket(port);  // Apre il socket sulla porta 8766
            System.out.println("Server UDP in ascolto sulla porta " + port);

            byte[] buffer = new byte[1024];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

            while (true) {
                socket.receive(packet);  // Aspetta di ricevere un pacchetto
                String receivedData = new String(packet.getData(), 0, packet.getLength());
                System.out.println("Ricevuto pacchetto: " + receivedData);
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();  // Chiude il socket
            }
        }
    }
}