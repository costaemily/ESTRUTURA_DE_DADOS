#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int elem;
	struct no *prox;
	struct no *ant;
}no;

typedef struct lista{
	struct no *prim;
}lista;

void criarLista(lista *l){
	l->prim = NULL;
}
int estaVazia(lista *l){
	if(l->prim == NULL){
		return 1;
	}else{
		return 0;
	}
}
int inserirLista(lista *l, int elem){
	no *novo, *aux;
	
	novo = malloc(sizeof(no));
	if(!novo){
        return 0;
    }

	novo->elem = elem;
	
	if(estaVazia(l)){
		l->prim = novo;
		l->prim->prox = novo;
		l->prim->ant = novo;
	}else{
		aux = l->prim;
		aux = aux->ant;
		aux->prox = novo;
		novo->ant = aux;
		novo->prox = l->prim;
		l->prim->ant = novo;
		l->prim = novo;
	}
    return 1;
}
no* busca(lista *l, int elem){
	no *aux;
    
    if(estaVazia(l)){
		printf("Lista vazia\n");
	}else{
	    aux = l->prim;
	    for(aux = l->prim; aux->prox != l->prim; aux = aux->prox){
		    if(aux->elem == elem){
			    return aux;
		    }	
	    }
	    if(aux->elem == elem){
		    return aux;
	    }
	}
	return aux = NULL;
}
int removerLista(lista *l, int elem){
	no  *aux, *aux2, *aux3;
	no *noBusca;
	
	noBusca = busca(l, elem);
	if(noBusca == NULL){
	    return 0;
	}else{
	    if(noBusca == l->prim){
		    aux = l->prim;
		    if(aux->prox == l->prim){
			    l->prim = NULL;
			    free(aux);
		    }else{
			    aux2 = l->prim->prox;
			    aux3 = l->prim->ant;
			    aux2->ant = aux3;
			    aux3->prox = aux2;
			    l->prim = aux2;
			    free(aux);
		    }
	    }else if(noBusca->ant == l->prim){
		    aux = l->prim;
		    aux2 = noBusca->prox;
		    aux3 = noBusca;
		    aux->prox = aux2;
		    aux2->ant = aux;
		    free(aux3);
		
	    }else if(noBusca->prox == l->prim){
		    aux = l->prim;
		    aux2 = noBusca->ant;
		    aux3 = noBusca;
		    aux2->prox = aux;
		    aux->ant = aux2;
		    free(aux3);
	    }else{
		    aux = noBusca;
		    aux2 = noBusca->prox;
		    aux3 = noBusca->ant;
		    aux3->prox = aux2;
		    aux2->ant = aux3;
		    free(aux);
	    }
	}
	return 1;	
}

void listarNos(lista *l){
	no *aux;
	int n = 1;
	
	if(estaVazia(l)){
		printf("Lista vazia\n");
	}else{
		for(aux = l->prim; aux->prox != l->prim; aux = aux->prox){
			printf("%d° - no\n", n);
			printf(" Elem: %d\n", aux->elem);
			printf("\n\n");
			n++;
		}
			printf("%d° - no\n", n);
			printf(" Elem: %d\n", aux->elem);
			printf("\n\n");
	}
}
int main(){
    setlocale(LC_ALL, "Portuguese");
	int opc = 0, c, elem;
	lista l1;
	no *noBusca;
	
	criarLista(&l1);
	
	while(opc != 5){
		
		printf("Escolha as opcoes abaixo:\n\n|1| Inserir No;\n|2| Remover No;\n|3| Buscar No;\n|4| Listar Nos;\n|5| Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf ("Digite o elemento -inteiro- do No:\n");
				scanf ("%d", &elem);
				if (inserirLista(&l1, elem)){
					printf ("No inserido com sucesso\n");
				} else {
					printf ("No nao inserido\n");
				}
				break;
			case 2: 
				printf ("Digite o No que deseja remover:\n");
				scanf ("%d", &elem);
				if (removerLista(&l1, elem)){
					printf ("No removido com sucesso\n");
				}else {
					printf ("No nao encontrado\n");
				}
				break;
			case 3:
				printf ("Digite o No que deseja buscar:\n");
				scanf ("%d", &elem);
				noBusca = busca(&l1, elem);
				if (noBusca == NULL){
				    printf ("No nao encontrado\n");
				}else{
				    printf ("No encontrado com sucesso\n");
					printf(" Elem: %d\n", noBusca->elem);
				}
				break;
			case 4:
				listarNos(&l1);
			break;
		}
	}
	printf ("\n\n");
	return 0;
}