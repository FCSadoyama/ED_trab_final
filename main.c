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
    printf("/#####   Buscar por diretor  |    Nao     #####/\n");
    printf("/##### Remover por categoria |  Parcial   #####/\n");
    printf("/##### Armazenar av em disco |    Nao     #####/\n");
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
    //Imprime(arvore, 0);
    writeCatalog(path, arvore);
    return 0;
}
