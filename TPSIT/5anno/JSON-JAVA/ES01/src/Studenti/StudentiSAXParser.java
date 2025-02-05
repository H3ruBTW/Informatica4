package Studenti;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

public class StudentiSAXParser extends DefaultHandler {
    private boolean ilNome = false;
    private boolean ilCognome = false;
    private String sNome, sCognome, sID;

    public void startElement(String namespace, String rawName, String dato, Attributes attrib) {
        if (dato.equals("nome")) {
            ilNome = true;
        }
        if (dato.equals("cognome")) {
            ilCognome = true;
        }
        if (dato.equals("studente")) {
            sID = attrib.getValue("ID");
        }
    }

    public void characters(char stringaParserizzata[], int inizio, int lungo) {
        if (ilNome)
            sNome = new String(stringaParserizzata, inizio, lungo);
        if (ilCognome)
            sCognome = new String(stringaParserizzata, inizio, lungo);
    }
    
    public void endElement(String namespaceURI, String rawlleme, String dato) {
        if (dato.equals("indirizzo"))
            System.out.println(sNome + " " + sCognome + " (" + sID + ")");
        if (dato.equals("nome"))
            ilNome = false;
        if (dato.equals("cognome"))
            ilCognome = false;
    }

    public static void main(String args[]) throws Exception {
        String NomeFile = "/mnt/c/Users/aless/Desktop/Codice/Informatica4/TPSIT/5°anno/JSON-JAVA/ES01/src/Studenti/studenti.xml";

        SAXParserFactory SAXPF = SAXParserFactory.newInstance();
        SAXParser saxParser = SAXPF.newSAXParser();

        XMLReader xmlReader = saxParser.getXMLReader();

        try {
            ContentHandler handler = new StudentiSAXParser();
            xmlReader.setContentHandler(handler);
            System.out.println("\nParser del file " + NomeFile);
            xmlReader.parse(NomeFile);
        } catch (Exception e) {
            System.err.println(e.getMessage());
            System.exit(1);
        }
    }
}
