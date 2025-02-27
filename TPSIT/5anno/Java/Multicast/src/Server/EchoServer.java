package Server;

import java.io.*;
import java.net.*;

public class EchoServer extends ClientServer  {

    private ServerSocket port;

    public EchoServer(int port, int backlog) throws IOException {
        this.port = new ServerSocket(port, backlog);
    }

    public void start() {
        System.out.println("SERVER AVVIATO!");

        while (true) {
            try {
                Socket socket = port.accept();
                System.out.println("Accettata la connessione da " + socket.getInetAddress() + " " + socket.getPort());

                new Thread(new ClientHandler(socket)).start();

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}