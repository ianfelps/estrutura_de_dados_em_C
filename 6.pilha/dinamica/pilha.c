#include <stdio.h>
#include <stdlib.h>

// estrututa do no
typedef struct nodeitem {
    int info; // informacao do no
    struct nodeitem *next; // ponteiro para o proximo no
} node;

// estutura da pilha
typedef struct {
    node *top; // topo da pilha
} stack;

// metodos/operacoes
node *newNode(int info); // criar no
stack *newStack(); // criar pilha
void push(stack *s, int value); // adiciona um valor ao topo da pilha
int pop(stack *s); // remove e retorna o valor do topo da pilha
int top(stack *s); // retorna o valor do topo da pilha
int isEmpty(stack *s); // verifica se a pilha esta vazia, 1 ou 0

int main (){

    stack *p; // criar estrutura da pilha
    p = newStack(); // cria a pilha utilizando a funcao newStack()

    // adicionar valores na pilha
    push(p, 15);
    push(p, 7);
    push(p, 10);
    push(p, 1);
    push(p, 20);

    // verificar topo da pilha
    printf("\nTopo da pilha: %d", top(p));

    // remover valor do topo da pilha
    printf("\nValor removido: %d", pop(p));

    // verificar novo topo da pilha
    printf("\nNovo topo da pilha: %d", top(p));

    printf("\n\nStatus da Pilha: ");
    // verificacao se a pilha esta vazia ou cheia utilizando as funcoes
    if (isEmpty(p)){
        printf("\nA pilha esta vazia!");
    } else {
        printf("\nA pilha NAO esta vazia!");
    }

}

// criar no
node *newNode(int info){
    node *n = (node *)malloc(sizeof(node)); // aloca o espaco na memoria do tamanho da estutura do no
    n->info = info; // atribui a info ao no
    n->next = NULL; // ao criar um no, ele aponta pra ninguem
    return n; // retorna n
}

// criar pilha
stack *newStack(){
    stack *p = (stack *)malloc(sizeof(stack)); // aloca o espaco na memoria do tamanho da estutura da pilha
    p->top = NULL; // o topo da pilha recebe NULO, a pilha comeca vazia
    return p; // retorna p
}

// adiciona um valor ao topo da pilha
void push(stack *s, int value){
    node *n = newNode(value); // cria um novo no
    n->next = s->top; // o proximo de n sera o antigo topo
    s->top = n; // o topo recebe n, pois n passa a ser o novo topo
}

// remove e retorna o valor do topo da pilha
int pop(stack *s){
    node *n;
    int aux; 
    if (isEmpty(s)){ // verifica se a pilha esta vazia
        printf("Pilha vazia!"); // stack underflow, impossivel retirar o valor do topo se a pilha esta vazia
        return 0;
    }
    n = s->top; // armazena no que sera removido em n
    aux = n->info; // armazena o valor do topo da pilha que sera removido em aux
    s->top = n->next; // o topo passa a receber o proximo elemento do elemento que sera removido
    free(n); // libera o n da memoria
    return aux; // retoran o valor que foi removido
}

// retorna o valor do topo da pilha
int top(stack *s){
    if (isEmpty(s)){ // verifica se a pilha esta vazia
        printf("Pilha vazia!"); // stack underflow, impossivel verificar o valor do topo se a pilha esta vazia
        return 0;
    }
    return s->top->info; // retorna o valor do topo da pilha
}

// verifica se a pilha esta vazia, 1 ou 0
int isEmpty(stack *s){
    return s->top == NULL; // se o topo da pilha for igual a NULL, a pilha esta vazia, entao retorna 1
}