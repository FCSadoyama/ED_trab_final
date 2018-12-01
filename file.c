#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "movie.h"
#include "arvore.h"
#include "file.h"

char * str_split(char* str)
{
    int i = 0;
    char *p = strtok (str, "/");
    char *array[5];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "/");
    }

    return array;
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
        printf("%s",buf);
        char* tokens = str_split(buf);
        Filme* novo = (Filme*)malloc(sizeof(Filme*));
        if (tokens){
            int i;
            strcpy(novo->titulo, tokens[0]);
            novo->ano_lancamento = tokens[1];
            strcpy(novo->nome_diretor, tokens[2]);
            strcpy(novo->genero, tokens[3]);
            novo->duracao_minutos = tokens[4];
            free(tokens);
        }
        else{
            novo = NULL;
        }

        arvore = Insere(arvore, novo, t);
    }

    fclose(fp);
    return arvore;
}
