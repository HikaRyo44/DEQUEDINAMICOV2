#include <stdio.h> // entrada e sa�da
#include <stdlib.h> // aloca��o de mem�ria
#include <locale.h> // manipula��o de localiza��o

typedef struct {
    int *array; // Array para armazenar os elementos do deque
    int inicio, fim; // �ndices para controlar o in�cio e o fim do deque
    int tamanho; // Tamanho m�ximo do deque
} Deque;

// Fun��o para inicializar o deque
void inicializarDeque(Deque *dq, int tamanho) {
    dq->array = (int *)malloc(tamanho * sizeof(int)); // Aloca mem�ria para o array do deque
    dq->inicio = -1; // Define o �ndice de in�cio como -1
    dq->fim = -1; // Define o �ndice de fim como -1
    dq->tamanho = tamanho; // Define o tamanho m�ximo do deque
}

// Fun��o para verificar se o deque est� vazio
int estaVazio(Deque *dq) {
    return (dq->inicio == -1 && dq->fim == -1); // Retorna verdadeiro se o in�cio e o fim forem -1
}

// Fun��o para verificar se o deque est� cheio
int estaCheio(Deque *dq) {
    return ((dq->fim + 1) % dq->tamanho == dq->inicio); // Retorna verdadeiro se o pr�ximo �ndice do fim for igual ao in�cio
}

// Fun��o para inserir um elemento no in�cio do deque
void inserirInicio(Deque *dq, int x) {
    if (estaCheio(dq)) { // Verifica se o deque est� cheio
        printf("Voc� inseriu o valor com sucesso, por�m o deque est� cheio!\n"); // Exibe uma mensagem de deque cheio
        return; // Retorna sem fazer nada
    } else if (estaVazio(dq)) { // Verifica se o deque est� vazio
        dq->inicio = 0; // Define o �ndice de in�cio como 0
        dq->fim = 0; // Define o �ndice de fim como 0
    } else { // Se o deque n�o estiver cheio nem vazio
        dq->inicio = (dq->inicio - 1 + dq->tamanho) % dq->tamanho; // Calcula o novo �ndice de in�cio
    }
    dq->array[dq->inicio] = x; // Insere o elemento no novo �ndice de in�cio
}

// Fun��o para inserir um elemento no fim do deque
void inserirFim(Deque *dq, int x) {
    if (estaCheio(dq)) { // Verifica se o deque est� cheio
        printf("Voc� inseriu o valor com sucesso, por�m o deque est� cheio!\n"); // Exibe uma mensagem de deque cheio
        return; // Retorna sem fazer nada
    } else if (estaVazio(dq)) { // Verifica se o deque est� vazio
        dq->inicio = 0; // Define o �ndice de in�cio como 0
        dq->fim = 0; // Define o �ndice de fim como 0
    } else { // Se o deque n�o estiver cheio nem vazio
        dq->fim = (dq->fim + 1) % dq->tamanho; // Calcula o novo �ndice de fim
    }
    dq->array[dq->fim] = x; // Insere o elemento no novo �ndice de fim
}

// Fun��o para remover um elemento do in�cio do deque
int removerInicio(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque est� vazio
        printf("O deque est� vazio!\n"); // Exibe uma mensagem de deque vazio
        return -1; // Retorna um valor inv�lido
    } else if (dq->inicio == dq->fim) { // Verifica se h� apenas um elemento no deque
        int x = dq->array[dq->inicio]; // Armazena o valor do elemento a ser removido
        dq->inicio = -1; // Define o �ndice de in�cio como -1
        dq->fim = -1; // Define o �ndice de fim como -1
        return x; // Retorna o valor do elemento removido
    } else { // Se houver mais de um elemento no deque
        int x = dq->array[dq->inicio]; // Armazena o valor do elemento a ser removido
        dq->inicio = (dq->inicio + 1) % dq->tamanho; // Calcula o novo �ndice de in�cio
        return x; // Retorna o valor do elemento removido
    }
}

