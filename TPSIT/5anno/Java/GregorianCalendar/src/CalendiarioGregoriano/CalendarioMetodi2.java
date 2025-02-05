package CalendiarioGregoriano;

import java.text.SimpleDateFormat;
import java.util.*;

public class CalendarioMetodi2 {
    void Orario(){
        GregorianCalendar Cal = new GregorianCalendar();
        SimpleDateFormat SDF = new SimpleDateFormat("dd/MM/yyyy - HH:mm:ss");
        
        System.out.println("Orario di avvio metodo seconda Classe:");
        System.out.println(SDF.format(Cal.getTime()));
    }
}
