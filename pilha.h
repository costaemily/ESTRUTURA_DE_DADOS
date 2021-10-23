#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

void criarPilha(Pilha *p){
    p->topo = NULL;
}
int estaVazia(Pilha *p){
    if(p->topo == NULL)
        return 1;
    else
        return 0;
}
void push(Pilha *p, int conteudo){
    No *novo;

    novo = malloc(sizeof(No));

    novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVazia(p)){
        p->topo = novo;
    }else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}
void pop(Pilha *p){
    if(estaVazia(p)){
        printf("\nPILHA VAZIA!\n");
    }else{
        No *aux;
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
        printf("\nELEMENTO RETIRADO COM SUCESSO!\n");
    }
}
void exibirPilha(Pilha *p){
    No *aux;

    if (estaVazia(p)){
        printf("\nPILHA VAZIA!\n");
    }else{
        aux = p->topo;
        while (aux)
        {
            printf("%d\n", aux->conteudo);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}