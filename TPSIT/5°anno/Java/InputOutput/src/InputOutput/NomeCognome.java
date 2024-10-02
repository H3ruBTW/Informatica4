package InputOutput;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NomeCognome {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nom;
        String cog;

        System.out.print("Inserire nome: ");
        nom = br.readLine();

        System.out.print("Inserire cognome: ");
        cog = br.readLine();

        System.out.println("\nIl nome completo inserito è: \"" + nom + " " + cog + "\"");
    }
}
