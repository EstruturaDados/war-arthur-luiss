// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---- Constantes Globais ----
#define MAX_TERRITORIO 5
#define MAX_STRING 100

// ---- Estruturas de Dados ----
typedef struct {
    char territorio[MAX_STRING];
    char cor[MAX_STRING];
    int tropas;
} Territorio;

// ---- Função para limpar o buffer de entrada ----
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer até encontrar uma nova linha ou EOF
}

// --- Função Principal ---
int main() {
    Territorio t[MAX_TERRITORIO];
    int i = 0;
    int TT = 0; // Total de Territórios cadastrados

    printf("=======================================================================\n");
    printf("==================== Bem-vindo ao jogo de guerra ======================\n");
    printf("=======================================================================\n\n");

    printf("====== Vamos cadastrar os 5 territorios iniciais do nosso mundo =======\n\n");

    while (i < MAX_TERRITORIO) {

        printf("---- Cadastro do território %d ----\n", i + 1);

        printf("Nome do Território: ");
        fgets(t[TT].territorio, MAX_STRING, stdin);
        t[TT].territorio[strcspn(t[TT].territorio, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Cor do Exercito (ex.: Azul, Verde): ");
        fgets(t[TT].cor, MAX_STRING, stdin);
        t[TT].cor[strcspn(t[TT].cor, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Número de tropas: ");
        while (scanf("%d", &t[TT].tropas) != 1 || t[TT].tropas < 0) {
            printf("Entrada inválida. Digite um número inteiro não negativo para tropas: ");
            limparBuffer(); // Limpa o buffer de entrada
        }
        printf("\n");
        limparBuffer(); // Limpa o buffer após a leitura do número

        i++;
        TT++;
    }
    
    printf("\n=======================================================================\n");
    printf("---- Resumo dos Territórios Cadastrados ----\n");
    printf("=======================================================================\n");

    for(i = 0; i < TT; i++) {
        printf("\nTERRITORIO %d:\n", i + 1);
        printf("Nome: %s\n", t[i].territorio);
        printf("Dominado por: Exercito %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);
    }

    return 0;
}