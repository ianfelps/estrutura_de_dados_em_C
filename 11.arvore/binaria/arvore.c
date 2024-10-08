#include <stdio.h>
#include <stdlib.h>

// estrutura dos nos
typedef struct nodetype {
    int info; // informacao do no
    struct nodetype *father; // ponteiro para o no pai
    struct nodetype *left; // ponteiro para o no filho esquerdo
    struct nodetype *right; // ponteiro para o no filho direito
} node;

// funcoes
node *makeTree(int val); // funcao para criar a arvore

int info(node *n); // funcao para retornar a info de um no
node *left(node *n); // funcao para retornar o no filho esquerdo de um no
node *right(node *n); // funcao para retornar o no filho direito de um no
node *father(node *n); // funcao para retornar o no pai de um no
node *brother(node *n); // funcao para retornar o no irmao de um no

int isLeft(node *n); // funcao para verificar esse no eh um filho esquerdo
int isRight(node *n); // funcao para verificar esse no eh um filho direito

node *addLeft(node *tree, int val); // funcao para adicionar um no filho esquerdo a um no
node *setLeft(node *tree, node *n); // funcao para setar um no filho esquerdo a um no
node *addRight(node *tree, int val); // funcao para adicionar um no filho direito a um no
node *setRight(node *tree, node *n); // funcao para setar um no filho direito a um no
void freeTree(node *n); // funcao para liberar todos os nos a partir de um da memoria

void preOrder(node *n); // funcao para printar os elementos da arvore em pre ordem
void inOrder(node *n); // funcao para printar os elementos da arvore em ordem
void postOrder(node *n); // funcao para printar os elementos da arvore em pos ordem

int isLeaf(node *n); // funcao para verificar se um no eh um no folha
node *root(node *n); // funcao para retornar a raiz da arvore

int level(node *n); // funcao para retornar o nivel de um no
int depth(node *n); // funcao para retornar a profundidade de um no
int treeDepth(node *tree); // funcao para retornar a profundidade de uma arvore
int maxOf(int a, int b); // funcao para retornar o maior valor entre a e b

int isStrict(node *tree); // funcao para verificar se a arvore eh estrita
int isComplete(node *tree); // funcao para verificar se a arvore eh completa

int length(node *tree); // funcao para retornar a quantidade de nos da arvore
int bigger(node *tree); // funcao para retornar o maior valor entre a familia dos nos
int sum(node *tree); // funcao para somar os valores da arvore

void printTree(node *tree, int space); // funcao para printar um "desenho" da arvore binaria

int main(){

    node *tree = makeTree(14); // cria a arvore binaria

    // adiciona os filhos esquerdos e direitos
    addLeft(addLeft(tree, 4), 3);
    addRight(left(tree), 10);
    addLeft(addRight(tree, 22), 18);
    addRight(right(tree), 25);
    addLeft(left(left(tree)), 1);
    
    // printar a arvore em orderns diferentes
    printf("\nPre-ordem: ");
    preOrder(tree);
    printf("\nEm ordem: ");
    inOrder(tree);
    printf("\nPos-ordem: ");
    postOrder(tree);

    // infos da arvore
    printf("\nA raiz da arvore eh: %d\n", info(root(tree)));
    printf("A profundidade da arvore eh: %d\n", treeDepth(tree));
    printf("O comprimento da arvore (numero de nos) eh: %d\n", length(tree));
    printf("A soma dos valores dos nos na arvore eh: %d\n", sum(tree));
    printf("O maior valor da arvore eh: %d\n", bigger(tree));

    // verificacoes de estrutura
    printf("A arvore eh estrita? %s\n", isStrict(tree) ? "Sim" : "Nao");
    printf("A arvore eh completa? %s\n", isComplete(tree) ? "Sim" : "Nao");

    printf("Desenho da arvore binaria:\n");
    printTree(tree, 0);

}

// funcao para criar a arvore
node *makeTree(int val){
    node *n = (node *)malloc(sizeof(node)); // aloca o espaco na memoria para o no
    n->info = val; // atribui o val a info do no
    n->father = NULL; // no pai eh NULO, o no acabou de ser criado
    n->left = NULL; // no filho esquerdo eh NULO, o no acabou de ser criado
    n->right = NULL; // no filho direito eh NULO, o no acabou de ser criado
    return n; // retorna n
}

// funcao para retornar a info de um no
int info(node *n){
    return n->info; // retorna a info do no
}

