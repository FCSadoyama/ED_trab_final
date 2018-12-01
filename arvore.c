#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "arvore.h"

TAB *Cria(int t){
    TAB* novo = (TAB*)malloc(sizeof(TAB));
    novo->nchaves = 0;
    novo->filme =(Filme*)malloc(sizeof(Filme*)*((t*2)-1));
    novo->folha=1;
    novo->filho = (TAB**)malloc(sizeof(TAB*)*t*2);
    int i;
    for(i=0; i<(t*2); i++) novo->filho[i] = NULL;
    return novo;
}

TAB *Libera(TAB *a){
    if(a){
        if(!a->folha){
            int i;
            for(i = 0; i <= a->nchaves; i++) Libera(a->filho[i]);
        }
        free(a->filme);
        free(a->filho);
        free(a);
        return NULL;
    }
}

void Imprime(TAB *a, int andar){
    if(a){
        int i,j;
        for(i=0; i<=a->nchaves-1; i++){
            Imprime(a->filho[i],andar+1);
            for(j=0; j<=andar; j++) printf("   ");
            printFilme(a->filme[i]);
        }
        Imprime(a->filho[i],andar+1);
    }
}

TAB *Inicializa(){
    return NULL;
}
