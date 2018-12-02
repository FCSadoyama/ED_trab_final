#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include "movie.h"

typedef struct ArvB{
    int nchaves, folha;
    struct Filme **filme;

    struct ArvB **filho;
}TAB;

TAB *Cria(int t);
TAB *Libera(TAB *a);
void Imprime(TAB *a, int andar);
TAB *Busca(TAB* x, char* ch);
Filme *BuscaFilme(TAB* x, char* ch);
TAB *BuscaDiretor(TAB* source, TAB* target, char* nome, int t);
TAB *Inicializa();
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, Filme* k, int t);
TAB *Insere(TAB *T, Filme* k, int t);
void *Altera(TAB *T, char* ch, char* nome_diretor, char* genero, int tempo);
TAB *Remover(TAB* arv, char* ch, int t);
void *RemoverPorGenero(TAB* arv, char* genero, int t);
Filme *BuscaGenero(TAB* x, char* genero);

#endif // ARVORE_H_INCLUDED
