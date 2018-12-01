#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct filme {
    char titulo[80];
    int ano_lancamento;
    char nome_diretor[50];
    char genero[30];
    int duracao_minutos;
} Filme;

void printFilme(Filme* filme);

#endif // MOVIE_H_INCLUDED
