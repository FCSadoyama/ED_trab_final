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
    Imprime(arvore, 0);
    return 0;
}
