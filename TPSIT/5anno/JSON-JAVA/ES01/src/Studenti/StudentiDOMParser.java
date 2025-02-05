package Studenti;

import java.io.File;
import javax.xml.parsers.*;
import org.w3c.dom.*;

public class StudentiDOMParser {
    public static void main(String[] args) {
        String nomeFile = "/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/JSON-JAVA/ES01/src/Studenti/studenti.xml";
        StudentiDOMParser dp = new StudentiDOMParser();
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();

        try {
            DocumentBuilder builder = dbf.newDocumentBuilder();
            File xmlFile = new File(nomeFile);
            Document documento = builder.parse(xmlFile);
            dp.stampaNodo(documento);
        } catch (Exception e){
            System.err.println(e.getMessage());
            System.exit(1);
        }
    }

    public void stampaNodo(Node nodoCorrente) {
        String elencoAttributi;
        short sNodeType = nodoCorrente.getNodeType();

        if (sNodeType == Node.ELEMENT_NODE) {
            String nomeNodo = nodoCorrente.getNodeName();
            if ("studente".equals(nomeNodo)){
                System.out.print("\n");
                System.out.print("Elemento: " + nomeNodo);
            }
                
            String valoreNodo = analizza(nodoCorrente);
            if (!valoreNodo.trim().equalsIgnoreCase("")) {
                System.out.print(" = " + valoreNodo);
            }

            NamedNodeMap attributi = nodoCorrente.getAttributes();
            elencoAttributi = formattaAttributi(attributi);
            if (elencoAttributi != "assenti"){
                System.out.print("\tAttributi: " + elencoAttributi);
            }
            System.out.print("\n");    
        }

        int nrFigli = nodoCorrente.getChildNodes().getLength();
        if (nodoCorrente.hasChildNodes()) {
            NodeList figli = nodoCorrente.getChildNodes();

            for (int conta = 0; conta < nrFigli; conta++) {
                stampaNodo(figli.item(conta));
            }
        }
    }

    private static String analizza(Node elementNode) {
        String testo = "";

        if (elementNode.hasChildNodes()) {
            Node testoFiglio = elementNode.getChildNodes().item(0);
            testo = testoFiglio.getNodeValue();
        } 

        return testo;
    }

    private static String formattaAttributi(NamedNodeMap nnm) {
        String elenco = new String();
        if (nnm != null && nnm.getLength() > 0) {
            for (int conta = 0; conta < nnm.getLength(); conta++) {
                elenco += nnm.item(conta).getNodeName();
                elenco += "=";
                elenco += nnm.item(conta).getNodeValue();
                elenco += ";";
            }
            return elenco;
        } else {
           return "assenti"; 
        }
    }
}