// Fun��o para remover um elemento do fim do deque
int removerFim(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque est� vazio
        printf("O deque est� vazio!\n"); // Exibe uma mensagem de deque vazio
        return -1; // Retorna um valor inv�lido
    } else if (dq->inicio == dq->fim) { // Verifica se h� apenas um elemento no deque
        int x = dq->array[dq->fim]; // Armazena o valor do elemento a ser removido
        dq->inicio = -1; // Define o �ndice de in�cio como -1
        dq->fim = -1; // Define o �ndice de fim como -1
        return x; // Retorna o valor do elemento removido
    } else { // Se houver mais de um elemento no deque
        int x = dq->array[dq->fim]; // Armazena o valor do elemento a ser removido
        dq->fim = (dq->fim - 1 + dq->tamanho) % dq->tamanho; // Calcula o novo �ndice de fim
        return x; // Retorna o valor do elemento removido
    }
}

// Fun��o para exibir os elementos do deque
void exibir(Deque *dq) {
    if (estaVazio(dq)) { // Verifica se o deque est� vazio
        printf("O deque est� vazio!\n"); // Exibe uma mensagem de deque vazio
        return; // Retorna sem fazer nada
    }
    printf("Elementos do deque: "); // Exibe uma mensagem indicando os elementos do deque
    int i = dq->inicio; // Inicializa o �ndice para percorrer o deque
    while (i != dq->fim) { // Enquanto n�o chegar ao fim do deque
        printf("%d ", dq->array[i]); // Exibe o elemento atual
        i = (i + 1) % dq->tamanho; // Avan�a para o pr�ximo �ndice (considerando a circularidade do deque)
    }
    printf("%d\n", dq->array[i]); // Exibe o �ltimo elemento do deque
}

// Fun��o principal
int main() {
	setlocale(LC_ALL,"portuguese");
	
    int tamanho;
    printf("Digite o tamanho do deque: ");
    scanf("%d", &tamanho); // Solicita ao usu�rio que digite o tamanho do deque
    
    if(tamanho <= 0){
    	printf("ERRO: tamanho incorreto, insira n�meros positivos maior que 0!\n\n");
    	printf("C�digo do erro: 0xE004A1F7\n\n\n");
    	return 1;
	}

    Deque dq; // Declara uma vari�vel do tipo Deque
    inicializarDeque(&dq, tamanho); // Inicializa o deque com o tamanho especificado

    int opcao, valor;

    do { // Loop do menu
        printf("\nMenu:\n"); // Exibe o menu de op��es
        printf("1. Inserir no in�cio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do in�cio\n");
        printf("4. Remover do fim\n");
        printf("5. Exibir elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao); // Solicita ao usu�rio que escolha uma op��o

        switch (opcao) { // Executa a op��o selecionada pelo usu�rio
            case 1: // Op��o para inserir no in�cio
                printf("Digite o valor a ser inserido no in�cio: ");
                scanf("%d", &valor); // Solicita ao usu�rio que digite o valor a ser inserido
                inserirInicio(&dq, valor); // Insere o valor no in�cio do deque
                printf("Valor %d inserido no in�cio do deque.\n", valor); // Exibe uma mensagem de confirma��o
                break;
            case 2: // Op��o para inserir no fim
                printf("Digite o valor a ser inserido no fim: ");
                scanf("%d", &valor); // Solicita ao usu�rio que digite o valor a ser inserido
                inserirFim(&dq, valor); // Insere o valor no fim do deque
                printf("Valor %d inserido no fim do deque.\n", valor); // Exibe uma mensagem de confirma��o
                break;
            case 3: // Op��o para remover do in�cio
                printf("Elemento removido do in�cio: %d\n", removerInicio(&dq)); // Remove um elemento do in�cio do deque e exibe seu valor
                break;
            case 4: // Op��o para remover do fim
                printf("Elemento removido do fim: %d\n", removerFim(&dq)); // Remove um elemento do fim do deque e exibe seu valor
                break;
            case 5: // Op��o para exibir elementos
                exibir(&dq); // Exibe os elementos do deque
                break;
            case 0: // Op��o para sair do programa
                printf("Encerrando o programa.\n"); // Exibe uma mensagem de encerramento
                system("pause");
                break;
            default: // Op��o para op��es inv�lidas
                printf("Op��o inv�lida!\n"); // Exibe uma mensagem de op��o inv�lida
        }
    } while (opcao != 0); // Repete o loop do menu at� que o usu�rio escolha a op��o de sair

    free(dq.array); // Libera a mem�ria alocada para o array do deque
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}

