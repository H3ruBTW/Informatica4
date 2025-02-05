package Studenti;
import java.io.FileReader;
import java.util.Iterator;

public class SecondJsonWin {
    public static void main(String[] args) throws Exception {
        String nomeFile = "C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\JSON-JAVA\\ES01\\src\\Studenti\\huitebe_.json";
        JSONObject oggettoJSon = (JSONObject) leggiFileJSON(nomeFile);
        System.out.println("Contenuto intero oggetto:");
        System.out.println(oggettoJSon);
        System.out.println("Singoli elementi:");
        String cognome = (String) oggettoJSon.get("cognome");
        System.out.print("il sig." + cognome);
        long anni = (Long) oggettoJSon.get("eta");
        System.out.println(" di anni " + anni + " parla le seguenti lingue:");
        JSONArray lingue = (JSONArray) oggettoJSon.get("lingue");
        Iterator<String> iterator = lingue.iterator();
        while (iterator.hasNext()) {
            System.out.println("-" + iterator.next());
        }
    }

    public static Object leggiFileJSON(String nomeFile) throws Exception {
        FileReader reader = new FileReader(nomeFile);
        JSONParser parserJSON = new JSONParser();
        return parserJSON.parse(reader);
    }
}
