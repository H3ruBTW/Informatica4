#ifndef PILA_H
#define PILA_H

class Pila {

private:
    int *p, fine=0;
    const N;
public:
    Pila(int);
    
    void push(int); //inserisce un elemento nell'array
    void pop(); //elimina l'ultimo elemento inserito
    int top(); //visualizza l'ultimo elemento inserito

    bool ifFull(); //controlla se l'array è pieno
    bool ifEmpty(); //controlla se l'array è vuoto
}

#endif