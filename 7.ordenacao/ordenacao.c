#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10 // tamanho dos vetores

// funcao
void preencher(int vet[], int max); // funcao para preencher um vetor com numeros aleatorios
void imprimir(int vet[]); // funcao para imprimir o vetor
void trocar(int *x, int *y); // funcao para fazer trocas dentro de um vetor

void bubbleSort(int vet[]); // funcao de ordenacao bubble sort

void selectionSort(int vet[]); // funcao de ordenacao selection sort
void insertionSort(int vet[]); // funcao de ordenacao insertion sort

int partition(int vet[], int left, int right); // funcao para encontrar o pivo de um vetor
void quickSort(int vet[], int left, int right); // funcao de ordenacao quick sort

void merge(int vet[], int left, int mid, int right); // funcao para juntar dois valores para a ordenacao
void mergeSort(int vet[], int left, int right); // funcao de ordenacao merge sort

int main(){

    int vet[N]; // criar vetor do tamanho da constante N

    srand(time(NULL)); // gerar os numeros aleatoriamente

    // Teste para bubble sort
    preencher(vet, 100);
    printf("Vetor original:\n");
    imprimir(vet);
    bubbleSort(vet);
    printf("Vetor ordenado com Bubble Sort:\n");
    imprimir(vet);
    printf("\n");

    // Teste para selection sort
    preencher(vet, 100);
    printf("Vetor original:\n");
    imprimir(vet);
    selectionSort(vet);
    printf("Vetor ordenado com Selection Sort:\n");
    imprimir(vet);
    printf("\n");

    // Teste para insertion sort
    preencher(vet, 100);
    printf("Vetor original:\n");
    imprimir(vet);
    insertionSort(vet);
    printf("Vetor ordenado com Insertion Sort:\n");
    imprimir(vet);
    printf("\n");

    // Teste para quick sort
    preencher(vet, 100);
    printf("Vetor original:\n");
    imprimir(vet);
    quickSort(vet, 0, N - 1);
    printf("Vetor ordenado com Quick Sort:\n");
    imprimir(vet);
    printf("\n");

    // Teste para merge sort
    preencher(vet, 100);
    printf("Vetor original:\n");
    imprimir(vet);
    mergeSort(vet, 0, N - 1);
    printf("Vetor ordenado com Merge Sort:\n");
    imprimir(vet);
    printf("\n");

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

// funcao de ordenacao bubble sort
void bubbleSort(int vet[]){
    int i, j, status = 1;
    for (i = 0; i < N-1 && status; i++){ // loop para o primeiro valor da comparacao
        status = 0; // nao houve troca
        for (j = 1; j < N-i; j++){ // loop para o segundo valor da comparacao
            if (vet[j-1] > vet[j]){ // se o numero anterior for maior, troca
                status = 1; // houve troca
                trocar(&vet[j], &vet[j-1]); // troca os valores
            }
        }
    }
}

// funcao de ordenacao selection sort
void selectionSort(int vet[]){
    int i, j, min;
    for (i = 0; i < N; i++){ // loop para as interacoes
        min = i;
        for (j = i + 1; j < N; j++){ // loop para encontrar o menor valor
            if (vet[j] < vet[min]){ // verificar se o valor eh menor que o "i"
                min = j; // se for menor, armazena o valor
            }
        }
        trocar(&vet[min], &vet[i]); // troca os valores
    }
}

// funcao de ordenacao insertion sort
void insertionSort(int vet[]){
    int i, j, aux;
    for (i = 1; i < N; i++){ // loop para percorrer o vetor
        aux = vet[i]; // variavel auxiliar recebe o numero da vez
        for (j = i-1; j >= 0 && aux < vet[j]; j--){ // loop para encontrar o valor maior que o aux
            vet[j+1] = vet[j]; // trocando a posicao
        }
        vet[j+1] = aux; // j recebe o valor de aux
    }
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

// funcao para juntar dois valores para a ordenacao
void merge(int vet[], int left, int mid, int right){
    int i = left, j = mid+1, k = 0;
    int n = (right - left) + 1; // quantidade de elementos do vetor
    int *vaux;
    vaux = (int*)malloc(n * sizeof(int)); // aloca um espaco na memoria para o vetor auxiliar

    while (i <= mid && j <= right) { // percorre o vetor fazendo as verificacoes
        if (vet[i] < vet[j]){ // se "i" for maior que "j"
            vaux[k++] = vet[i++]; // aumenta o valor de "k" e de "i"
        } else { // se nao
            vaux[k++] = vet[j++]; // aumenta o valor de "k" e de "j"
        }
    }

    while (i <= mid){
        vaux[k++] = vet[i++]; // copia os elemntos da primeira parte
    }

    while (j <= right){
        vaux[k++] = vet[j++]; // copia os elemntos da segunda parte
    }

    for (k = 0, i = left; k < n; i++, k++){ // copia os valores do vetor auxiliar para o vetor original
        vet[i] = vaux[k]; // armazena os valores
    }

    free(vaux);
}

// funcao de ordenacao merge sort
void mergeSort(int vet[], int left, int right){
    int mid;
    if (left >= right){ // verifica se a parte esquerda foir maior ou igual a parte da direita
        return; // para
    }

    mid = (left + right) / 2; // encontra a posicao do centro
    mergeSort(vet, left, mid); // utiliza a recursividade para a subparte esquerda
    mergeSort(vet, mid+1, right); // utiliza a recursividade para a subparte direita
    merge(vet, left, mid, right); // junta os valores para a ordenacao
}