#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "movie.h"
#include "arvore.h"
#include "file.h"

Filme* movie_split(char* str)
{
    int i = 0;
    char *p = strtok (str, "/");
    char *array[5];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "/");
    }

    Filme* novo = (Filme*)malloc(sizeof(Filme));
    strcpy(novo->titulo, array[0]);
    novo->ano_lancamento = array[1];
    strcpy(novo->nome_diretor, array[2]);
    strcpy(novo->genero, array[3]);
    novo->duracao_minutos = array[4];

    return novo;
}

TAB* readCatalog(char path[80], int t){
    FILE *fp;
    char buf[1000];
    TAB* arvore = Cria(t);

    fp = fopen(path, "r");
    if(!fp) {
      printf("Arquivo nao encontrado.");
      return arvore;
    }

    while (fgets(buf,1000, fp) != NULL){
        Filme* novo = movie_split(buf);

        //arvore = Insere(arvore, novo, t);
    }

    fclose(fp);
    return arvore;
}
