#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "arvore.h"

TAB *Cria(int t){
    TAB* novo = (TAB*)malloc(sizeof(TAB));
    novo->nchaves = 0;
    novo->filme =(Filme*)malloc(sizeof(Filme*)*((t*2)-1));
    novo->folha = 1;
    novo->filho = (TAB**)malloc(sizeof(TAB*)*t*2);
    int i;
    for(i=0; i<(t*2); i++) novo->filho[i] = NULL;
    return novo;
}

TAB *Libera(TAB *a){
    if(a){
        if(!a->folha){
            int i;
            for(i = 0; i <= a->nchaves; i++)
                Libera(a->filho[i]);
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

            for(j=0; j<=andar; j++)
                printf("   ");

            printFilme(a->filme[i]);
            printf("\n");
            //printf("%s\n", getPrimaryKey(a->filme[i]));
        }
        Imprime(a->filho[i],andar+1);
    }
}

TAB *Busca(TAB* x, char* ch){
    TAB *resp = NULL;
    if(!x)
        return resp;

    int i = 0;

    while(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) > 0)
        i++;

    if(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) == 0)
        return x;

    if(x->folha)
        return resp;

    return Busca(x->filho[i], ch);
}

Filme *BuscaFilme(TAB* x, char* ch){
    Filme *resp = NULL;

    if(!x)
        return resp;

    int i = 0;

    while(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) > 0)
        i++;

    if(i < x->nchaves && strcmp(ch, getPrimaryKey(x->filme[i])) == 0)
        return x->filme[i];

    if(x->folha)
        return resp;

    return BuscaFilme(x->filho[i], ch);
}

char* BuscaNomeDiretor(TAB* x, char* ch){
    Filme* filme = BuscaFilme(x, ch);
    return filme->nome_diretor;
}

char* BuscaGenero(TAB* x, char* ch){
    Filme* filme = BuscaFilme(x, ch);
    return filme->genero;
}

int BuscaDuracao(TAB* x, char* ch){
    Filme* filme = BuscaFilme(x, ch);
    return filme->duracao_minutos;
}

TAB *BuscaDiretor(TAB* source, TAB* target, char* nome, int t){
    if(!source)
        return target;

    int i = 0;
    while(i < source->nchaves){
        printFilme(source->filme[i]);
        printf("\n");
        if(strcmp(nome, getDiretor(source->filme[i])) == 0){
            target = Insere(target, source->filme[i], t);
        }
        i++;
    }

    int j = 0;
    while (j <= source->nchaves){
        if (source->filho[j]){
            target = BuscaDiretor(source->filho[j], target, nome, t);
        }
        j++;
    }
    return target;
}

TAB *Inicializa(){
    return NULL;
}

TAB *Divisao(TAB *x, int i, TAB* y, int t){
    TAB *z = Cria(t);
    z->nchaves = t - 1;
    z->folha = y->folha;

    int j;

    for(j=0;j<t-1;j++)
        z->filme[j] = y->filme[j+t];

    if(!y->folha){
        for(j = 0; j < t; j++){
            z->filho[j] = y->filho[j+t];
            y->filho[j+t] = NULL;
        }
    }
    y->nchaves = t-1;

    for(j = x->nchaves; j >= i; j--)
        x->filho[j+1]=x->filho[j];

    x->filho[i] = z;

    for(j = x->nchaves; j >= i; j--)
        x->filme[j] = x->filme[j-1];

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

  while((i>=0) && (strcmp(getPrimaryKey(k), getPrimaryKey(x->filme[i])) < 0))
    i--;
  i++;

  if(x->filho[i]->nchaves == ((2*t)-1)){
    x = Divisao(x, (i+1), x->filho[i], t);
    if(strcmp(getPrimaryKey(k), getPrimaryKey(x->filme[i])) > 0)
        i++;
  }

  x->filho[i] = Insere_Nao_Completo(x->filho[i], k, t);
  return x;
}


