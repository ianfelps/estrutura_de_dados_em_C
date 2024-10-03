#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // definir constante N

// funcoes
void preencher(int vet[], int max); // funcao para preencher um vetor com numeros aleatorios
void imprimir(int vet[]); // funcao para imprimir o vetor

void trocar(int *x, int *y); // funcao para fazer trocas dentro de um vetor
int partition(int vet[], int left, int right); // funcao para encontrar o pivo de um vetor
void quickSort(int vet[], int left, int right); // funcao de ordenacao quick sort

int buscaSeq(int vet[], int key); // funcao de busca sequencial
int buscaSeqOrd(int vet[], int key); // funcao de busca sequencial em um vetor ordenado

int buscaBin(int vet[], int key, int left, int right); // funcao de busca binaria

int main(){

    int vet[N]; // criar vetor do tamanho da constante N
    int pos; 

    srand(time(NULL)); // gerar os numeros aleatoriamente

    preencher(vet, 20); // preencher o vetor com numeros aleatorios
    quickSort(vet, 0, N-1); // ordenar o vetor utilizando o quick sort
    imprimir(vet); // imprimir o vetor

    pos = buscaBin(vet, 10, 0, N-1); // utiliza a busca binaria para o valor 10

    // verificacao do resultado da busca
    if (pos < 0){
        printf("Valor nao foi encontrado!\n");
    } else {
        printf("Valor encontrado na posicao %d!", pos+1);
    }
}

// funcao para preencher um vetor com numeros aleatorios
void preencher(int vet[], int max){
    int i;
    for (i = 0; i < N; i++){ // percorre o vetor e preenche com um valor aleatorio
        vet[i] = (rand() % max) + 1;
    }
}

// funcao para imprimir o vetor
void imprimir(int vet[]){
    int i;
    for (i = 0; i < N; i++){ // percorre o vetor e printa o valor
        printf("[%d]", vet[i]);
    }
    printf("\n"); // quebra a linha
}

// funcao para fazer trocas dentro de um vetor
void trocar(int *x, int *y){
    int aux;
    aux = *x; // troca os valores utilizando uma variavel auxiliar
    *x = *y;
    *y = aux;
}

// funcao para encontrar o pivo de um vetor
int partition(int vet[], int left, int right){
    int i, j, pivo;
    pivo = vet[left]; // o pivo começa como o primeiro elemento
    i = left + 1; // "i" eh o proximo valor depois do pivo
    for (j = i; j <= right; j++){ // percorre o vetor de uma ponta a outra
        if (vet[j] < pivo){ // verifica se o valor em loop eh menor que o pivo
            trocar(&vet[j], &vet[i]); // troca o valor do loop pelo valor do "i"
            i++; // "i" passa para a proxima posicao
        }
    }
    trocar(&vet[left], &vet[i-1]); // troca o pivo com o valor de "i" - 1
    return i - 1; // retorna o indice do pivo
}

// funcao de ordenacao quick sort
void quickSort(int vet[], int left, int right){
    int pivo;
    if (left >= right){ // verifica se a parte esquerda foir maior ou igual a parte da direita
        return; // para
    }
    pivo = partition(vet, left, right); // retornar a posicao do pivo
    quickSort(vet, left, pivo-1); // utiliza a recursividade para a subparte esquerda
    quickSort(vet, pivo+1, right); // utiliza a recursividade para a subparte direita
}

// funcao de busca sequencial
int buscaSeq(int vet[], int key){
    int i;
    for (i = 0; i < N; i++){ // percorrer o vetor
        if (vet[i] == key){ // verificar se o valor na posicao "i" eh igual a chave
            return i; // retorna o indice o valor encontrado
        }
    }
    return -1; // se nao achou o valor, por padrao, retorna -1
}

// funcao de busca sequencial em um vetor ordenado
int buscaSeqOrd(int vet[], int key){
    int i;
    for (i = 0; i < N && key <= vet[i]; i++){ // percorrer o vetor e verifica se a chave eh menor que o valor na posicao "i"
        if (vet[i] == key){ // verificar se o valor na posicao "i" eh igual a chave
            return i; // retorna o indice do valor encontrado
        }
    }
    return -1; // se nao achou o valor, por padrao, retorna -1
}

// funcao de busca binaria
int buscaBin(int vet[], int key, int left, int right){
    int mid;
    if (right < left){ // verifica se o indice direito eh menor que o indice esquerdo
        return -1; // o valor nao foi encontrado
    }
    mid = (left + right) / 2; // encontar o indice do meio
    if (vet[mid] == key){ // verifica se o indice do meio possui o valor
        return mid; // se for igual, retorna o valor
    } else if (key < vet[mid]){ // verifica se o valor eh menor que o valor do meio;
        return buscaBin(vet, key, left, mid-1); // retorna a funcao novamente, mas agora buscando do meio para tras
    } // se o valor nao eh igual, nem menor que o meio, entao eh maior
    return buscaBin(vet, key, mid+1, right); // retorna a funcao novamente, mas agora buscando do meio para a frente
}