package UDP;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;

public class UDPServer {
    public static void main(String[] args) {

        BufferedReader cl = new BufferedReader(new InputStreamReader(System.in));/* COMPLETARE CON IL BUFFER DI LETTURA DA CONSOLE */

        DatagramSocket socket = null;  

        try {

            socket = new DatagramSocket(12346); //SCRIVERE LA CLASSE DI JAVA CHE CREA LA SOCKET IN UDP E LA Porta in ascolto DEL SERVER  

            byte[] receiveData = new byte[1024]/* CREIAMO UN ARRY DI 1024 BYTE */;


            while (true) {

                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);//CREIAMO UN PACKET UDP DI DIMENSIONE 1024                                    
                                                                                      //BYTE

                socket.receive(receivePacket);//APRE LA SOCKET IN RICEZONE SCRIVERE IL METODO DI RICEZIONE PER LA socket DELL'UDP DI JAVA

                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());//CONVERTE LO STREAM BYTE
                                                                                                        //RICEVUTO IN UN MESSAGGIO STRIGA
                                                                                                        //DI CARATTERI
                System.out.println("Ricevuto il messaggio: " + message);

                InetAddress address = receivePacket.getAddress();//ESTRAE L'INDIRIZZO IP DEL CLIENT DA CUI SI E' RICEVUTO IL MESSAGGIO

                String client = address.getHostName();//ESTRAE IL NOME DELL'HOST DA CUI SI E' RICEVUTO IL MESSAGGIO

                int porta = receivePacket.getPort();

                System.out.println("In chiamata Client: "+ client + "su porta: " + porta);

                String message2 = cl.readLine(); // legge l'input DA CONSOLE per COMPLETARE INSERIRE LA STESSA VARIABILE IN CIMA AL CODICE IL BufferReader

                byte[] sendData2 = message2.getBytes();//TRASFORMA IL MESSAGGIO2 INSERITO DA CONSOLE IN ARRAY DI BYTE
                DatagramPacket sendPacket2 = new DatagramPacket(sendData2, sendData2.length, address, porta);
                //sendPacket2 E' IL DATAGRAM DA INVIARE
                socket.send(sendPacket2);//MANDA IL MESSAGGIO AL CLIENT
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
