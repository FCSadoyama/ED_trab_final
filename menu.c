#include "menu.h"
#include "arvore.h"

void Run(char* path, int t, char* newPath){
    TAB* arvore = readCatalog(path, t);
    Imprime(arvore, 0);
    printf("\n");
    int action = 1;
    while (action >0 && action < 5){
        printf("Selecione uma opcao\n1-Inserir filme\n2-Remover filme\n3-Buscar por diretor\n4-Remover por genero\n0-Sair\n");
        if (scanf("%d", &action) == 1){
            if (action > 0){
                if (action == 1){ //inserir
                    char nome[80];
                    char diretor[50];
                    char genero[30];
                    int ano, duracao;
                    printf("De o nome do novo filme: ");
                    scanf("%s", &nome);
                    printf("De o ano do novo filme: ");
                    scanf("%d", &ano);
                    printf("De o diretor do novo filme: ");
                    scanf("%s", &diretor);
                    printf("De o genero do novo filme: ");
                    scanf("%s", &genero);
                    printf("De a duracao do novo filme: ");
                    scanf("%d", &duracao);
                    printf("\n\n\n%s\n\n\n", &nome);
                    Filme* filme = initFilme(&nome, ano, &diretor, &genero, duracao);
                    arvore = Insere(arvore, filme, t);
                    Imprime(arvore, 0);
                    writeCatalog(newPath, arvore);
                } else if (action == 2) { // remover
                    char pk[84];
                    printf("De a chave primaria do filme a ser removido: ");
                    scanf("%s", &pk);
                    arvore = Remover(arvore, &pk, t);
                    Imprime(arvore, 0);
                    writeCatalog(newPath, arvore);
                } else if (action == 3){ // buscar

                } else if (action == 4) { // remover por diretor

                }
            }
        }
        else{
            action = 0;
        }
    }
}
