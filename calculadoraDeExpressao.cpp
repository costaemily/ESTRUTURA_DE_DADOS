#include <iostream>
#include <string>

#define MAIS 1
#define MENOS 1
#define VEZES 2
#define DIVIDIR 2

using namespace std;

typedef struct NoF{
    string conteudo;
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

void inserirFila(Fila *f, string conteudo){
    NoF *novo = new NoF; 

    novo->conteudo = conteudo;
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
        cout << "FILA VAZIA!\n";
    }else{
        aux = f->prim;
        while (aux != f->ult)
        {
            cout << aux->conteudo << " ";
            aux = aux->prox;
        }
        cout << aux->conteudo;
        cout << "\n\n";
    }
}

string retirarFila(Fila *f){
    string elem;

    if(estaVaziaFila(f)){
        return NULL;
    }else{
        NoF *aux;
        aux = f->prim;
        if((aux == f->prim) && (aux == f->ult)){
            f->prim = NULL;
            f->ult = NULL;
            elem = aux->conteudo;
            free(aux);
        }else{
            f->prim = f->prim->prox;
            elem = aux->conteudo;
            free(aux);
        }
    }
    return elem;
}

typedef struct NoP{
    string conteudo;
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

void push(Pilha *p, string conteudo){
    NoP *novo = new NoP; 
    
    novo->conteudo = conteudo;
    novo->prox = NULL;

    if(estaVaziaPilha(p)){
        p->topo = novo;
    }else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

string pop(Pilha *p){

    string elem;
    if(estaVaziaPilha(p)){
        return NULL;
    }else{
        NoP *aux;
        aux = p->topo;
        elem = aux->conteudo;
        p->topo = p->topo->prox;
        free(aux);
    }
    return elem;
}

void exibirPilha(Pilha *p){
    NoP *aux;

    if (estaVaziaPilha(p)){
        cout << "PILHA VAZIA!\n";
    }else{
        aux = p->topo;
        while (aux)
        {
            cout << aux->conteudo << endl;
            aux = aux->prox;
        }
        cout << "\n\n";
    }
}

int verificarOperacao(string oper){
    if(oper ==  "+"){
        return MAIS;
    }else if(oper ==  "-"){
        return MENOS;
    }else if(oper ==  "*"){
        return VEZES;
    }else if (oper ==  "/"){
        return DIVIDIR;
    }
    return 0;
}

string calcular(Pilha *operadores, Pilha *numeros){
    string prim, seg, oper;

    prim = pop(numeros);
    seg = pop(numeros);
    oper = pop(operadores);
    
    float prime = stof(prim);
    float segu = stof(seg);

    string res;
    if(oper ==  "+"){
        return res = to_string(segu + prime);
    }else if(oper ==  "-"){
        return res = to_string(segu - prime);
    }else if(oper ==  "*"){
        return res = to_string(segu * prime);
    }else if(oper ==  "/"){
        return res = to_string(segu / prime);
    }
    return NULL;
}

int main(){

    Fila f;
    Pilha numeros, operadores;
    string c = "n";
    string elem;

    criarFila(&f);
    criarPilha(&numeros);
    criarPilha(&operadores);

    while(c != "s"){
        cout << "DIGITE UM NUMERO OU OPERACAO DA EXPRESSAO POR VEZ\n\nSE DESEJA SAIR, DIGITE 's':\n\n";
        cin >> c;
        fflush(stdout);
        if(c != "s"){
            inserirFila(&f, c);
            system("cls");
            cout << "\nFILA: ";
            exibirFila(&f);
        }else{
            while(!estaVaziaFila(&f)){
                elem = retirarFila(&f);
                if(elem ==  "+" || elem ==  "-" || elem ==  "*" || elem ==  "/"){
                    if(estaVaziaPilha(&operadores)){
                        push(&operadores, elem);
                    }else{
                        string pre;
                        pre = operadores.topo->conteudo;
                        
                        int operPre = verificarOperacao(pre);
                        int elemOpe = verificarOperacao(elem);
                        
                        if(elemOpe > operPre){
                            push(&operadores, elem);
                            
                        }else{
                            string res = calcular(&operadores, &numeros);
                            push(&numeros, res);
                            push(&operadores, elem);
                        }
                    }
                }else{
                    push(&numeros, elem); 
                }
            }

            while(!estaVaziaPilha(&operadores)){
                string res = calcular(&operadores, &numeros);
                push(&numeros, res);
            }

            cout << "\n\nPILHA NUMEROS: ";
            exibirPilha(&numeros);
        }
    } 
    return 0;
}