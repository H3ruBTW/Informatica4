package XML;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import javax.xml.transform.*;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;

public class ApplyXSLTWin {
    public static void main(String[] args) {
        try {
            TransformerFactory factory = TransformerFactory.newInstance();
            Source xslt = new StreamSource(new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\XML-JAVA\\ES02\\src\\XML\\maestri3.xsl"));
            Transformer transformer = factory.newTransformer(xslt);

            Source xml = new StreamSource(new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\XML-JAVA\\ES02\\src\\XML\\maestri3.xml"));
            transformer.transform(xml, new StreamResult(new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\XML-JAVA\\ES02\\src\\XML\\output.html")));
            try {
                File xmlFile = new File("C:\\Users\\aless\\Desktop\\Codice\\Informatica4\\TPSIT\\5°anno\\XML-JAVA\\ES02\\src\\XML\\output.html");
                if (xmlFile.exists() && Desktop.isDesktopSupported()) {
                    Desktop d = Desktop.getDesktop();
                    d.open(xmlFile);

                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
