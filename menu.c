#include "menu.h"
#include "arvore.h"
#include "file.h"

void Run(char* path, int t, char* newPath){
    TAB* arvore = readCatalog(path, t);
    Imprime(arvore, 0);
    printf("\n");
    int action = 1;
    while (action >0 && action < 5){
        printf("Selecione uma opcao\n1-Inserir filme\n2-Remover filme\n3-Buscar informacoes\n4-Alterar info subordinada\n0-Sair\n");
        int scanned = scanf("%d", &action);
        if (scanned == 1){
            if (action > 0){
                FILE* file = fopen(newPath, "w");
                if (action == 1){ //inserir
                    char nome[80];
                    char diretor[50];
                    char genero[30];
                    int ano, duracao;
                    printf("De o nome do novo filme: ");
                    scanf(" %[^\n]s ", &nome);
                    printf("De o ano do novo filme: ");
                    scanf("%d", &ano);
                    printf("De o diretor do novo filme: ");
                    scanf(" %[^\n]s ", &diretor);
                    printf("De o genero do novo filme: ");
                    scanf(" %[^\n]s ", &genero);
                    printf("De a duracao do novo filme: ");
                    scanf("%d", &duracao);
                    printf("\n\n\n%s\n\n\n", &nome);
                    Filme* filme = initFilme(&nome, ano, &diretor, &genero, duracao);
                    arvore = Insere(arvore, filme, t);
                    Imprime(arvore, 0);
                    writeCatalog(file, arvore);
                }
                if (action == 2) { // remover
                    char pk[84];
                    printf("De a chave primaria do filme a ser removido: ");
                    scanf(" %[^\n]s ", &pk);
                    Filme* filmeRemovido = BuscaFilme(arvore, pk);
                    if (filmeRemovido){
                        arvore = Remover(arvore, filmeRemovido, t);
                        Imprime(arvore, 0);
                        writeCatalog(file, arvore);
                    } else {
                        printf("Filme nao encontrado.\n");
                    }
                }
                if (action == 3){ // buscar
                    char pk[84];
                    printf("Digite a chave primaria: ");
                    scanf(" %[^\n]s ", &pk);
                    char* diretor = BuscaNomeDiretor(arvore, pk);
                    char* genero = BuscaGenero(arvore, pk);
                    int duracao = BuscaDuracao(arvore, pk);
                    printf("\nDiretor: %s | Genero: %s | Duracao: %d\n\n", diretor, genero, duracao);
                }
                if (action == 4) { // remover por diretor
                    char pk[84];
                    printf("Digite a chave primaria: ");
                    scanf(" %[^\n]s ", &pk);
                    Filme* filme = BuscaFilme(arvore, pk);
                    if (filme){
                        printFilme(filme);
                        printf("\n");
                        char* diretor;
                        printf("Digite o novo nome do diretor: ");
                        scanf(" %[^\n]s ", &diretor);
                        char* genero;
                        printf("Digite o novo genero: ");
                        scanf(" %[^\n]s ", &genero);
                        int duracao;
                        printf("Digite a nova duracao: ");
                        scanf("%d", &duracao);

                        Altera(arvore, pk, diretor, genero, duracao);
                        Imprime(arvore, 0);
                        writeCatalog(file, arvore);
                    } else {
                        printf("Filme não encontrado. \n");
                    }
                }
                fclose(file);
            }
        }
        else{
            action = 0;
        }
    }
}
