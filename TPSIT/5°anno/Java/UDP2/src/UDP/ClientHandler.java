package UDP;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ClientHandler extends Thread{
    DatagramSocket socket = null; // definisce una connessione socket datagram

    BufferedReader sv = new BufferedReader(new InputStreamReader(System.in));

    public ClientHandler(DatagramSocket socket) {

        this.socket = socket;

    }

    public void run() {

        /* COSA INSERIRE QUI? */

        try {
            
            while (true) { 

                byte[] receiveData = new byte[1024]/* CREIAMO UN ARRY DI 1024 BYTE */;

                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);//CREIAMO UN PACKET UDP DI DIMENSIONE 1024 BYTE

                socket.receive(receivePacket);//APRE LA SOCKET IN RICEZONE POPOLANDO IL ///PACKET DEFINITO ALLA RIGA PRECEDENTE */

                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());

                //CONVERTE LO STREAM BYTE RICEVUTO IN UN MESSAGGIO DI CARATTERI

                System.out.println("Ricevuto il messaggio: " + message);

                //Informazioni sul Client che ha effettuato la chiamata

                InetAddress address = receivePacket.getAddress()/*VEDERE COME FATTO SUL CLIENT, USARE GETADDRESS*/;//INDIRIZZO IP DEL CLIENT DA CUI SI E' RICEVUTO IL MESSAGGIO

                String client = address.getHostName();//NOME DELL'HOST DA CUI SI E' RICEVUTO IL MESSAGGIO

                int porta = receivePacket.getPort();

                //PORTA DELL'HOST DA CUI SI E' RICEVUTO IL MESSAGGIO

                System.out.println("In chiamata Client: "+ client + "su porta: " + porta);//INFORMAZIONI SUL CLIENT IN CHIAMATA

                String message2 = sv.readLine(); // legge l'input DA CONSOLE

                byte[] sendData2 = message2.getBytes();

                //TRASFORMA IL MESSAGGIO2 INSERITO DA CONSOLE IN ARRAY DI BYTE

                DatagramPacket sendPacket2 = new DatagramPacket(sendData2, sendData2.length, address, porta); //COSTRUISCE IL
                //MESSAGGIO PER IL CLIENT

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