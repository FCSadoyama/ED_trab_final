#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define TRUE 0
#define FALSE 1

typedef struct filme {
    char titulo[80];
    int ano_lancamento;
    char nome_diretor[50];
    char genero[30];
    int duracao_minutos;
} Filme;

Filme* initFilme(char titulo[80], int ano, char nome_diretor[50], char genero[30], int duracao);
void printFilme(Filme* filme);
char* getPrimaryKey(Filme* filme);
int filmecmp(Filme* target, Filme* filme);

#endif // MOVIE_H_INCLUDED