#include <stdio.h> // entrada e saída
#include <stdlib.h> // alocação de memória
#include <locale.h> // manipulação de localização

typedef struct {
    int *array; // Array para armazenar os elementos do deque
    int inicio, fim; // Índices para controlar o início e o fim do deque
    int tamanho; // Tamanho máximo do deque
} Deque;

// Função para inicializar o deque
void inicializarDeque(Deque *dq, int tamanho) {
    dq->array = (int *)malloc(tamanho * sizeof(int)); // Aloca memória para o array do deque
    dq->inicio = -1; // Define o índice de início como -1
    dq->fim = -1; // Define o índice de fim como -1
    dq->tamanho = tamanho; // Define o tamanho máximo do deque
}

// Função para verificar se o deque está vazio
int estaVazio(Deque *dq) {
    return (dq->inicio == -1 && dq->fim == -1); // Retorna verdadeiro se o início e o fim forem -1
}

// Função para verificar se o deque está cheio
int estaCheio(Deque *dq) {
    return ((dq->fim + 1) % dq->tamanho == dq->inicio); // Retorna verdadeiro se o próximo índice do fim for igual ao início
}

// Função para inserir um elemento no início do deque
void inserirInicio(Deque *dq, int x) {
    if (estaCheio(dq)) { // Verifica se o deque está cheio
        printf("Você inseriu o valor com sucesso, porém o deque está cheio!\n"); // Exibe uma mensagem de deque cheio
        return; // Retorna sem fazer nada
    } else if (estaVazio(dq)) { // Verifica se o deque está vazio
        dq->inicio = 0; // Define o índice de início como 0
        dq->fim = 0; // Define o índice de fim como 0
    } else { // Se o deque não estiver cheio nem vazio
        dq->inicio = (dq->inicio - 1 + dq->tamanho) % dq->tamanho; // Calcula o novo índice de início
    }
    dq->array[dq->inicio] = x; // Insere o elemento no novo índice de início
}

// Função para inserir um elemento no fim do deque
void inserirFim(Deque *dq, int x) {
    if (estaCheio(dq)) { // Verifica se o deque está cheio
        printf("Você inseriu o valor com sucesso, porém o deque está cheio!\n"); // Exibe uma mensagem de deque cheio
        return; // Retorna sem fazer nada
    } else if (estaVazio(dq)) { // Verifica se o deque está vazio
        dq->inicio = 0; // Define o índice de início como 0
        dq->fim = 0; // Define o índice de fim como 0
    } else { // Se o deque não estiver cheio nem vazio
        dq->fim = (dq->fim + 1) % dq->tamanho; // Calcula o novo índice de fim
    }
    dq->array[dq->fim] = x; // Insere o elemento no novo índice de fim
}

// Função para remover um elemento do início do deque
int removerInicio(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque está vazio
        printf("O deque está vazio!\n"); // Exibe uma mensagem de deque vazio
        return -1; // Retorna um valor inválido
    } else if (dq->inicio == dq->fim) { // Verifica se há apenas um elemento no deque
        int x = dq->array[dq->inicio]; // Armazena o valor do elemento a ser removido
        dq->inicio = -1; // Define o índice de início como -1
        dq->fim = -1; // Define o índice de fim como -1
        return x; // Retorna o valor do elemento removido
    } else { // Se houver mais de um elemento no deque
        int x = dq->array[dq->inicio]; // Armazena o valor do elemento a ser removido
        dq->inicio = (dq->inicio + 1) % dq->tamanho; // Calcula o novo índice de início
        return x; // Retorna o valor do elemento removido
    }
}

// Função para remover um elemento do fim do deque
int removerFim(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque está vazio
        printf("O deque está vazio!\n"); // Exibe uma mensagem de deque vazio
        return -1; // Retorna um valor inválido
    } else if (dq->inicio == dq->fim) { // Verifica se há apenas um elemento no deque
        int x = dq->array[dq->fim]; // Armazena o valor do elemento a ser removido
        dq->inicio = -1; // Define o índice de início como -1
        dq->fim = -1; // Define o índice de fim como -1
        return x; // Retorna o valor do elemento removido
    } else { // Se houver mais de um elemento no deque
        int x = dq->array[dq->fim]; // Armazena o valor do elemento a ser removido
        dq->fim = (dq->fim - 1 + dq->tamanho) % dq->tamanho; // Calcula o novo índice de fim
        return x; // Retorna o valor do elemento removido
    }
}

// Função para exibir os elementos do deque
void exibir(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque está vazio
        printf("O deque está vazio!\n"); // Exibe uma mensagem de deque vazio
        return; // Retorna sem fazer nada
    }
    printf("Elementos do deque: "); // Exibe uma mensagem indicando os elementos do deque
    int i = dq->inicio; // Inicializa o índice para percorrer o deque
    while (i != dq->fim) { // Enquanto não chegar ao fim do deque
        printf("%d ", dq->array[i]); // Exibe o elemento atual
        i = (i + 1) % dq->tamanho; // Avança para o próximo índice (considerando a circularidade do deque)
    }
    printf("%d\n", dq->array[i]); // Exibe o último elemento do deque
}

// Função principal
int main() {
	setlocale(LC_ALL,"portuguese");
	
    int tamanho;
    printf("Digite o tamanho do deque: ");
    scanf("%d", &tamanho); // Solicita ao usuário que digite o tamanho do deque
    
    if(tamanho <= 0){
    	printf("ERRO: tamanho incorreto, insira números positivos maior que 0!\n\n");
    	printf("Código do erro: 0xE004A1F7\n\n\n");
    	return 1;
	}

    Deque dq; // Declara uma variável do tipo Deque
    inicializarDeque(&dq, tamanho); // Inicializa o deque com o tamanho especificado

    int opcao, valor;

    do { // Loop do menu
        printf("\nMenu:\n"); // Exibe o menu de opções
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do início\n");
        printf("4. Remover do fim\n");
        printf("5. Exibir elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Solicita ao usuário que escolha uma opção

        switch (opcao) { // Executa a opção selecionada pelo usuário
            case 1: // Opção para inserir no início
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &valor); // Solicita ao usuário que digite o valor a ser inserido
                inserirInicio(&dq, valor); // Insere o valor no início do deque
                printf("Valor %d inserido no início do deque.\n", valor); // Exibe uma mensagem de confirmação
                break;
            case 2: // Opção para inserir no fim
                printf("Digite o valor a ser inserido no fim: ");
                scanf("%d", &valor); // Solicita ao usuário que digite o valor a ser inserido
                inserirFim(&dq, valor); // Insere o valor no fim do deque
                printf("Valor %d inserido no fim do deque.\n", valor); // Exibe uma mensagem de confirmação
                break;
            case 3: // Opção para remover do início
                printf("Elemento removido do início: %d\n", removerInicio(&dq)); // Remove um elemento do início do deque e exibe seu valor
                break;
            case 4: // Opção para remover do fim
                printf("Elemento removido do fim: %d\n", removerFim(&dq)); // Remove um elemento do fim do deque e exibe seu valor
                break;
            case 5: // Opção para exibir elementos
                exibir(&dq); // Exibe os elementos do deque
                break;
            case 0: // Opção para sair do programa
                printf("Encerrando o programa.\n"); // Exibe uma mensagem de encerramento
                system("pause");
                break;
            default: // Opção para opções inválidas
                printf("Opção inválida!\n"); // Exibe uma mensagem de opção inválida
        }
    } while (opcao != 0); // Repete o loop do menu até que o usuário escolha a opção de sair

    free(dq.array); // Libera a memória alocada para o array do deque
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}

