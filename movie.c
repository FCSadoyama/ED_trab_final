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

char* getPrimaryKey(Filme* filme){
    char* pk = (char*)malloc(sizeof(char*)*(80+sizeof(filme->ano_lancamento)));
    int i;
    for (i = 0; i < strlen(filme->titulo); i++){
        pk[i] = filme->titulo[i];
    }
    char ano[4];
    sprintf(ano, "%d", filme->ano_lancamento);
    int j;
    for (j = i; j < 4; j++)
        pk[j+1] = ano[j-i];
    return pk;
}
