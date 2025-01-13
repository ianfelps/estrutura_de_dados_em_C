#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora, min, seg;
} time;

void mostraTime(time t){
    printf("%dh %dm %ds\n", t.hora, t.min, t.seg);
}

// alocando memoria
time *criaTime(int hora, int min, int seg){
    time *t = (time *)malloc(sizeof(time)); // aloca memoria
    // validacao dos dados
    if (hora < 0 || hora > 24)
        return NULL;
    if (min < 0 || min > 60)
        return NULL;
    if (seg < 0 || seg > 60)
        return NULL;
    // atribuicao dos dados
    t->hora = hora;
    t->min = min;
    t->seg = seg;
    return t;
}

// utilizando endereco de memoria
time *leTime() {
    int hora, min, seg;
    time *t;
    do { // loop ate todos os dados serem validos
        printf("Informe a hora: ");
        scanf("%d", &hora);
        printf("Informe o minuto: ");
        scanf("%d", &min);
        printf("Informe o segundo: ");
        scanf("%d", &seg);
        t = criaTime(hora, min, seg);
    } while (t == NULL);
    return t;
}

int main(){
    time *t1, *t2;
    
    t1 = leTime(); // usuario insere os dados e a funcao chama a criaTime()
    t2 = criaTime(23, 59, 59); // inserindo os dados direto na funcao criaTime()
    
    printf("Tempo inserido pelo usuario: ");
    mostraTime(*t1); // mostrar t1

    printf("Tempo inserido diretamente na funcao: ");
    mostraTime(*t2); // mostrar t2
}