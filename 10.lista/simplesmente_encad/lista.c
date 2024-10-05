#include <stdio.h>
#include <stdlib.h>

// estrutura do no
typedef struct nodeitem {
    int info; // informacao do no
    struct nodeitem *next; // ponteiro para o proximo no
} node;

// estrutura da lista encadeada
typedef struct {
    node *first; // ponteiro para o primeiro no da lista
} linkedList;

// funcoes
linkedList *newList(); // criar uma nova lista
node *newNode(int value); // criar um novo no
void addItem(linkedList *l, int value, int pos); // adicionar um item na lista
int isEmpty(linkedList *l); // verifica se a lista esta vazia
int listLenght(linkedList *l); // retornar o tamanho da lista
void showList(linkedList *l); // mostrar a lista

int indexOf(linkedList *l, int value); // retorna a posicao a partir do um valor de um no
node *getNode(linkedList *l, int pos); // retorna um no a partir da posicao
void delByPos(linkedList *l, int pos); // remove um no a partir da posicao
void delByValue(linkedList *l, int value); // remove um no a partir do valor de um no

int main() {
    linkedList *l = newList(); // criar a lista

    // inserir elementos
    addItem(l, 1, 1);
    addItem(l, 2, 2);
    addItem(l, 3, 3);
    addItem(l, 5, 4);
    addItem(l, 7, 5);
    addItem(l, 8, 6);
    addItem(l, 9, 7);
    addItem(l, 10, 8);
    addItem(l, 12, 9);
    addItem(l, 14, 10);
    addItem(l, 1, 5);
    printf("\nLista apos insercoes: ");
    showList(l);

    // remover elemento por posicao
    delByPos(l, 4); // remover o quarto no
    printf("\nLista apos remover elemento na posicao 4: ");
    showList(l);

    // inserir em uma posicao intermediaria (5)
    addItem(l, 6, 5); // inserir o valor 6 na posição 5
    printf("\nLista apos inserir valor 6 na posicao 5: ");
    showList(l);

    // remover elemento por valor
    delByValue(l, 1); // remover todos os nós com valor 1
    printf("\nLista apos remover todos os elementos com valor 1: ");
    showList(l);

    // verificar a posicao de um valor
    int pos = indexOf(l, 7); // verificar a posicao do valor 7
    if (pos != -1) {
        printf("\nValor 7 encontrado na posicao: %d\n", pos);
    } else {
        printf("\nValor 7 nao encontrado!\n");
    }

    // verificar o tamanho da lista
    printf("\nTamanho atual da lista: %d\n", listLenght(l));
}

// criar uma nova lista
linkedList *newList(){
    linkedList *l = (linkedList *)malloc(sizeof(linkedList)); // aloca espaco na memoria para a lista
    l->first = NULL; // o primeiro no da lista recebe NULO, a lista acabou de ser criada
    return l; // retorna l
}

// criar um novo no
node *newNode(int value){
    node *n = (node *)malloc(sizeof(node)); // alocar espaco na memoria para o no
    n->info = value; // o no recebe o valor
    n->next = NULL; // o proximo no eh NULO
    return n; // retorna o no
}

// adicionar um item na lista
void addItem(linkedList *l, int value, int pos){
    // int i;
    node *n, *aux;
    if (pos < 1 || pos > listLenght(l)+1 ){ // verifica se a posicao eh valida na lista
        return; // para a funcao
    }
    n = newNode(value); // cria o no para ser inserido
    if (pos == 1){ // primeira posicao
        n->next = l->first; // o novo no passa a apontar para o primeiro no da lista
        l->first = n; // o novo no passa a ser o primeiro da lista
    } else { // demais posicoes
        aux = getNode(l, pos-1); // utiliza a funcao de retornar um no para encontrar o no anterior da posicao
        /*aux = l->first; // aux recebe a cabeca da lista
        for (i = 1; i < pos-1; i++){ // percorrer a lista ate o no anterior da posicao
            aux = aux->next; // aux recebe o proximo no
        } */
        n->next = aux->next; // o proximo no a n, recebe o proximo no a aux
        aux->next = n; // o proximo no a aux, recebe n
    }
}

// verifica se a lista esta vazia
int isEmpty(linkedList *l){
    return l->first == NULL; // se o primeiro no da lista esta NULO, a lista esta vazia
}

// retornar o tamanho da lista
int listLenght(linkedList *l){
    int size = 0;
    node *n;
    n = l->first; // n recebe o primeiro da lista
    while (n != NULL){ // enquanto n for diferente de NULO
        size++; // mais uma posicao
        n = n->next; // n passa para o proximo no
    }
    return size; // retorna o tamanho
}

// mostrar a lista
void showList(linkedList *l){
    node *n;
    n = l->first; // n recebe o primeiro da lista
    if (isEmpty(l)){ // verifica se a lista esta vazia
        printf("Vazio!");
    } else {
        while (n != NULL){ // enquanto n for diferente de NULO
            printf("[%d]", n->info); // printa a informacao do no
            n = n->next; // n passa para o proximo no
        }
    }
    printf("\n"); // quebra a linha
}

// retorna a posicao a partir do um valor de um no
int indexOf(linkedList *l, int value){
    int pos = 1;
    node *n;
    n = l->first; // n recebe o primeiro da lista
    while (n != NULL){ // enquanto n for diferente de NULO
        if (n->info == value){ // se a informacao do no, for igual ao valor
            return pos; // retorna a posicao
        } // se nao
        pos++; // aumenta a posicao
        n = n->next; // n passa para o proximo no
    }
    return -1; // se nao encontrar o valor, retorna -1
}

// retorna um no a partir da posicao
node *getNode(linkedList *l, int pos){
    node *n;
    if (pos < 0 || pos > listLenght(l)){ // verifica se a posicao eh valida
        return NULL; // retorna NULO
    }
    n = l->first; // n recebe o primeiro da lista
    while (pos > 1){ // enquanto a posicao for maior que 1
        n = n->next; // n passa para o proximo no
        pos--; // posicao diminui
    }
    return n; // retorna n
}

// remove um no a partir da posicao
void delByPos(linkedList *l, int pos) {
    node *n, *aux;
    if (pos < 1 || pos > listLenght(l)) { // verifica se a posicao eh valida
        return; // retorna NULO
    }
    if (pos == 1) { // primeira posicao
        n = l->first; // o novo no passa a ser o primeiro no da lista
        l->first = n->next; // o primeiro passa a ser o proximo no
    } else {
        aux = getNode(l, pos-1); // obtem o n anterior a posicao
        if (aux == NULL || aux->next == NULL) { // verifica se aux ou o proximo no sao NULOS
            return; // para a funcao, o no nao foi encontrado
        }
        n = aux->next; // n recebe o proximo no a aux
        aux->next = n->next; // o proximo no de aux, recebe o proximo no de n
    }
    free(n); // libera o no da memoria
}


// remove um no a partir do valor de um no
void delByValue(linkedList *l, int value){
    int pos = indexOf(l, value); // encontra a posicao do no
    while (pos > 0) { // enquanto a posicao for maior que 0
        delByPos(l, pos); // remove o no pela posicao
        pos = indexOf(l, value); // busca novamente por outro no com o mesmo valor
    }
}