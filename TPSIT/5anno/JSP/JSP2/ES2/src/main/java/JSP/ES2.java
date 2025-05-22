package JSP;

import java.util.*;
public class ES2 implements java.io.Serializable {
/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String testo;
	public ES2() {
	testo = " ";
	}
	public String getTesto() {
		GregorianCalendar dataAttuale = new GregorianCalendar();
		int ore =
		dataAttuale.get(GregorianCalendar.HOUR_OF_DAY);
		if (ore < 12) {
		testo = "Buongiorno: è mattina!";
		} else if (ore < 17) {
		testo = " Buon Pomeriggio !";
		} else {
		testo = " Buona notte !";
		}
		return testo;
	}
}
