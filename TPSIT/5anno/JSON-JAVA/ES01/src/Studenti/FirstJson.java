package Studenti;

import java.io.FileWriter;
import java.io.IOException;
import java.rmi.AccessException;

import javax.tools.JavaFileObject;

public class FirstJson {
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        String nomeFile = "Studenti/huitebe_.json";
        JSONObject mioOggetto = new JSONObject();
        mioOggetto.put("cognome", "Verdi");
        mioOggetto.put("nome", "Pino");
        mioOggetto.put("eta", 40);

        JSONArray elenco = new JSONArray();
        elenco.add("lingua 1: cinese");
        elenco.add("lingua 2: russo");
        elenco.add("lingua 3: turco");

        mioOggetto.put("lingue", elenco);

        System.out.print(mioOggetto);

        scriviFileJSON(nomeFile, mioOggetto);
        }
        public static void scriviFileJSON(String nomeFile, JavaFileObject mioOggetto) throws IOException {
        try (FileWriter mioFile = new FileWriter(nomeFile)) {
            mioFile.write(mioOggetto.toJSONString());
        } catch (AccessException e) {
            e.printStackTrace();
        }
    }
}
