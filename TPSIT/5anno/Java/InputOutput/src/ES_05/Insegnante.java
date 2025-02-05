package ES_05;

import java.io.Serializable;

public class Insegnante implements Serializable{
        
        int id;
        String name;
        String materia;

        Insegnante(int id, String name, String materia){
            this.id = id;
            this.name = name;
            this.materia = materia;
        }
}
