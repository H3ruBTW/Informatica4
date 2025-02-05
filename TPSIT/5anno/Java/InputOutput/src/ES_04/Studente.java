package ES_04;

import java.io.Serializable;

public class Studente implements Serializable{
        
        int id;
        String name;

        Studente(int id, String name){
            this.id = id;
            this.name = name;
        }
}
