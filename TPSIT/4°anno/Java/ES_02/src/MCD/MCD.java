package MCD;

import java.util.Scanner;

public class MCD {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Inserire il primo numero: ");
		int n1 = scanner.nextInt();
		System.out.print("Inserire il secondo numero: ");
		int n2 = scanner.nextInt();
		
		int mcd = calcolaMCD (n1,n2);
		
		System.out.println("Il MCD tra " + n1 + " e " + n2 + " è " + mcd);
		
		scanner.close();
		
	}
	
	private static int calcolaMCD (int x, int y){
		
		int r;
		
		if(x<y)
		{
			int z=x;
			x=y;
			y=z;
		}
		
		do
		{
			r=x%y;
			
			if(r!=0)
			{
				x=y;
				y=r;
			}
			
		}while(r!=0);
		
		
		return y;
	}

}
