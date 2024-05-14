#ifndef LISTA_H
#define LISTA_H

struct s_nodo
{
    int info;
    struct s_nodo* next;
}typedef s_nodo;


class lista
{
private:
    s_nodo* L;
public:
    lista();
    void insInTesta(int):
    void cancInTesta();
    void insInCoda(int);
    void cancInCoda();
    void stampaLista();
    bool isEmpty();
    void inserisciNodo(int, int);
    void cancellaNodo(int);
};

#endif