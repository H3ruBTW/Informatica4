package Server;

import java.io.*;
import java.net.*;

public class ClientHandler extends ClientServer {

    private Socket socket;
    private BufferedReader sv = new BufferedReader(new InputStreamReader(System.in));

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            writeToSocket(socket, "Ciao, come stai? \n");
            String str;

            do {

                str = readFromSocket(socket);

                if (str.toLowerCase().equals("goodbye")) {
                    writeToSocket(socket, "Goodbye");
                    System.out.println("CLIENT: " + str);}
                else {
                    System.out.println("CLIENT: " + str);
                    String servStr;
            servStr = sv.readLine(); // legge l'input da console	  
            writeToSocket(socket, "SERVER" + servStr + "\n");//LO INVIA AL CLIENT
                }
            } while (!str.toLowerCase().equals("goodbye"));

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}


