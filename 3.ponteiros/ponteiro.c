#include <stdio.h>

typedef struct {
    int hora, min, seg;
} time;

void mostraTime(time t){
    printf("%dh %dm %ds\n", t.hora, t.min, t.seg);
}

// utilizando ponteiro
void leTimeP(time *t) {
    printf("Informe a hora: ");
    scanf("%d", &t->hora);
    printf("Informe o minuto: ");
    scanf("%d", &t->min);
    printf("Informe o segundo: ");
    scanf("%d", &t->seg);

    printf("Dentro da funcao: ");
    mostraTime(*t);
}

// sem utilizar ponteiro
void leTime(time t) {
    printf("Informe a hora: ");
    scanf("%d", &t.hora);
    printf("Informe o minuto: ");
    scanf("%d", &t.min);
    printf("Informe o segundo: ");
    scanf("%d", &t.seg);

    printf("Dentro da funcao: ");
    mostraTime(t);
}

int main(){
    time t;

    leTime(t); // sem utilizar ponteiro
    printf("Fora da funcao: ");
    mostraTime(t);

    printf("\n--- Utilizando ponteiros ---\n");
    
    leTimeP(&t); // utilizando ponteiro, recebe o endereco
    printf("Fora da funcao: ");
    mostraTime(t);
}