#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

Filme* initFilme(char titulo[80], int ano, char nome_diretor[50], char genero[30], int duracao){
    Filme* novo = (Filme*)malloc(sizeof(Filme));
    strcpy(novo->titulo, titulo);
    novo->ano_lancamento = ano;
    strcpy(novo->nome_diretor, nome_diretor);
    strcpy(novo->genero, genero);
    novo->duracao_minutos = duracao;
    return novo;
}

void printFilme(Filme* filme){
    printf("%s | %d | %s | %s | %d", filme->titulo, filme->ano_lancamento, filme->nome_diretor, filme->genero, filme->duracao_minutos);
}

char* printFilmeInFile(Filme *filme){
    char ano[sizeof(int) * 4 + 1];
    sprintf(ano, "%d", filme->ano_lancamento);
    char duracao[sizeof(int) * 4 + 1];
    sprintf(duracao, "%d", filme->duracao_minutos);
    char *pk = malloc(strlen(filme->titulo) + strlen(ano) + strlen(filme->nome_diretor) + strlen(filme->genero) + strlen(duracao) + 1);
    strcpy(pk, filme->titulo);
    strcat(pk, "/");
    strcat(pk, ano);
    strcat(pk, "/");
    strcat(pk, filme->nome_diretor);
    strcat(pk, "/");
    strcat(pk, filme->genero);
    strcat(pk, "/");
    strcat(pk, filme->duracao_minutos);
    return pk;
}

char* getPrimaryKey(Filme* filme){
    char ano[sizeof(int) * 4 + 1];
    sprintf(ano, "%d", filme->ano_lancamento);
    char *pk = malloc(strlen(filme->titulo) + strlen(ano) + 1);
    strcpy(pk, filme->titulo);
    strcat(pk, ano);
    return pk;
}

char* getDiretor(Filme* filme){
    if (!filme)
        return "";
    return filme->nome_diretor;
}

char* getGenero(Filme* filme){
    if (!filme)
        return "";
    return filme->genero;
}
