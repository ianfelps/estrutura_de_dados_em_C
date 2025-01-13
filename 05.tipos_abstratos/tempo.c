#include <stdlib.h>
#include <stdio.h>

// estrutura do tempo
typedef struct {
    int hora;
    int min;
    int seg;
} tempo;

// operacoes
long int paraSeg(tempo *t); // transformar um tempo para segundos
tempo *paraTempo(long int s); // transformar segundos para um tempo

tempo *criarTempo(int h, int m, int s); // criar uma instancia de tempo
tempo *lerTempo(); // fazer a leitura de um tempo

void mostrarTempo(tempo *t); // exibir um tempo

tempo *addSeg(tempo *t, long int seg); // adicionar segundos a um tempo
tempo *decSeg(tempo *t, long int seg); // retirar segundos de um tempo

tempo *addMin(tempo *t, long int min); // adicionar minutos a um tempo
tempo *decMin(tempo *t, long int min); // retirar minutos de um tempo

tempo *addHora(tempo *t, long int hora); // adicionar horas a um tempo
tempo *decHora(tempo *t, long int hora); // retirar horas de um tempo

tempo *subTempo(tempo *t1, tempo *t2); // calcula a diferenca entre dois tempos
tempo *addTempo(tempo *t1, tempo *t2); // calcula a soma entre dois tempos

int main() {
    tempo *t1, *t2; // cria os ponteiros

    t1 = criarTempo(10, 20, 30); // atribuir valores via codigo
    t2 = addTempo(criarTempo(3, 4, 5), t1); // tempo 2 eh igual a soma do tempo 1 mais 3h 4m 5s
    // t2 = lerTempo(); // atribuir valores via terminal

    t1 = decHora(t1, 3); // retira 3 horas do tempo 1

    printf("Hora 1: ");
    mostrarTempo(t1); // mostrar t1
    printf("Hora 2: ");
    mostrarTempo(t2); // mostrar t2
}

// transformar um tempo para segundos
long int paraSeg(tempo *t){
    return t->hora * 3600 + t->min * 60 + t->seg; // converter todo o tempo para segundos
}

// transformar segundos para um tempo
tempo *paraTempo(long int s){
    int h;
    h = s / 3600;
    s = s % 3600;
    return criarTempo(h, s / 60, s % 60); // converter segundos para um tempo
}

// criar uma instancia de tempo
tempo *criarTempo(int h, int m, int s){
    tempo * t = (tempo *)malloc(sizeof(tempo)); // alocar memoria
    // validacao dos dados
    if (h < 0 || h >= 24)
        return NULL;
    if (m < 0 || m >= 60)
        return NULL;
    if (s < 0 || s >= 60)
        return NULL;
    t->hora = h; // hora recebe h
    t->min = m; // min recebe m
    t->seg = s; // seg recebe s
    return t; // retorna o ponteiro
}

// fazer a leitura de um tempo
tempo *lerTempo(){
    int h, m, s;
    // coletar e armazenar dados
    printf("Informe a hora: ");
    scanf("%d", &h);
    printf("Informe o minuto: ");
    scanf("%d", &m);
    printf("Informe o segundo: ");
    scanf("%d", &s);
    return criarTempo(h, m, s); // retorna a funcao de criar tempo
}

// exibir um tempo
void mostrarTempo(tempo *t){
    printf("%02dh : %02dm : %02ds\n", t->hora, t->min, t->seg); // printar dados
}

// adicionar segundos a um tempo
tempo *addSeg(tempo *t, long int seg){
    // converter todo o tempo para segundos e adicionar os segundos desejados, e depois converte tudo para tempo
    tempo *aux = paraTempo(paraSeg(t) + seg);
    // t recebe aux
    t->hora = aux->hora;
    t->min = aux->min;
    t->seg = aux->seg;
    free(aux); // liberar variavel auxiliar
    return t; // retornar t
}

// retirar segundos de um tempo
tempo *decSeg(tempo *t, long int seg){
    // converte tudo para segundos e remove os segundos desejados
    long int total = paraSeg(t) - seg;
    // verifica se eh possivel fazer a remocao
    if (total < 0){
        printf("Tempo em segundos invalido!");
        return NULL; // retorna nulo
    }
    tempo *aux = paraTempo(total); // converte os segundos para tempo
    // t recebe aux
    t->hora = aux->hora;
    t->min = aux->min;
    t->seg = aux->seg;
    free(aux); // liberar variavel auxiliar
    return t; // retornar t
}

// adicionar minutos a um tempo
tempo *addMin(tempo *t, long int min){
    return addSeg(t, min * 60); // converte min para seg e utiliza a funcao de adicionar segundos
}

// retirar minutos de um tempo
tempo *decMin(tempo *t, long int min){
    return decSeg(t, min * 60); // converte min para seg e utiliza a funcao de retirar segundos
}

// adicionar horas a um tempo
tempo *addHora(tempo *t, long int hora){
    return addSeg(t, hora * 3600); // converte hora para seg e utiliza a funcao de adicionar segundos
}

// retirar horas de um tempo
tempo *decHora(tempo *t, long int hora){
    return decSeg(t, hora * 3600); // converte hora para seg e utiliza a funcao de retirar segundos
}

// calcula a diferenca entre dois tempos
tempo *subTempo(tempo *t1, tempo *t2){
    long int s1, s2;
    // converte os dois tempos para segundos
    s1 = paraSeg(t1);
    s2 = paraSeg(t2);
    // verifica qual tempo eh maior para fazer a subtracao
    if (s1 > s2){
        return paraTempo(s1 - s2); // retorna a diferenca do maior para o menor
    } else {
        return paraTempo(s2 - s1); // retorna a diferenca do maior para o menor
    }
}

// calcula a soma entre dois tempos
tempo *addTempo(tempo *t1, tempo *t2){
    long int s1, s2;
    // converte os dois tempos para segundos
    s1 = paraSeg(t1);
    s2 = paraSeg(t2);
    // retornar a conversao da soma dos dois tempos em segundos em tempo
    return paraTempo(s1 + s2);
}