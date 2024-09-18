package primo;

public class primoFunc {
    primoFunc(){
        System.out.println("Ciao!");
    }

    primoFunc(int x, int y){
        System.out.println(x + " + " + y + " = " + somma2(x,y));
    }

    int somma2 (int x, int y){
        return x+y;
    }

    int prod3 (int x, int y, int z){
        return x*y*z;
    }
}
