#include <stdio.h>
#include <string.h>

// assinatura/prototipo das funcoes
void linha(int qtd, char simbolo);
void centralizar(char texto[], int qtd);
float porcentagem(float valor, float total);

int main(){
    // chamada das funções
    linha(40, '-');
    centralizar("Ola Mundo!", 40);
    linha(40, '-');

    // chamada da funcao com return
    printf("Porcentagem: %.0f%% - %.0f%%\n", porcentagem(20, 50), porcentagem(5, porcentagem(20, 50)));
}

// funcoes
void linha(int qtd, char simbolo){ // printar um numero de caracteres em linha
    int i;
    for (i = 0; i < qtd; i++){
        printf("%c", simbolo);
    }
    printf("\n");
}

void centralizar(char texto[], int qtd){ // centralizar um texto a partir de um tamanho
    int i, espaco;
    espaco = (qtd / 2) - (strlen(texto) / 2);
    for (i = 0; i < espaco; i++){
        printf(" ");
    }
    printf("%s\n", texto);
}

float porcentagem(float valor, float total){ // calcular porcentagem
    return (valor / total) * 100;
}