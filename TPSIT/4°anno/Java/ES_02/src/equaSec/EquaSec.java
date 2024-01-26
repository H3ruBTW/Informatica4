package equaSec;

import java.util.Scanner;

public class EquaSec {
	
	static float a, b, c, d, x1, x2;

	public static void main(String[] args) {
		
		int dec;
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Equazioni di secondo grado\nax2+bx+c\nInserire la 'a': ");
		a = scanner.nextInt();
		System.out.print("Inserire la 'b': ");
		b = scanner.nextInt();
		System.out.print("Inserire la 'c': ");
		c = scanner.nextInt();
		
		dec=calcoloDelta();
		
		calcoloEqua(dec);
		
		scanner.close();
	}
	
	private static int calcoloDelta(){
		
		d=(float) Math.pow(b, 2)-4*a*c;
		
		if(d==0)
			return 0;
		
		else if(d>0)
			return 1;
		
			else	
				return -1;
	}
	
	private static void calcoloEqua(int dec) {
	
		if(dec==0)
		{
			x1=(-b)/(2*a);
			System.out.println("La equazione ha un'unica x: " + x1);
		}
		else if(dec==1)
		{
			x1=((-b + (float) Math.sqrt(d))/(2*a));
			x2=((-b - (float) Math.sqrt(d))/(2*a));
			System.out.println("La equazione ha due risultati, x1: " + x1);
			System.out.println("x2: " + x2);
		}
		else
		{
			System.out.println("L'equazione è impossibile\n");
		}
	}

}