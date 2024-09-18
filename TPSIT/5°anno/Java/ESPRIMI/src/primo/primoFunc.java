package primo;

public class primoFunc {
    primoFunc(){
        System.out.println("Ciao!");
    }

    primoFunc(int x){
        System.out.println(x + " + " + x + " = " + somma2(x,x));
    }

    primoFunc(int x, int y){
        System.out.println(x + " + " + y + " = " + somma2(x,y));
    }

    primoFunc(int x, int y, int z){
        System.out.println(x + " + " + y + " + " + z  + " = " + somma2(somma2(x,y), z));
    }

    primoFunc(int x, int y, int z, int x2){
        System.out.println(x + " * " + y + " * " + z + " + " + x2 + " = " + somma2(prod3(x, y, z), x2));
    }

    int somma2 (int x, int y){
        return x+y;
    }

    int prod3 (int x, int y, int z){
        return x*y*z;
    }
}
