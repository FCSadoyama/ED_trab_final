#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

void printFilme(Filme* filme){
    printf("%s | %d | %s | %s | %d", filme->titulo, filme->ano_lancamento, filme->nome_diretor, filme->genero, filme->duracao_minutos);
}
