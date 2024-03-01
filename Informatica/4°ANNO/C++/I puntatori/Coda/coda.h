#ifndef CODA_H
#define CODA_H

class Coda {

private:
    int *p, N, inizio=0, fine=0, N_elem=0;
    int d = 0;
public:
    Coda();
    Coda(int);

    void push(int);
    void pop();
    int top();
    
    bool ifEmpty();
    bool ifFull();
}

#endif