// funcao para retornar o no filho esquerdo de um no
node *left(node *n){
    return n->left; // retorna o filho esquerdo de um no
}

// funcao para retornar o no filho direito de um no
node *right(node *n){
    return n->right; // retorna o filho direito de um no
}

// funcao para retornar o no pai de um no
node *father(node *n){
    return n->father; // retorna o no pai de um no
}

// funcao para retornar o no irmao de um no
node *brother(node *n){
    if (father(n) == NULL) return NULL; // verifica se esse no tem um pai
    if (isLeft(n)){ // se n for um filho esquerdo
        return right(father(n)); // retorna o filho direito do seu pai
    } else { // // se n nao for um filho esquerdo, n eh um filho direito
        return left(father(n)); // retorna o filho esquerdo do seu pai
    }
}

// funcao para verificar esse no eh um filho esquerdo
int isLeft(node *n){
    if (father(n) == NULL) return 0; // verifica se esse no tem um pai
    return n == left(father(n)); // se n for igual ao filho do pai de n, n eh um no filho esquerdo
}

// funcao para verificar esse no eh um filho direito
int isRight(node *n){
    if (father(n) == NULL) return 0; // verifica se esse no tem um pai
    return n == right(father(n)); // se n for igual ao filho do pai de n, n eh um no filho direito
}

// funcao para adicionar um no filho esquerdo a um no
node *addLeft(node *tree, int val){
    return setLeft(tree, makeTree(val)); // utiliza outras duas funcoes para criar e setar o no filho esquerdo
}

// funcao para setar um no filho esquerdo a um no
node *setLeft(node *tree, node *n){
    if (left(tree) == NULL){ // verifica se tem espaço para um no filho esquerdo
        tree->left = n; // o no filho esquerdo de tree, recebe n
        n->father = tree; // o no pai de n, recebe tree
        return n; // retorna n
    } else { // se ja houver um no filho esquerdo
        return NULL; // retorna nulo
    }
}

// funcao para adicionar um no filho direito a um no
node *addRight(node *tree, int val){
    return setRight(tree, makeTree(val)); // utiliza outras duas funcoes para criar e setar o no filho direito
}

// funcao para setar um no filho direito a um no
node *setRight(node *tree, node *n){
    if (right(tree) == NULL){ // verifica se tem espaço para um no filho direito
        tree->right = n; // o no filho direito de tree, recebe n
        n->father = tree; // o no pai de n, recebe tree
        return n; // retorna n
    } else { // se ja houver um no filho direito
        return NULL; // retorna nulo
    }
}

// funcao para liberar todos os nos a partir de um da memoria
void freeTree(node *n){
    node *aux;
    if (n != NULL){ // verifica se n eh diferente de NULO
        aux = father(n); // aux recebe o pai de n
        if (aux != NULL){ // verifica se o pai de n eh diferente de NULO
            if (isLeft(n)){ // verifica se n eh um filho esquerdo
                aux->left = NULL; // o filho esquerdo do pai de n passa a receber nulo
            } else { // se n nao eh um filho esquerdo, n eh um filho direito
                aux->right = NULL; // o filho direito do pai de n passa a receber nulo
            }
        }
        freeTree(left(n)); // primeiro libera os respectivos filhos esquerdos de n
        freeTree(right(n)); // primeiro libera os respectivos filhos direitos de n
        free(n); // e depois, libera o n
    }
}

// funcao para printar os elementos da arvore em pre ordem
void preOrder(node *n){
    if (n != NULL){ // verifica se n eh diferente de NULO
        printf("[%d]", info(n)); // primiero printa a info de n
        preOrder(left(n)); // depois a info dos nos filhos esquerdos
        preOrder(right(n)); // e por ultimo, a info dos nos filhos direitos
    }
}

// funcao para printar os elementos da arvore em ordem
void inOrder(node *n){
    if (n != NULL){ // verifica se n eh diferente de NULO
        inOrder(left(n)); // primeiro printa a info dos nos filhos esquerdo
        printf("[%d]", info(n)); // depois a info de n
        inOrder(right(n)); // e por ultimo, a info dos nos filhos direitos
    }
}

// funcao para printar os elementos da arvore em pos ordem
void postOrder(node *n){
    if (n != NULL){ // verifica se n eh diferente de NULO
        postOrder(left(n)); // primeiro printa a info dos nos filhos esquerdo
        postOrder(right(n)); // depois a info dos nos filhos direitos
        printf("[%d]", info(n)); // e por ultimo, a info de n
    }
}

