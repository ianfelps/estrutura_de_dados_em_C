# Estrutura de Dados em C
Este repositório é dedicado ao estudo e implementação de diversas estruturas de dados na linguagem C. Aqui, você encontrará exemplos práticos e explicações sobre como utilizar cada estrutura, além de algoritmos relacionados.
- [Playlist do Curso: Estrutura de dados em C](https://www.youtube.com/playlist?list=PLZp_AigPrZjPbjVydii2mQZ48jarYiv6L)

## 1. Estruturas Básicas
### Arquivo: `01.estruturas/estrutura.c`
Neste arquivo, é definida uma estrutura chamada `produto`, que representa um produto com os seguintes atributos:
- `codigo`: um inteiro que identifica o produto.
- `nome`: uma string que armazena o nome do produto.
- `qtd`: um inteiro que representa a quantidade em estoque.
- `valor`: um número de ponto flutuante que indica o valor unitário do produto.
O programa permite a atribuição de valores a um produto e a comparação do valor total em estoque de dois produtos.

## 2. Funções
### Arquivo: `02.funcoes/funcao.c`
Este arquivo contém funções utilitárias que demonstram conceitos básicos de programação em C:
- `linha(int qtd, char simbolo)`: imprime uma linha de caracteres.
- `centralizar(char texto[], int qtd)`: centraliza um texto em relação a uma largura especificada.
- `porcentagem(float valor, float total)`: calcula a porcentagem de um valor em relação a um total.
Essas funções são chamadas no `main` para demonstrar seu funcionamento.

## 3. Ponteiros
### Arquivo: `03.ponteiros/ponteiro.c`
Este arquivo explora o uso de ponteiros em C, especialmente em relação a estruturas. A estrutura `time` é definida para armazenar horas, minutos e segundos. O programa demonstra duas funções:
- `leTimeP(time *t)`: lê os valores de tempo usando ponteiros, permitindo que as alterações sejam refletidas fora da função.
- `leTime(time t)`: lê os valores de tempo sem usar ponteiros, mostrando como as alterações não afetam a variável original.

## 4. Alocação Dinâmica
### Arquivo: `04.alocacao/alocacao.c`
Neste arquivo, a estrutura `time` é utilizada novamente, mas com alocação dinâmica de memória. As funções permitem:
- `criaTime(int hora, int min, int seg)`: cria uma nova instância de `time` alocando memória dinamicamente.
- `leTime()`: lê os valores de tempo do usuário e retorna um ponteiro para a nova instância de `time`.
O programa demonstra como gerenciar a memória e garantir que os dados sejam válidos.

## 5. Tipos Abstratos de Dados
### Arquivo: `05.tipos_abstratos/tempo.c`
Este arquivo implementa operações em uma estrutura de tempo, permitindo a manipulação de horas, minutos e segundos. As funções incluem:
- `paraSeg(tempo *t)`: converte um tempo em segundos.
- `paraTempo(long int s)`: converte segundos de volta para a estrutura de tempo.
- Funções para adicionar e subtrair segundos, minutos e horas, além de calcular a soma e a diferença entre dois tempos.

## 6. Pilha
### Arquivo: `06.pilha/dinamica/pilha.c` e `06.pilha/estatica/pilha.c`
Estes arquivos implementam uma pilha, tanto de forma dinâmica quanto estática. As operações incluem:
- `push`: adiciona um elemento ao topo da pilha.
- `pop`: remove e retorna o elemento do topo da pilha.
- `top`: retorna o elemento do topo sem removê-lo.
- `isEmpty`: verifica se a pilha está vazia.
A versão dinâmica utiliza alocação de memória para os nós, enquanto a versão estática utiliza um vetor fixo.

## 7. Ordenação
### Arquivo: `07.ordenacao/ordenacao.c`
Este arquivo implementa vários algoritmos de ordenação, incluindo:
- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**
- **Quick Sort**
- **Merge Sort**
Cada algoritmo é testado em um vetor de números aleatórios, e os resultados são impressos.

## 8. Busca
### Arquivo: `08.busca/busca.c`
Este arquivo implementa algoritmos de busca, incluindo:
- **Busca Sequencial**: percorre o vetor até encontrar o valor desejado.
- **Busca Binária**: requer que o vetor esteja ordenado e divide o espaço de busca pela metade a cada iteração.
Os resultados da busca são impressos, indicando se o valor foi encontrado ou não.

## 9. Fila
### Arquivo: `09.fila/dinamica/fila.c` e `09.fila/estatica/fila.c`
Estes arquivos implementam uma fila, tanto de forma dinâmica quanto estática. As operações incluem:
- `enqueue`: adiciona um elemento ao final da fila.
- `dequeue`: remove e retorna o elemento do início da fila.
- `isEmpty`: verifica se a fila está vazia.
A versão dinâmica utiliza alocação de memória para os nós, enquanto a versão estática utiliza um vetor fixo.

## 10. Listas Encadeadas
### Arquivo: `10.lista_encadeada/lista.c`
Este arquivo implementa uma lista encadeada simples, permitindo a adição e remoção de elementos. As operações incluem:
- `inserir`: adiciona um novo nó ao final da lista.
- `remover`: remove um nó específico da lista.
- `imprimir`: exibe todos os elementos da lista.
A lista é composta por nós que contêm dados e um ponteiro para o próximo nó.

## 11. Árvores
### Arquivo: `11.arvore/arvore.c`
Este arquivo implementa uma árvore binária de busca, permitindo a inserção, remoção e busca de elementos. As operações incluem:
- `inserir`: adiciona um novo nó à árvore.
- `remover`: remove um nó da árvore, mantendo a propriedade da árvore binária de busca.
- `buscar`: verifica se um determinado valor está presente na árvore.
A estrutura da árvore é representada por nós que contêm dados e ponteiros para os filhos esquerdo e direito.
