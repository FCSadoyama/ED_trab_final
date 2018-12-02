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
    printf("De o tamanho da arvore: \n");
    scanf("%d", &t);
    TAB* arvore = readCatalog(path, t);
    Imprime(arvore, 0);
    printf("\n\nRemovido:\n\n");
    TAB* arvore2 = BuscaDiretor(arvore, Inicializa(), "George Lucas", t);
    Imprime(arvore2, 0);
    return 0;
}
