#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "file.h"
#include "menu.h"

int main()
{
    int t;
    char path[80];
    char newPath[80];
    char action = 99;

    printf("De o caminho do catalogo: \n");
    scanf("%s", &path);
    printf("De o tamanho da arvore: \n");
    scanf("%d", &t);
    printf("De o caminho do novo catalogo: \n");
    scanf("%s", &newPath);

    Run(path, t, newPath);

    return 0;
}
