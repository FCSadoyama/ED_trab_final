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
char* BuscaNomeDiretor(TAB* x, char* ch);
char* BuscaGenero(TAB* x, char* ch);
int BuscaDuracao(TAB* x, char* ch);
TAB *BuscaDiretor(TAB* source, TAB* target, char* nome, int t);
TAB* Concat(TAB* source, TAB* target, int t);
TAB *Inicializa();
TAB *Divisao(TAB *x, int i, TAB* y, int t);
TAB *Insere_Nao_Completo(TAB *x, Filme* k, int t);
TAB *Insere(TAB *T, Filme* k, int t);
void *Altera(TAB *T, char* ch, char* nome_diretor, char* genero, int tempo);
int comparaFilmes(Filme* filme1, Filme* filme2);
TAB *Remover(TAB* arv, Filme* filme, int t);
TAB *RemoverPorGenero(TAB* arv, char* genero, int t, char* path);
Filme *BuscaPorGenero(TAB* x, char* genero);

#endif // ARVORE_H_INCLUDED
