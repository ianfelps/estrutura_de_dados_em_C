#include <stdio.h>
#include <string.h>

// criar struct
typedef struct {
    int codigo; // valores
    char nome[30];
    int qtd;
    float valor;
} produto; // apelido

int main(){
    produto p1, p2; // declarar struct
    float t1, t2;

    // atribuir valores
    p1.codigo = 1;
    strcpy(p1.nome, "Tijolo");
    p1.qtd = 10000;
    p1.valor = 0.25;

    // atribuir valores via prompt
    p2.codigo = 2;
    printf("\nInforme o nome do produto: ");
    scanf("%s", p2.nome);
    printf("\nInforme o valor unitario: ");
    scanf("%f", &p2.valor);
    printf("\nInforme a quantidade em estoque: ");
    scanf("%d", &p2.qtd);

    t1 = p1.qtd * p1.valor;
    t2 = p2.qtd * p2.valor;

    printf("\nValor em estoque: ");
    if (t1 < t2){
        printf("\n%s: R$ %.2f", p1.nome, t1);
        printf("\n%s: R$ %.2f", p2.nome, t2);
    } else {
        printf("\n%s: R$ %.2f", p2.nome, t2);
        printf("\n%s: R$ %.2f", p1.nome, t1);
    }

}