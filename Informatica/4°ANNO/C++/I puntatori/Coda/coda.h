#ifndef CODA_H
#define CODA_H

class Coda {

private:
    int *p, N, inizio=0, fine=-1;
public:
    Coda();
    Coda(int);

    void push(int);
    void pop();
    int top();
    
    bool ifEmpty();
}

#endif
