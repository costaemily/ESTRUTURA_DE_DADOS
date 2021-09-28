#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include"fila.h"

#define BRANCO 1
#define AMARELO 2
#define VERMELHO 3

typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
}Adjacencia;

typedef struct vertice{
    int id;
    char nome[50];
    struct adjacencia *cab;
}Vertice;

typedef struct grafo{
    int vertices;
    int arestas;
    struct vertice *adj;
}Grafo;

Grafo* criarGrafo(int numVertices){
    int i;
    Grafo *g;

    g = malloc(sizeof(Grafo));

    g->vertices = numVertices;
    g->arestas = 0;
    g->adj = malloc(numVertices * sizeof(Vertice)); 
	
	for (i = 0; i < numVertices; i++){ 
		g->adj[i].cab = NULL; 
	}
	
    return g;
}
void preencherNomes(Grafo *g, char *nome, int id){
    strcpy(g->adj[id].nome, nome);
}
Adjacencia* criarAdjacencia(int vertice, int peso){
    Adjacencia *novo = malloc(sizeof(Adjacencia));

    novo->vertice = vertice;
    novo->peso = peso;
    novo->prox = NULL;
    return novo;
}
int criarAresta(Grafo *g, int vi, int vf, int peso){
    if(!g){
        return 0;
    }
    Adjacencia *novo = criarAdjacencia(vf, peso);
    Adjacencia *novo2 = criarAdjacencia(vi, peso);

    novo->prox = g->adj[vi].cab;
    g->adj[vi].cab = novo;
    novo2->prox = g->adj[vf].cab;
    g->adj[vf].cab = novo2;
    g->arestas++;
    return 1;
}
void imprime(Grafo *g){
	printf("Vertices: %d. Arestas: %d. \n",g->vertices, g->arestas); //imprime numero de vértice e arestas
	int i;
	
    for (i = 0; i < g->vertices; i++)
    {
        Vertice v = g->adj[i];
        printf("V(%s): ", v.nome); 
		Adjacencia *ad = g->adj[i].cab; 
			while(ad){ 
                Vertice c = g->adj[ad->vertice];
				printf("%s(%d) ", c.nome, ad->peso); 
				ad = ad->prox; 
			}
		printf("\n");
    }
}
void visitaP(Grafo *g, int i, int *cor){
    cor[i] = AMARELO;

    Adjacencia *ad = g->adj[i].cab;
    while(ad){
        if(cor[ad->vertice] == BRANCO){
            visitaP(g, ad->vertice, cor);
        }
        ad = ad->prox;
    }
    cor[i] = VERMELHO;
}
void profundidade(Grafo *g){
    int cor[6];

    int i;
    for (i = 0; i < g->vertices; i++)
    {
        cor[i] = BRANCO;
    }
    for (i = 0; i < g->vertices; i++)
    {
        if(cor[i] == BRANCO){
            visitaP(g, i, cor);
        }
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    Grafo *g; 
    g = criarGrafo(6);

    preencherNomes(g, "LAN", 0);
    preencherNomes(g, "LEITOR BIOMETRICO", 1);
    preencherNomes(g, "IMPRESSORA TERMICA", 2);
    preencherNomes(g, "PC RECEPCAO", 3);
    preencherNomes(g, "IMPRESSORA LASER", 4);
    preencherNomes(g, "SERVIDOR", 5);

	criarAresta(g, 0, 1, 10);
	criarAresta(g, 0, 2, 22);
	criarAresta(g, 0, 3, 8);
	criarAresta(g, 0, 4, 14);
	criarAresta(g, 0, 5, 2);
	criarAresta(g, 1, 2, 2);
    criarAresta(g, 3, 4, 9);
    criarAresta(g, 5, 4, 4);
    
    imprime(g);
}