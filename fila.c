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
    No *novo;

    novo = malloc(sizeof(No));

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
int main(){
    int opc = 1, conteudo;
    Fila f;

    criarFila(&f);

    while (opc != 4)
    {
        printf("\nESCOLHA UMA OPCAO PARA A FILA:\n\n1- INSERIR FILA;\n2- EXIBIR FILA;\n3- RETIRAR FILA;\n4- SAIR.\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("DIGITE O ELEMENTO QUE DESEJA INSERIR NA FILA:\n");
            scanf("%d", &conteudo);
            inserirFila(&f, conteudo);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nFILA DE INTEIROS:\n\n");
            exibirFila(&f);
            system("pause");
            system("cls");
            break;
        case 3:
            retirarFila(&f);
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