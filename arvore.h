#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct ArvB{
    int nchaves, folha;
    struct Filme **filme;

    struct ArvB **filho;
}TAB;

TAB *Cria(int t);
TAB *Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Inicializa();

#endif // ARVORE_H_INCLUDED
