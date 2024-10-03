#include <stdio.h>
#include <stdlib.h>

#define N 10 // definir constante N

// estrutura da fila
typedef struct {
    int head, tail; // valor da "cabeca" e da "cauda" da fila
    int data[N]; // vetor com os valores da fila
} queue;

// funcoes
queue *newQueue(); // funcao para criar uma nova fila
void enqueue(queue *q, int value); // funcao para inserir um valor na fila (no final)
int dequeue(queue *q); // funcao para remover um valor da fila (no inicio)
int isEmpty(queue *q); // funcao para verificar se a fila esta vazia
int isFull(queue *q); // funcao para verificar se a fila esta cheia
void showQueue(queue *q); // funcao para imprimir a fila

int main() {

    queue *fila = newQueue(); // cria a fila

    printf("\nFila: ");
    showQueue(fila); // printa a fila

    // adicionar valores na fila
    enqueue(fila, 7);
    enqueue(fila, 3);
    enqueue(fila, 8);
    enqueue(fila, 2);
    enqueue(fila, 10);
    enqueue(fila, 11);
    printf("\nInserindo valores...\n");

    printf("\nFila: ");
    showQueue(fila); // printa a fila

    // remover valores da fila
    printf("\nValor removido: %d\n", dequeue(fila));
    printf("Valor removido: %d\n", dequeue(fila));

    printf("\nFila: ");
    showQueue(fila); // printa a fila

    // adicionar valores na fila
    enqueue(fila, 4);
    enqueue(fila, 8);
    enqueue(fila, 9);
    enqueue(fila, 12);
    enqueue(fila, 23);
    enqueue(fila, 71);
    printf("\nInserindo valores...\n");

    printf("\nFila: ");
    showQueue(fila); // printa a fila

    // remover valores da fila
    printf("\nValor removido: %d\n", dequeue(fila));
    printf("Valor removido: %d\n", dequeue(fila));

    printf("\nFila: ");
    showQueue(fila); // printa a fila

}

// funcao para criar uma nova fila
queue *newQueue(){
    queue *q = (queue *)malloc(sizeof(queue)); // aloca o espaco na memoria para a fila
    q->head = 0; // a cabeca e a cauda da fila comecam como 0
    q->tail = 0;
    return q; // retorna q
}

// funcao para inserir um valor na fila (no final)
void enqueue(queue *q, int value){
    if (isFull(q)){ // verifica se a fila esta cheia
        printf("Nao eh possivel inserir um novo valor, a fila esta cheia!");
        return;
    }
    q->data[q->tail % N] = value; // a cauda da fila recebe o valor
    q->tail++; // a cauda passa a ser o proximo indice
}

// funcao para remover um valor da fila (no inicio)
int dequeue(queue *q){
    int aux;
    if (isEmpty(q)){ // verifica se a fila esta cheia
        printf("Nao eh possivel remover um valor, a fila esta vazia!");
        return -1;
    }
    aux = q->data[q->head % N]; // o valor da cabeca da fila (que foi "removido")
    q->head++; // a cabeca passa a ser o proximo valor
    return aux; // retorna o valor
}

// funcao para verificar se a fila esta vazia
int isEmpty(queue *q){
    return q->head == q->tail; // se o valor da cabeca e da cauda da fila forem iguais, a fila esta vazia
}

// funcao para verificar se a fila esta cheia
int isFull(queue *q){
    // return q->tail == N; // se a cauda da fila for do mesmo tamanho do vetor, a fila esta cheia
    return q->tail - q->head == N; // se a a cauda da fila, menos a cabeca da fila, for igual ao tamanho do vetor, a fila esta cheia
}

// funcao para imprimir a fila
void showQueue(queue *q){
    int i;
    if (isEmpty(q)){ // verifica se a fila esta vazia
        printf("Vazio!");
    }
    for (i = q->head; i < q->tail; i++){ // percorre a fila da cabeca ate a cauda
        printf("[%d]", q->data[i % N]); // printa os valores no indice "i"
    }
    printf("\n");
}

// utilizando "% N" nas posicoes dos elementos, garante que a posicao sempre esteja entre 0 e N-1, fazendo com que a fila seja circular