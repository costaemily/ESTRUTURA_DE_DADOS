#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char elem[100];

typedef struct NoF{
    char conteudo[100];
    struct NoF *prox;
}NoF;

typedef struct Fila{
    NoF *prim;
    NoF *ult;
}Fila;

void criarFila(Fila *f){
    f->prim = NULL;
    f->ult = NULL;
}

int estaVaziaFila(Fila *f){
    if(f->prim == NULL)
        return 1;
    else
        return 0;
}

void inserirFila(Fila *f, char *conteudo){
    NoF *novo = malloc(sizeof(NoF));

    strcpy (novo->conteudo, conteudo);
    //novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVaziaFila(f)){
        f->prim = novo;
        f->ult = novo;
    }else{
        f->ult->prox = novo;
        f->ult = novo;
    }
}

void exibirFila(Fila *f){
    NoF *aux;

    if(estaVaziaFila(f)){
        printf("FILA VAZIA!\n");
    }else{
        aux = f->prim;
        while (aux != f->ult)
        {
            printf("%s ", aux->conteudo);
            aux = aux->prox;
        }
        printf("%s ", aux->conteudo);
        printf("\n\n");
    }
}

char* retirarFila(Fila *f){

    if(estaVaziaFila(f)){
        return NULL;
    }else{
        NoF *aux;
        aux = f->prim;
        if((aux == f->prim) && (aux == f->ult)){
            f->prim = NULL;
            f->ult = NULL;
            strcpy (elem, aux->conteudo);
            free(aux);
        }else{
            f->prim = f->prim->prox;
            strcpy (elem, aux->conteudo);
            free(aux);
        }
    }
    return elem;
}