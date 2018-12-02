#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "file.h"

int main()
{
    printf("/##############################################/\n");
    printf("/#####            Lista de tarefas        #####/\n");
    printf("/#####        Tarefa         | Realizado? #####/\n");
    printf("/#####        Inserir        |      S     #####/\n");
    printf("/#####      Buscar por pk    |      S     #####/\n");
    printf("/#####     Remover por pk    |      N     #####/\n");
    printf("/#####     Alterar pro pk    |      S     #####/\n");
    printf("/#####   Buscar por diretor  |      N     #####/\n");
    printf("/##### Remover por categoria |      N     #####/\n");
    printf("/##############################################/\n\n\n");

    int t;
    char path[80];
    printf("De o caminho do catalogo: \n");
    scanf("%s", &path);
    printf("De o tamanho da arvore: \n");
    scanf("%d", &t);
    TAB* arvore = readCatalog(path, t);
    //Imprime(arvore, 0);
    return 0;
}
