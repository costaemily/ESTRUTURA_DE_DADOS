#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char elem[100];

typedef struct NoP{
    char conteudo[100];
    struct NoP *prox;
}NoP;

typedef struct Pilha{
    NoP *topo;
}Pilha;

void criarPilha(Pilha *p){
    p->topo = NULL;
}

int estaVaziaPilha(Pilha *p){
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}

void push(Pilha *p, char *conteudo){
    NoP *novo = malloc(sizeof(NoP));

    strcpy (novo->conteudo, conteudo);
    //novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVaziaPilha(p)){
        p->topo = novo;
    }else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

char* pop(Pilha *p){

    if(estaVaziaPilha(p)){
        return NULL;
    }else{
        NoP *aux;
        aux = p->topo;
        strcpy (elem, aux->conteudo);
        p->topo = p->topo->prox;
        free(aux);
    }
    return elem;
}

void exibirPilha(Pilha *p){
    NoP *aux;

    if (estaVaziaPilha(p)){
        printf("PILHA VAZIA!\n");
    }else{
        aux = p->topo;
        while (aux)
        {
            printf("%s ", aux->conteudo);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}