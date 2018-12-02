#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "file.h"

int main()
{
    int t;
    char path[80];
    printf("De o caminho do catalogo: \n");
    scanf("%s", &path);
    printf("De o tamanho da arvore: \n");
    scanf("%d", &t);
    TAB* arvore = readCatalog(path, t);
    //Imprime(arvore, 0);
    Filme* movie = BuscaFilme(arvore, "Forrest Gump1994");
    printFilme(movie);
    printf("\nAlterado:\n");
    Altera(arvore, "Forrest Gump1994", "teste", "teste2", 95);
    printFilme(movie);
    return 0;
}
