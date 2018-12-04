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

    Filme* filme = initFilme("teste", 2018, "teste_diretor", "Action", 90);
    arvore = Insere(arvore, filme, t);
    char* diretor = BuscaNomeDiretor(arvore, "3002006");
    char* genero = BuscaGenero(arvore, "3002006");
    int duracao = BuscaDuracao(arvore, "3002006");
    arvore = Remover(arvore, "3002006", t);
    arvore = Altera(arvore, "teste2018", "teste_alterado", "Comedy", 22);
    RemoverPorGenero(arvore, "Action", t, path);
    TAB* arv = BuscaDiretor(arvore, Inicializa(), "George Lucas", t);
    Libera(arvore);
    printf("De o caminho do novo catalogo: \n");
    scanf("%s", &path);
    writeCatalog(path, arv);
    return 0;
}
