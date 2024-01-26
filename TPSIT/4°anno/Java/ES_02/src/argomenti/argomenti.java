package argomenti;

public class argomenti {

	public static void main(String[] args) {
		
		int somma=0, magg=Integer.parseInt(args[0]), min=Integer.parseInt(args[0]);
		float media=0;
		System.out.println("Numero di argomenti: " + args.length);

        System.out.println("Argomenti:");
        for (int i = 0; i < args.length; i++) {
            System.out.println("Argomento[ " + i + "]: " + args[i]);
            somma+=Integer.parseInt(args[i]);
            media+=Integer.parseInt(args[i]);
            
            if(Integer.parseInt(args[i])>magg)
            	magg=Integer.parseInt(args[i]);
            if(Integer.parseInt(args[i])<min)
            	min=Integer.parseInt(args[i]);
        }
        
        System.out.println("La somma degli argomenti è: " + somma);
        System.out.println("La media degli argomenti è: " + media/args.length);
        System.out.println("Il maggiore tra gli argomenti è: " + magg);
        System.out.println("Il minore tra gli argomenti è: " + min);
	}

}
