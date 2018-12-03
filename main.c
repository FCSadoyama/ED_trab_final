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
    TAB* arvore = readCatalog(path, t);
    printf("De o tamanho da arvore: \n");
    scanf("%d", &t);
    printf("De o caminho do novo catalogo: \n");
    scanf("%s", &path);

    arvore = RemoverPorGenero(arvore, "Sci-Fi", t, path);
    //writeCatalog(path, arvore);
    //printFilme(BuscaGenero(arvore, "Sci-Fi"));

    return 0;
}
