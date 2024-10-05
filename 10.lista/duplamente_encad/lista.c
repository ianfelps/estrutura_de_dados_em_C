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
    node *head; // primeiro no da lista
    node *tail; // ultimo no da lista
} dlinkedList;

//funcoes
dlinkedList *newList(); // funcao para criar uma nova lista
node *newNode(int value); // funcao para criar um novo no
void addNode(dlinkedList *l, int value, int pos); // funcao para adicionar um no na lista
node *getNode(dlinkedList *l, int pos); // retorna um no a partir da posicao
int isEmpty(dlinkedList *l); // verifica se a lista esta vazia
void showList(dlinkedList *l, int inv); // mostrar a lista
int listLenght(dlinkedList *l); // retornar o tamanho da lista

int indexOf(dlinkedList *l, int value); // retorna a posicao a partir do um valor de um no
void delByPos(dlinkedList *l, int pos); // remove um no a partir da posicao
void delByValue(dlinkedList *l, int value); // remove um no a partir do valor de um no

int main(){
    
    dlinkedList *l = newList(); // criar lista

    // inserir elementos
    addNode(l, 1, 1);
    addNode(l, 2, 2);
    addNode(l, 3, 3);
    addNode(l, 5, 4);
    addNode(l, 7, 5);
    addNode(l, 8, 6);
    addNode(l, 9, 7);
    addNode(l, 10, 8);
    addNode(l, 12, 9);
    addNode(l, 14, 10);
    addNode(l, 1, 5);

    // remover elemento por posicao
    delByPos(l, 4); // remover o quarto no
    printf("\nLista apos remover elemento na posicao 4: ");
    showList(l, 0);

    // inserir em uma posicao intermediaria (5)
    addNode(l, 6, 5); // inserir o valor 6 na posição 5
    printf("\nLista apos inserir valor 6 na posicao 5: ");
    showList(l, 0);

    // remover elemento por valor
    delByValue(l, 1); // remover todos os nós com valor 1
    printf("\nLista apos remover todos os elementos com valor 1: ");
    showList(l, 0);

    // verificar a posicao de um valor
    int pos = indexOf(l, 7); // verificar a posicao do valor 7
    if (pos != -1) {
        printf("\nValor 7 encontrado na posicao: %d\n", pos);
    } else {
        printf("\nValor 7 nao encontrado!\n");
    }

    // verificar o tamanho da lista
    printf("\nTamanho atual da lista: %d\n", listLenght(l));

    // lista normal e invertida
    printf("\nLista normal: ");
    showList(l, 0);
    printf("\nLista invertida: ");
    showList(l, 1);

}

