#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
}No;

typedef struct lista{
    No *prim;
}Lista;

void criarLista(Lista *l){
    l->prim = NULL;
}
int estaVazia(Lista *l){
    if(l->prim == NULL)
        return 1;
    else
        return 0;
}
void inserirListaInicio(Lista *l, int conteudo){
    No *novo;

    novo = malloc(sizeof(No));

    novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVazia(l)){
        l->prim = novo;
    }else{
        novo->prox = l->prim;
        l->prim = novo;
    }
}
void exibirLista(Lista *l){
    No *aux;

    if(estaVazia(l)){
        printf("\nLISTA VAZIA!\n");
    }else{
        aux = l->prim;
        while (aux)
        {
            printf("%d ", aux->conteudo);
            aux = aux->prox;
        }
        printf("\n\n");
    }
}
int main(){
    int opc = 1, conteudo;
    Lista l;

    criarLista(&l);

    while (opc != 4)
    {
        printf("\nESCOLHA UMA OPCAO PARA A LISTA:\n\n1- INSERIR LISTA INICIO;\n2- INSERIR LISTA FIM;\n3- EXIBIR LISTA;\n4- SAIR.\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("DIGITE O ELEMENTO QUE DESEJA INSERIR NA LISTA:\n");
            scanf("%d", &conteudo);
            inserirListaInicio(&l, conteudo);
            system("pause");
            system("cls");
            break;
        case 2:

            break;
        case 3:
            printf("\nLISTA DE INTEIROS:\n\n");
            exibirLista(&l);
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