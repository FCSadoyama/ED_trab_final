#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "file.h"

int main()
{
    printf("/##############################################/\n");
    printf("/#####            Lista de tarefas        #####/\n");
    printf("/#####        Tarefa         | Realizado? #####/\n");
    printf("/#####        Inserir        |    Sim     #####/\n");
    printf("/#####      Buscar por pk    |    Sim     #####/\n");
    printf("/#####     Remover por pk    |    Sim     #####/\n");
    printf("/#####     Alterar pro pk    |    Sim     #####/\n");
    printf("/#####   Buscar por diretor  |    Sim     #####/\n");
    printf("/##### Remover por categoria |  Parcial   #####/\n");
    printf("/##### Armazenar av em disco |    Sim     #####/\n");
    printf("/##############################################/\n\n\n");

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
