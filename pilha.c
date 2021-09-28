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
int main(){
    int opc = 1, conteudo;
    Pilha p;

    criarPilha(&p);

    while (opc != 4)
    {
        printf("\nESCOLHA UMA OPCAO PARA A PILHA:\n\n1- EMPILHAR (PUSH);\n2- DESEMPILHAR (POP);\n3- EXIBIR PILHA;\n4- SAIR.\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("DIGITE O ELEMENTO QUE DESEJA EMPILHAR:\n");
            scanf("%d", &conteudo);
            push(&p, conteudo);
            system("pause");
            system("cls");
            break;
        case 2:
            pop(&p);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nPILHA DE INTEIROS:\n\n");
            exibirPilha(&p);
            system("pause");
            system("cls");
            break;
        case 4:
            system("pause");
            system("exit");
            break;
        default:
            printf("\nDIGITE UMA OPCAO VALIDA!\n");
            system("pause");
            system("cls");
            break;
        }
    }
}