// funcao para criar uma nova lista
dlinkedList *newList(){
    dlinkedList *l = (dlinkedList *)malloc(sizeof(dlinkedList)); // alocar espaco na memoria para a lista
    l->head = NULL; // o primeiro e o ultimo elemento sao NULOS, a lista acabou de ser criada
    l->tail = NULL;
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

// funcao para adicionar um no na lista
void addNode(dlinkedList *l, int value, int pos){
    node *n, *aux;
    if (pos < 0 || pos > listLenght(l)+1){ // verifica se a posicao eh valida
        return; // para a funcao
    }
    n = newNode(value); // cria um novo no
    if (isEmpty(l)){ // se a lista estiver vazia
        l->head = n; // o primeiro e o ultimo no serao o no n
        l->tail = n;
    } else if (pos == 1){ // inserir no inicio
        n->next = l->head; // o novo no passa a apontar (proximo) para o primeiro no
        l->head->prev = n; // o primeiro no passa a apontar (anterior) para o novo no
        l->head = n; // o novo no passa a ser o primeiro no
    } else if (pos == listLenght(l)+1){ // inserir no final
        n->prev = l->tail; // o novo no passa a apontar (anterior) para o ultimo no
        l->tail->next = n; // o ultimo no passa a apontar (proximo) para o novo no
        l->tail = n; // o novo no passa a ser o ultimo no
    } else { // inserir nas outras posicoes
        aux = getNode(l, pos-1); // aux recebe o elemento da posicao anterior
        n->prev = aux; // o no anterior a n eh aux
        n->next = aux->next; // o proximo no a n eh o proximo no a aux
        aux->next->prev = n; // o no anterior ao proximo no eh n
        aux->next = n; // o proximo no a aux eh n
    }
}

// retorna um no a partir da posicao
node *getNode(dlinkedList *l, int pos){
    node *n;
    if (pos < 0 || pos > listLenght(l)){ // verifica se a posicao eh valida
        return NULL; // retorna NULO
    }
    n = l->head; // n recebe o primeiro da lista
    while (pos > 1){ // enquanto a posicao for maior que 1
        n = n->next; // n passa para o proximo no
        pos--; // posicao diminui
    }
    return n; // retorna n
}

// verifica se a lista esta vazia
int isEmpty(dlinkedList *l){
    return l->head == NULL; // se a lista nao tem o primeiro elemento, a lista esta vazia
}

// mostrar a lista
void showList(dlinkedList *l, int inv){
    node *n;
    if (isEmpty(l)){ // verifica se a lista esta vazia
        printf("Vazio!");
    } else {
        if (inv == 0){ // se inv for igual a 0, mostrar a lista em ordem da esquerda para a direita
            n = l->head; // n recebe o primeiro da lista
            while (n != NULL){ // enquanto n for diferente de NULO
                printf("[%d]", n->info); // printa a informacao do no
                n = n->next; // n passa para o proximo no
            }
        } else { // se inv for diferente de 0, mostrar a lista invertida, da direita para a esquerda
            n = l->tail; // n recebe o ultimo da lista
            while (n != NULL){ // enquanto n for diferente de NULO
                printf("[%d]", n->info); // printa a informacao do no
                n = n->prev; // n passa para o no anterior
            }
        }
    }
    printf("\n"); // quebra a linha
}

// retornar o tamanho da lista
int listLenght(dlinkedList *l){
    int size = 0;
    node *n;
    n = l->head; // n recebe o primeiro da lista
    while (n != NULL){ // enquanto n for diferente de NULO
        size++; // mais uma posicao
        n = n->next; // n passa para o proximo no
    }
    return size; // retorna o tamanho
}

// retorna a posicao a partir do um valor de um no
int indexOf(dlinkedList *l, int value){
    int pos = 1;
    node *n;
    n = l->head; // n recebe o primeiro da lista
    while (n != NULL){ // enquanto n for diferente de NULO
        if (n->info == value){ // se a info do no for igual ao valor
            return pos; // retorna a posicao do no
        } // se nao
        n = n->next; // n passa para o proximo no
        pos++; // aumenta a posicao
    }
    return -1; // se nao encontrar, retorna -1
}

// remove um no a partir da posicao
void delByPos(dlinkedList *l, int pos){
    node *n, *aux;
    if (pos < 0 || pos > listLenght(l)+1){ // verifica se a posicao eh valida
        return; // para a funcao
    }
    if (pos == 1){ // remover no inicio
        n = l->head; // o novo no passa a ser o primeiro no
        l->head = n->next; // o primeiro no, passa a ser a ser o proximo no do novo no
        if (l->head != NULL){ // se o primeiro no for nulo
            l->head->prev = NULL; // o no anterior ao primeiro no passa a ser NULO
        } else { // se nao
            l->tail = NULL; // o ultimo no passa a ser NULO
        }
    } else if (pos == listLenght(l)+1){ // remover no final
        n = l->tail; // o novo no passa a ser o ultimo no
        l->tail = n->prev; // o ultimo no, passa a ser a ser o no anterior do novo no
        l->tail->next = NULL; // o proximo no ao ultimo no passa a ser NULO
    } else { // remover nas outras posicoes
        aux = getNode(l, pos-1); // aux recebe o no anterior a posicao
        if (aux == NULL){ // se o aux for NULO
            return; // para a funcao
        }
        n = aux->next; // n passa a ser o proximo no a aux
        if (n == NULL){ // se o n for NULO
            return; // para a funcao
        }
        aux->next = n->next; // o proximo no a aux recebe o proximo no a n
        if (n->next != NULL){ // se o proximo no a n nao for NULO
            n->next->prev = aux; // o proximo no ao no anterior a n passara a ser aux
        }
        free(n); // libera o n da memoria
    }
}

// remove um no a partir do valor de um no
void delByValue(dlinkedList *l, int value){
    int pos = indexOf(l, value); // encontra a posicao do no
    while (pos > 0) { // enquanto a posicao for maior que 0
        delByPos(l, pos); // remove o no pela posicao
        pos = indexOf(l, value); // busca novamente por outro no com o mesmo valor
    }
}