TAB *Insere(TAB *T, Filme* k, int t){
  if(Busca(T, getPrimaryKey(k)))
    return T;

  if(!T){
    T = Cria(t);
    T->filme[0] = k;
    T->nchaves = 1;
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

void Altera(TAB *T, char* ch, char* nome_diretor, char* genero, int tempo){
    Filme* movie = BuscaFilme(T, ch);
    strcpy(movie->nome_diretor, nome_diretor);
    strcpy(movie->genero, genero);
    movie->duracao_minutos = tempo;
}

int comparaFilmes(Filme* filme1, Filme* filme2){
    int result = strcmp(getPrimaryKey(filme1), getPrimaryKey(filme2));
    if (result < 0)
        return -1;
    else if (result == 0)
        return 0;
    return 1;
}

TAB* Remover(TAB* arv, Filme* filme, int t){
    if(!arv)
        return arv;
    int i;
    for(i = 0; i < arv->nchaves && comparaFilmes(arv->filme[i], filme) == -1; i++);
    if(i < arv->nchaves && comparaFilmes(filme, arv->filme[i]) == 0){
        if(arv->folha){
            int j;
            for(j = i; j < arv->nchaves-1; j++)
                arv->filme[j] = arv->filme[j+1];
            arv->nchaves--;
            return arv;
        }
        if(!arv->folha && arv->filho[i]->nchaves >= t){
            TAB *y = arv->filho[i];
            while(!y->folha)
                y = y->filho[y->nchaves];
            Filme* temp = y->filme[y->nchaves-1];
            arv->filho[i] = Remover(arv->filho[i], temp, t);
            arv->filme[i] = temp;
            return arv;
        }
        if(!arv->folha && arv->filho[i+1]->nchaves >= t){
            TAB *y = arv->filho[i+1];
            while(!y->folha)
                y = y->filho[0];
            Filme* temp = y->filme[0];
            y = Remover(arv->filho[i+1], temp, t);
            arv->filme[i] = temp;
            return arv;
        }
        if(!arv->folha && arv->filho[i+1]->nchaves == t-1 && arv->filho[i]->nchaves == t-1){
            TAB *y = arv->filho[i];
            TAB *z = arv->filho[i+1];
            y->filme[y->nchaves] = filme;
            int j;
            for(j = 0; j < t-1; j++)
                y->filme[t+j] = z->filme[j];
            for(j=0; j<=t; j++)
                y->filho[t+j] = z->filho[j];
            y->nchaves = 2*t-1;
            for(j = i; j < arv->nchaves-1; j++)
                arv->filme[j] = arv->filme[j+1];
            for(j = i+1; j <= arv->nchaves; j++)
                arv->filho[j] = arv->filho[j+1];
            arv->filho[j] = NULL;
            arv->nchaves--;
            arv->filho[i] = Remover(arv->filho[i], filme, t);
            return arv;
        }
    }
    TAB *y = arv->filho[i], *z = NULL;
    if (y->nchaves == t-1){
        if((i < arv->nchaves) && (arv->filho[i+1]->nchaves >=t)){
            z = arv->filho[i+1];
            y->filme[t-1] = arv->filme[i];
            y->nchaves++;
            arv->filme[i] = z->filme[0];
            int j;
            for(j = 0; j < z->nchaves-1; j++)
                z->filme[j] = z->filme[j+1];
            y->filho[y->nchaves] = z->filho[0];
            for(j = 0; j < z->nchaves; j++)
                z->filho[j] = z->filho[j+1];
            z->nchaves--;
            arv->filho[i] = Remover(arv->filho[i], filme, t);
            return arv;
        }
        if((i > 0) && (!z) && (arv->filho[i-1]->nchaves >=t)){
            z = arv->filho[i-1];
            int j;
            for(j = y->nchaves; j > 0; j--)
                y->filme[j] = y->filme[j-1];
            for(j = y->nchaves+1; j > 0; j--)
                y->filho[j] = y->filho[j-1];
            y->filme[0] = arv->filme[i-1];
            y->nchaves++;
            arv->filme[i-1] = z->filme[z->nchaves-1];
            y->filho[0] = z->filho[z->nchaves];
            z->nchaves--;
            arv->filho[i] = Remover(y, filme, t);
            return arv;
        }
        if(!z){
            if(i < arv->nchaves && arv->filho[i+1]->nchaves == t-1){
                z = arv->filho[i+1];
                y->filme[t-1] = arv->filme[i];
                y->nchaves++;
                int j;
                for(j=0; j < t-1; j++){
                    y->filme[t+j] = z->filme[j];
                    y->nchaves++;
                }
                if(!y->folha){
                    for(j = 0; j < t; j++){
                        y->filho[t+j] = z->filho[j];
                    }
                }
                for(j = i; j < arv->nchaves-1; j++){
                    arv->filme[j] = arv->filme[j+1];
                    arv->filho[j+1] = arv->filho[j+2];
                }
                arv->nchaves--;
                arv = Remover(arv, filme, t);
                return arv;
            }
            if((i > 0) && (arv->filho[i-1]->nchaves == t-1)){
                z = arv->filho[i-1];
                if(i == arv->nchaves)
                    z->filme[t-1] = arv->filme[i-1];
                else
                    z->filme[t-1] = arv->filme[i];
                z->nchaves++;
                int j;
                for(j=0; j < t-1; j++){
                    z->filme[t+j] = y->filme[j];
                    z->nchaves++;
                }
                if(!z->folha){
                    for(j=0; j<t; j++){
                        z->filho[t+j] = y->filho[j];
                    }
                }
                arv->nchaves--;
                arv->filho[i-1] = z;
                arv = Remover(arv, filme, t);
                return arv;
            }
        }
    }
    arv->filho[i] = Remover(arv->filho[i], filme, t);
    return arv;
}

TAB *RemoverPorGenero(TAB* arv, char* genero, int t){
    printf("\n%s\n", genero);
    Filme* movie = BuscaPorGenero(arv, genero);
    while(movie){
        arv = Remover(arv, movie, t);
        movie = BuscaPorGenero(arv, genero);
    }
    return arv;
}

Filme *BuscaPorGenero(TAB* source, char* genero){
    Filme *resp = NULL;
    if(!source)
        return resp;

    int i = 0;
    while(i < source->nchaves){
        if(strcmp(genero, getGenero(source->filme[i])) == 0){
            return source->filme[i];
        }
        i++;
    }

    int j = 0;
    while (j <= source->nchaves){
        if (source->filho[j]){
            Filme* filme = BuscaPorGenero(source->filho[j], genero);
            if (filme)
                return filme;
        }
        j++;
    }
    return resp;
}
