package UDP;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramSocket;

public class UDPServer {
     public static void main(String[] args) {

        DatagramSocket socket = null;

        BufferedReader cl = new BufferedReader(new InputStreamReader(System.in));

        try {

            socket = new DatagramSocket(12346); // Porta in ascolto DAL SERVER

            //PER IL MULTITHREAD UDP RIMUOVERE UNA PARTE DEL CODICE SOTTOSTANTE E PORLO NELLA POSIZIONE CORRETTA DI //CLIENTHENDLERUDP PER IMPLEMENTARE IL MULTITHREADING

            //AL POSTO DEL CODICE TOLTO QUI PORRE, UN CODICE CHE IMPLEMENTI UN OGGETTO DI UN'ALTRA CLASSE (QUALE?) //UTILIZZANDOLA COME //UN THREAD CHE CONSENTA IL MULTITHREADING APPUNTO PER LA COMUNICAZIONE //CON PIU' CLIENT   
                           
            new Thread(new ClientHandler(socket)).start();

        } catch (Exception e){
            e.printStackTrace();
        }
    }

}
