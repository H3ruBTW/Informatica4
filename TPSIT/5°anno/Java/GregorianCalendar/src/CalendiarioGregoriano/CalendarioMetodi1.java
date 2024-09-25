package CalendiarioGregoriano;

import java.util.*;

public class CalendarioMetodi1 {
    void Orario(){
        GregorianCalendar Cal = new GregorianCalendar();
        int giorno = Cal.get(Calendar.DAY_OF_MONTH);
        int mese = Cal.get(Calendar.MONTH);
        int anno = Cal.get(Calendar.YEAR);
        int H = Cal.get(Calendar.HOUR_OF_DAY);
        int m = Cal.get(Calendar.MINUTE);
        int S = Cal.get(Calendar.SECOND);
        System.out.println("Orario di avvio metodo prima Classe:");
        System.out.println(giorno + "/" + mese + "/" + anno + " - " + H + ":" + m + ":" + S);
    }
}
