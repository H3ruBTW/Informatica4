package Server;

import java.io.IOException;

public class MainServer extends ClientServer {
    public static void main(String[] args) throws IOException{
        EchoServer server = new EchoServer(14500, 5);
        
        server.start();
    }
}
