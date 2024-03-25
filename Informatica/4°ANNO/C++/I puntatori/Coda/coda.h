#ifndef CODA_H
#define CODA_H

/*
ANNOTAZIONE

LA CODA COME è STATA IMPLEMENTATA IN QUESTO CODICE LE PERMETTE
DI ESSERE INFINITA E IN CASO DI PIENEZZA DI QUEST'ULTIMA
ELIMINA L'ELEMENTO IN TESTA FACENDO COSì UN POP AUTOMATICO
*/

class Coda {

private:
    int *p, N, inizio=-1, fine=-1;
public:
    Coda();
    Coda(int);

    void push(int);
    void pop();
    int top();
    
    bool ifEmpty();
};

#endif
