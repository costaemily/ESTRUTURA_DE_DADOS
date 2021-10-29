#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"
#include "fila.h"

#define MAIS 1
#define MENOS 1
#define VEZES 2
#define DIVIDIR 2

int verificarOperacao(char *oper){
    if(strcmp(oper, "+") == 0){
        return MAIS;
    }else if(strcmp(oper, "-") == 0){
        return MENOS;
    }else if(strcmp(oper, "*") == 0){
        return VEZES;
    }else if (strcmp(oper, "/") == 0){
        return DIVIDIR;
    }
    return 0;
}

void opreracaoListaNaoVazia(Pilha *operadores, Pilha *numeros, char *elem){
    char prim[100], seg[100], oper[100];

    strcpy(prim, pop(numeros));
    strcpy(seg, pop(numeros));
    strcpy(oper, pop(operadores));

    float prime = atof(prim);
    float segu = atof(seg);

    char res[100];
    if(strcmp(oper, "+") == 0){
        sprintf(res, "%g", segu + prime);
        push(numeros, res);
        push(operadores, elem);
    }else if(strcmp(oper, "-") == 0){
        sprintf(res, "%g", segu - prime);
        push(numeros, res);
        push(operadores, elem);
    }else if(strcmp(oper, "*") == 0){
        sprintf(res, "%g", segu * prime);
        push(numeros, res);
        push(operadores, elem);
    }else if(strcmp(oper, "/") == 0){
        sprintf(res, "%g", segu / prime);
        push(numeros, res);
        push(operadores, elem);
    }
}

void operacaoListaVazia(Pilha *operadores, Pilha *numeros){
    char prim[100], seg[100], oper[100];
    strcpy(prim, pop(numeros));
    strcpy(seg, pop(numeros));
    strcpy(oper, pop(operadores));
    
    float prime = atof(prim);
    float segu = atof(seg);

    char res[100];
    if(strcmp(oper, "+") == 0){
        sprintf(res, "%g", segu + prime);
        push(numeros, res);
    }else if(strcmp(oper, "-") == 0){
        sprintf(res, "%g", segu - prime);
        push(numeros, res);
    }else if(strcmp(oper, "*") == 0){
        sprintf(res, "%g", segu * prime);
        push(numeros, res);
    }else if(strcmp(oper, "/") == 0){
        sprintf(res, "%g", segu / prime);
        push(numeros, res);
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    Fila f;
    Pilha numeros, operadores;
    char c[100] = "n";
    char elem[100];

    criarFila(&f);
    criarPilha(&numeros);
    criarPilha(&operadores);

    while(strcmp(c, "s") != 0){
        printf("DIGITE O DIGITO OU OPERACAO DA EXPRESSAO\n\nSE DESEJA SAIR, DIGITE 's':\n\n");
        scanf("%s", c);
        fflush(stdout);
        if(strcmp(c, "s") != 0){
            inserirFila(&f, c);
            printf("\n\nFILA: ");
            exibirFila(&f);
        }else{
            while(!estaVaziaFila(&f)){
                strcpy(elem, retirarFila(&f));
                if(strcmp(elem, "+") == 0 || strcmp(elem, "-") == 0 || strcmp(elem, "*") == 0 || strcmp(elem, "/") == 0){
                    if(estaVaziaPilha(&operadores)){
                        push(&operadores, elem);
                    }else{
                        char pre[100];
                        strcpy (pre, operadores.topo->conteudo);
                        
                        int operPre = verificarOperacao(pre);
                        int elemOpe = verificarOperacao(elem);
                        
                        if(elemOpe > operPre){
                            push(&operadores, elem);
                            
                        }else{
                            opreracaoListaNaoVazia(&operadores, &numeros, elem);
                        }
                    }
                }else{
                    push(&numeros, elem); 
                }
            }

            while(!estaVaziaPilha(&operadores)){
                operacaoListaVazia(&operadores, &numeros);
            }

            printf("\n\nPILHA OPERADORES: ");
            exibirPilha(&operadores);
            printf("\n\nPILHA NUMEROS: ");
            exibirPilha(&numeros);
        }
    }
    return 0;
}