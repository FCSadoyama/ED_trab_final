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

TAB *Busca(TAB* x, char* ch){
  TAB *resp = NULL;
  if(!x) return resp;
  int i = 0;
  while(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) > 0) i++;
  if(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) == 0) return x;
  if(x->folha) return resp;
  return Busca(x->filho[i], ch);
}

TAB *Inicializa(){
    return NULL;
}

TAB *Divisao(TAB *x, int i, TAB* y, int t){
  TAB *z=Cria(t);
  z->nchaves= t - 1;
  z->folha = y->folha;
  int j;
  for(j=0;j<t-1;j++) z->filme[j] = y->filme[j+t];
  if(!y->folha){
    for(j=0;j<t;j++){
      z->filho[j] = y->filho[j+t];
      y->filho[j+t] = NULL;
    }
  }
  y->nchaves = t-1;
  for(j=x->nchaves; j>=i; j--) x->filho[j+1]=x->filho[j];
  x->filho[i] = z;
  for(j=x->nchaves; j>=i; j--) x->filme[j] = x->filme[j-1];
  x->filme[i-1] = y->filme[t-1];
  x->nchaves++;
  return x;
}


TAB *Insere_Nao_Completo(TAB *x, Filme* k, int t){
  int i = x->nchaves-1;
  if(x->folha){
    while((i>=0) && (strcmp(getPrimaryKey(k), getPrimaryKey(x->filme[i])) < 0)){
      x->filme[i+1] = x->filme[i];
      i--;
    }
    x->filme[i+1] = k;
    x->nchaves++;
    return x;
  }
  while((i>=0) && (strcmp(getPrimaryKey(k), getPrimaryKey(x->filme[i])) < 0)) i--;
  i++;
  if(x->filho[i]->nchaves == ((2*t)-1)){
    x = Divisao(x, (i+1), x->filho[i], t);
    if(strcmp(getPrimaryKey(k), getPrimaryKey(x->filme[i])) > 0) i++;
  }
  x->filho[i] = Insere_Nao_Completo(x->filho[i], k, t);
  return x;
}


TAB *Insere(TAB *T, Filme* k, int t){
  if(Busca(T,k)) return T;
  if(!T){
    T=Cria(t);
    T->filme[0] = k;
    T->nchaves=1;
    return T;
  }
  if(T->nchaves == (2*t)-1){
    TAB *S = Cria(t);
    S->nchaves = 0;
    S->folha = 0;
    S->filho[0] = T;
    S = Divisao(S,1,T,t);
    S = Insere_Nao_Completo(S,k,t);
    return S;
  }
  T = Insere_Nao_Completo(T,k,t);
  return T;
}
