#include <stdio.h>
#include <stdlib.h>

#define N 5 // definir uma constante N = 5

// estutura da pilha
typedef struct {
    int top; // topo da pilha
    int data[N]; // vetor com os dados (inteiros) da pilha
} stack;

// metodos/operacoes
stack *newStack(); // criar pilha
void push(stack *s, int value); // adiciona um valor ao topo da pilha
int pop(stack *s); // remove e retorna o valor do topo da pilha
int top(stack *s); // retorna o valor do topo da pilha
int isEmpty(stack *s); // verifica se a pilha esta vazia, 1 ou 0
int isFull(stack *s); // verifica se a pilha esta cheia, 1 ou 0

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
    if (!isFull(p)){
        printf("\nA pilha NAO esta cheia!");
    } else {
        printf("\nA pilha esta cheia!");
    }
    
}

// criar pilha
stack *newStack(){
    stack *p = (stack *)malloc(sizeof(stack)); // aloca o espaco na memoria do tamanho da estutura da pilha
    p->top = 0; // o topo da pilha recebe 0, a pilha comeca vazia
    return p; // retorna p
}

// adiciona um valor ao topo da pilha
void push(stack *s, int value){
    if (isFull(s)){ // verifica se a pilha esta cheia
        printf("Pilha cheia!"); // stack overflow, impossivel inserir dados na pilha se ela esta cheia
    }
    s->data[s->top] = value; // data, na posicao do topo, recebe o valor
    s->top++; // aumenta o valor do topo
}

// remove e retorna o valor do topo da pilha
int pop(stack *s){
    if (isEmpty(s)){ // verifica se a pilha esta vazia
        printf("Pilha vazia!"); // stack underflow, impossivel retirar o valor do topo se a pilha esta vazia
        return 0;
    }
    s->top = s->top - 1; // remove 1 do topo
    return s->data[s->top]; // retorna o valor da pilha na posicao do topo - 1
}

// retorna o valor do topo da pilha
int top(stack *s){
    if (isEmpty(s)){ // verifica se a pilha esta vazia
        printf("Pilha vazia!"); // stack underflow, impossivel verificar o valor do topo se a pilha esta vazia
        return 0;
    }
    return s->data[s->top - 1]; // retorna o valor da pilha na posicao do topo - 1
}

// verifica se a pilha esta vazia, 1 ou 0
int isEmpty(stack *s){
    return s->top == 0; // se o topo da pilha for igual a 0, a pilha esta vazia, entao retorna 1
}

// verifica se a pilha esta cheia, 1 ou 0
int isFull(stack *s){
    return s->top == N; // se o topo da pilha for igual a N, a pilha esta cheia, entao retorna 1
}