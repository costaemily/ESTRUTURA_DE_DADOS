#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
}No;

typedef struct fila{
    No *prim;
    No *ult;
}Fila;

void criarFila(Fila *f){
    f->prim = NULL;
    f->ult = NULL;
}
int estaVazia(Fila *f){
    if(f->prim == NULL)
        return 1;
    else
        return 0;
}
void inserirFila(Fila *f, int conteudo){
    No *novo = malloc(sizeof(No));

    novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVazia(f)){
        f->prim = novo;
        f->ult = novo;
    }else{
        f->ult->prox = novo;
        f->ult = novo;
    }
}
void exibirFila(Fila *f){
    No *aux;

    if(estaVazia(f)){
        printf("\nFILA VAZIA!\n");
    }else{
        aux = f->prim;
        while (aux != f->ult)
        {
            printf("%d ", aux->conteudo);
            aux = aux->prox;
        }
        printf("%d ", aux->conteudo);
        printf("\n\n");
    }
}
void retirarFila(Fila *f){
    if(estaVazia(f)){
        printf("\nESTA VAZIA\n");
    }else{
        No *aux;
        aux = f->prim;
        if((aux == f->prim) && (aux == f->ult)){
            f->prim = NULL;
            f->ult = NULL;
            free(aux);
        }else{
            f->prim = f->prim->prox;
            free(aux);
        }
        printf("\nELEMENTO RETIRADO COM SUCESSO!\n");
    }
}