// funcao para verificar se um no eh um no folha
int isLeaf(node *n){
    return left(n) == NULL && right(n) == NULL; // verifica se o filho esquerdo e o filho direito do no sao NULOS, se forem, o no eh um no folha
}

// funcao para retornar a raiz da arvore
node *root(node *n){
    if (father(n) == NULL){ // verifica se o no possui um no pai
        return n; // se nao houver um no pai, entao n eh a raiz
    } // se houver um pai
    return root(father(n)); // chama a funcao com recursividade para o pai de n
}

// funcao para retornar o nivel de um no
int level(node *n){
    if (father(n) == NULL){ // verifica se o no possui um no pai
        return 0; // se o no nao tem pai, ele eh a raiz, entao o nivel eh 0
    } else { // se nao
        return level(father(n)) + 1; // chama a funcao novamente, passando para o pai de n, e adicionando + 1
    }
}

// funcao para retornar a profundidade de um no
int depth(node *n){
    if (n == NULL || isLeaf(n)){ // verifica se n eh nulo, ou se n eh uma folha
        return 0; // se sim , a profundidade de n eh 0
    } // se nao
    return maxOf(depth(left(n)), depth(right(n))) + 1; // pega o maior entre os filhos esquerdos e direitos e chama novamente a funcao, adicionando + 1
}

// funcao para retornar a profundidade de uma arvore
int treeDepth(node *tree){
    return depth(root(tree)); // retorna a profundidade a partir da raiz
}

// funcao para retornar o maior valor entre a e b
int maxOf(int a, int b){
    return a > b ? a : b; // verifica quem eh maior e retorna o mesmo
}

// funcao para verificar se a arvore eh estrita
int isStrict(node *tree){ // arvore estrita eh uma arvore onde os nos possuem 2 ou 0 filhos
    if (tree == NULL){ // se o no for NULO
        return 0; // retorna 0
    } else if (isLeaf(tree)){ // se o no for uma folha
        return 1; // retorna 1
    }
    return isStrict(left(tree)) && isStrict(right(tree)); // ve se os proximos nos tambem seguem a regra
}

// funcao para verificar se a arvore eh completa
int isComplete(node *tree){ // arvore completa eh onde todos os nos folhas estao no mesmo nivel
    if (tree == NULL){ // se o no for NULO
        return 0; // retorna 0
    } else if (isLeaf(tree)){ // se o no for um no folha
        return level(tree) == treeDepth(tree); // verifica se o nivel do no eh o mesmo da profundidade da arvore
    }
    return isComplete(left(tree)) && isComplete(right(tree)); // ve se os proximos nos tambem seguem a regra
}

// funcao para retornar a quantidade de nos da arvore
int length(node *tree){
    if (tree == NULL){ // se o no for NULO
        return 0; // retorna 0
    }
    return 1 + length(left(tree)) + length(right(tree)); // cotinua a contagem nos nos filhos de tree
}

// funcao para retornar o maior valor entre a familia dos nos
int bigger(node *tree){
    int m;
    if (tree == NULL){ // se o no for NULO
        return 0; // retorna 0
    }
    m = maxOf(bigger(left(tree)), bigger(right(tree))); // encontra o maior valor entre os valores da esquerda e da direita
    return maxOf(info(tree), m); // retorna o maior entre tree e o maior dos filhos
}

// funcao para somar os valores da arvore
int sum(node *tree){
    if (tree == NULL){ // se o no for NULO
        return 0; // retorna 0
    }
    return info(tree) + sum(left(tree)) + sum(right(tree)); // soma o no com toda a subarvore esquerda e direita
}

// funcao para printar um "desenho" da arvore binaria
void printTree(node *tree, int space) {
    int indent = 5; // espacos entre os niveis
    if (tree == NULL) { // se o no for NULO
        return; // para a funcao
    }
    space += indent; // aumenta o espaco para o proximo nivel

    // primeiro, imprime a subarvore da direita
    printTree(tree->right, space);

    // imprime o valor do no atual, com a indentação correta
    printf("\n");
    for (int i = indent; i < space; i++) { // for para imprimir os espacos
        printf(" ");
    }
    printf("%d\n", tree->info); // printa o no atual

    // depois, imprime a subarvore da esquerda
    printTree(tree->left, space);
}