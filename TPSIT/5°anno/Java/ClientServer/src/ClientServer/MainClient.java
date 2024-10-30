package ClientServer;

import java.io.IOException;
import java.net.UnknownHostException;

public class MainClient extends ClientServer  {
    public static void main(String[] args) throws UnknownHostException, IOException{
        EchoClient client = new EchoClient("localhost", 14500);
        client.run();
    }
}
