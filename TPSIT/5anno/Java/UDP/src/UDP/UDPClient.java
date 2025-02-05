package UDP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;

public class UDPClient {
     public static void main(String[] args) throws IOException {

        DatagramSocket socket = null;//ISTANZIAMO LA SOCKET DI UDP CON LA CLASSE PREPOSTA IN JAVA

        BufferedReader cl = new BufferedReader(new InputStreamReader(System.in));

        try {

            socket = new DatagramSocket();//CLASSE CHE IN JAVA CREA LA SOCKET DI COMUNICAZIONE E IL SUO COSTRUTTORE

            String message = "Hello, UDP Server!";

            InetAddress serverAddress = InetAddress.getByName("127.0.0.1"); //ASSOCIA A serverAddress l'IP 127.0.0.1 CON LA CLASSE OPPORTUNA PER LA MANIPOLAZIONE DEGLI IP E                
                                                                                 //PORT IN UDP DATAGRAM DI JAVA

            byte[] sendData = message.getBytes();//TRASFORMA IL MESSAGGIO IN ARRAY DI byte poiché IL PACKET DATAGRAM IN UDP FUNZIONA CON I BYTE

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, 12346); //APPRONTA il MESSAGGIO PER IL Server, INSERIRE LA CLASSE CHE  
                                                                                                                         //COSTRUISCE IL PACCHETTO PER DatagramSocket

            socket.send(sendPacket);//INSERIRE IL METODO CHE MANDA IL MESSAGGIO AL SERVER CON IL METODO PROPRIO DI UDP PER L'INVIO MESSAGGI IN JAVA CON LA DatagramSocket

            System.out.println("Messagio inviato: " + message);


            while(true) {    

                    message = cl.readLine();  //legge l'input DA TASTIERA

                    byte[] sendData2 = message.getBytes();  //CONVERTE IL MESSAGIO LETTO IN UN ARRAY DI byte

                    DatagramPacket sendPacket2 = new DatagramPacket(sendData2, sendData2.length, serverAddress, 12346); // COSTRUISCE IL PACKET DA INVIARE AL Server

                    socket.send(sendPacket2);//INVIA IL PACKET ORA CREATO ALLA RIGA PRECEDENTE

                    System.out.println("Messagio inviato: " + message +" Da IP e Porta: " + socket.getLocalAddress() + " e " + socket.getLocalPort());

                    byte[] receiveData = new byte[1024];//CREA UNA STRUTTURA DATI FATTA CON UN ARRAY DI 1024 BYTE PER RICEVERE I DATI

                    DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);//COSTRUISCE IL PACCHETTO DATAGRAM DI RICEZIONE CON LA CLASSE PREPOSTA
                                                                                                                   //ALLA CREAZIONE DI PACCHETTI DATAGRAM DI UDP                                                                                                    
                    
                    socket.receive(sendPacket);///CHIAMA IL METODO DI RICEZIONE TIPICO DELL'UDP CON JAVA UTILIZZATO DALLA socket

                    String message2 = new String(receivePacket.getData(), 0, receivePacket.getLength());

                    System.out.println("Ricevuto il messaggio: " + message2);

            }

        } catch (Exception e) {

            e.printStackTrace();

        } finally {

            if (socket != null) {

                socket.close();

            }

        }

    }

}
