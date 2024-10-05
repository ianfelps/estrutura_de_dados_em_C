#include <stdio.h>
#include <stdlib.h>

// estrutura do no
typedef struct nodeitem {
    int info; // informacao do no
    struct nodeitem *next; // ponteiro para o proximo no
    struct nodeitem *prev; // ponteiro para o no anterior
} node;

// estrutura da lista duplamente encadeada
typedef struct {
    node *current; // no atual da lista
} clinkedList;

clinkedList *newList(); // funcao para criar uma nova lista
node *newNode(int value); // funcao para criar um novo no
int isEmpty(clinkedList *l); // funcao para verificar se a lista esta vazia
int listLenght(clinkedList *l); // funcao para verificar o tamanho da lista

node *currentNode(clinkedList *l); // funcao para retornar o no atual
node *nextNode(clinkedList *l); // funcao para retornar o proximo no
node *prevNode(clinkedList *l); // funcao para retornar o no anterior

node *addNode(clinkedList *l, int value); // funcao para adicionar um novo no na posicao atual
void delNode(clinkedList *l, node *n); // funcao para remover um no na lista
node *findNode(clinkedList *l, int value); // funcao para encontrar um no na lista

void showList(clinkedList *l, int inv); // funcao para imprimir a lista

int main(){

    clinkedList *l = newList(); // cria uma nova lista

    // adiciona novos nos
    addNode(l, 10);
    addNode(l, 20);
    addNode(l, 30);
    addNode(l, 40);
    addNode(l, 50);

    // imprimir lista
    printf("\nLista original: ");
    showList(l, 0); // lista na ordem normal

    // tamanho da lista
    printf("\nTamanho da lista original: %d\n", listLenght(l));

    // removendo um no
    node *n = findNode(l, 20);
    if (n != NULL) {
        printf("Removendo o no com valor 20...\n");
        delNode(l, n);
    }

    // imprimir lista apos remocao
    printf("\nLista apos remocao: ");
    showList(l, 0); // lista na ordem normal

    // tamanho da lista apos remocao
    printf("\nTamanho da lista apos remocao: %d\n", listLenght(l));

    // imprimir lista invertida
    printf("\nLista invertida: ");
    showList(l, 1); // lista invertida

}

// funcao para criar uma nova lista
clinkedList *newList(){
    clinkedList *l = (clinkedList *)malloc(sizeof(clinkedList)); // alocar espaco na memoria para a lista
    l->current = NULL; // o valor atual eh NULO, a lista acabou de ser criada
    return l; // retorna l
}

// funcao para criar um novo no
node *newNode(int value){
    node *n = (node *)malloc(sizeof(node)); // alocar espaco na memoria para o no
    n->info = value; // o no recebe o valor
    n->next = NULL; // o proximo no eh NULO
    n->prev = NULL; // o no anterior eh NULO
    return n; // retorna o no
}

// funcao para verificar se a lista esta vazia
int isEmpty(clinkedList *l){
    return l->current == NULL; // se o no atual da lista for NULO, a lista esta vazia
}

// funcao para verificar o tamanho da lista
int listLenght(clinkedList *l){
    int size;
    node *n;
    if (isEmpty(l)){ // verifica se a lista esta vazia
        return 0; // se estiver vazia, retorna 0
    }
    size = 1;
    n = l->current->next; // o no n passa a ser o proximo no ao no atual
    while (n != l->current){ // enquanto o no n for diferente do no atual
        n = n->next; // n passa para o proximo no
        size++; // aumenta o tamanho
    }
    return size; // retorna o tamanho
}

// funcao para retornar o no atual
node *currentNode(clinkedList *l){
    return l->current; // no atual
}

// funcao para passar para o proximo no
node *nextNode(clinkedList *l){
    return l->current->next; // proximo no ao no atual
}

// funcao para volar para o no anterior
node *prevNode(clinkedList *l){
    return l->current->prev; // no anterior ao no atual
}

// funcao para adicionar um novo no na posicao atual
node *addNode(clinkedList *l, int value){
    node *n;
    n = newNode(value); // cria um novo no com o valor
    if (!isEmpty(l)){ // se a lista nao estiver vazia
        n->prev = l->current->prev; // o elemento anterior ao no n, recebe o anterior ao elemento atual
        n->next = l->current; // o proximo elemento ao no n, recebe o elemento atual
        l->current->prev = n; // o elemento anterior ao elemento atual, recebe o no n
        n->prev->next = n; // o elemento anterior ao proximo elemento do no n, recebe o no n
    } else { // se a lista estiver vazia
        l->current = n; // o no atual passa a ser o no n
        n->next = n; // o proximo no tambem passa a ser o no n
        n->prev = n; // o no anterior tambem passa a ser o no n
    }
    return n; // retorna n
}

// funcao para remover um no na lista
void delNode(clinkedList *l, node *n){
    if (n->next == n){ // se o proximo elemento ao no n, for o proprio n
        l->current = NULL; // o no atual passa a ser NULO, e a lista esta vazia
    } else {
        l->current = n->prev; // o no atual passa a ser o no anterior ao no n
        l->current->next = n->next; // o proximo no ao no atual passa a ser o proximo no ao no n
        n->next->prev = l->current; // o no anterior ao proximo no do no n passa a ser o no atual
    }
    free(n); // libera o n da memoria
}

// funcao para encontrar um no na lista
node *findNode(clinkedList *l, int value){
    node *n;
    if (isEmpty(l)){ // se a lista estiver vazia
        return NULL; // retorna NULO
    }
    n = l->current->next; // n passa a ser o proximo no ao no atual
    while (n->info != value && n != l->current){ // enquanto a info do no no for diferente do valor e n for diferente do no atual
        n = n->next; // n passa para o proximo
    }
    if (n->info == value){ // se a info do no n for igual ao valor
        return n; // retorna o n
    } else { // se nao
        return NULL; // retorna NULO, o valor nao foi encontrado
    }
}

// funcao para imprimir a lista
void showList(clinkedList *l, int inv){
    node *n;
    if (isEmpty(l)){ // se a lista estiver vazia
        printf("Vazio!");
    } else {
        n = l->current; // o no n passa a ser o no atual
        do {
            printf("[%d<-%d->%d]", n->prev->info, n->info, n->next->info); // printa o valor do no anterior, do atual e do proximo
            if (inv){ // se inv for igual a 1
                n = n->prev; // n passa para o valor anterior
            } else {
                n = n->next; // n passa para o proximo valor
            }
        } while (n != l->current); // enquanto o no no for diferente do no atual
    }
    printf("\n"); // quebra a linha
}