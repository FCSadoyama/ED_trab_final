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
    printf("Caminho: %s | Tamanho: % d \n", path, t);
    TAB* arvore = readCatalog(path, t);
    return 0;
}
