#include <stdio.h>
#include <stdlib.h>

// estutura do no
typedef struct NodeItem {
    int info; // informacao do no
    struct NodeItem *next; // ponteiro para o proximo no
} node;

// estrutura da fila
typedef struct {
    node *head, *tail; // no da "cabeca" e no da "cauda" da fila
} queue;

// funcoes
queue *newQueue(); // funcao para criar uma nova fila
node *newNode(int info); // funcao para criar um novo no
void enqueue(queue *q, int value); // funcao para inserir um valor na fila (no final)
int dequeue(queue *q); // funcao para remover um valor da fila (no inicio)
int isEmpty(queue *q); // funcao para verificar se a fila esta vazia
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
    q->head = NULL; // a cabeca e a cauda da fila comecam como NULO
    q->tail = NULL;
    return q; // retorna q
}

// funcao para criar um novo no
node *newNode(int info){
    node *n = (node *)malloc(sizeof(node)); // aloca o espaco na memoria para o no
    n->info = info; // atribui a info ao no
    n->next = NULL; // ao criar um no, ele aponta pra ninguem
    return n; // retorna n
}

// funcao para inserir um valor na fila (no final)
void enqueue(queue *q, int value){
    node *n = newNode(value); // cria um novo no
    if (isEmpty(q)){ // se a fila esta vazia
        q->head = n; // a fila esta vazia, logo a cabeca e a cauda da fila recebem o mesmo valor
        q->tail = n;
    } else {
        q->tail->next = n; // o proximo valor depois da cauda passa a ser n
        q->tail = n; // n passa a ser a nova cauda
    }
}

// funcao para remover um valor da fila (no inicio)
int dequeue(queue *q){
    node *n;
    int aux;
    if (isEmpty(q)){ // verifica se a fila esta cheia
        printf("Nao eh possivel remover um valor, a fila esta vazia!");
        return -1;
    }
    n = q->head; // guarda o no que sera removido
    aux = n->info; // aux recebe o valor que sera removido
    q->head = n->next; // a cabeca da fila passa a ser o proximo valor da antiga cabeca
    if (q->head == NULL){ // se a cabeca passar a ser NULO
        q->tail = NULL; // a cauda tambem passara a ser NULO
    }
    free(n); // libera o n da memoria
    return aux; // retorna o valor que foi removido
}

// funcao para verificar se a fila esta vazia
int isEmpty(queue *q){
    return q->head == NULL; // se a cabeca da fila for igual a NULO, a fila esta vazia
}

// funcao para imprimir a fila
void showQueue(queue *q){
    node *n;
    if (isEmpty(q)){ // verifica se a fila esta vazia
        printf("Vazio!");
    }
    n = q->head; // no n recebe o no cabeca da fila
    while (n != NULL){ // percorre a fila ate o no n ser nulo (nao ter proximo)
        printf("[%d]", n->info); // printa a info do no n
        n = n->next; // n passa a receber o novo valor
    }
    printf("\n");
}