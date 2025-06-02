#include <stdio.h>

#define TAM 10         // Tamanho do tabuleiro
#define NAVIO_TAM 3    // Tamanho fixo dos navios
#define NAVIO 3        // Valor que representa um navio no tabuleiro

// Função para verificar se as posições estão livres (sem sobreposição)
int posicaoLivre(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linha[i]][coluna[i]] == NAVIO) {
            return 0; // posição já ocupada
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------
    // NAVIO 1 - Horizontal (linha 1, colunas 1 a 3)
    // -------------------------------
    int linhaH1[NAVIO_TAM] = {1, 1, 1};
    int colunaH1[NAVIO_TAM] = {1, 2, 3};

    if (posicaoLivre(tabuleiro, linhaH1, colunaH1)) {
        posicionarNavio(tabuleiro, linhaH1, colunaH1);
    }

    // -------------------------------
    // NAVIO 2 - Vertical (coluna 6, linhas 4 a 6)
    // -------------------------------
    int linhaV2[NAVIO_TAM] = {4, 5, 6};
    int colunaV2[NAVIO_TAM] = {6, 6, 6};

    if (posicaoLivre(tabuleiro, linhaV2, colunaV2)) {
        posicionarNavio(tabuleiro, linhaV2, colunaV2);
    }

    // -------------------------------
    // NAVIO 3 - Diagonal ↘ (de cima para baixo, esquerda para direita)
    // Começa em (0,0)
    // -------------------------------
    int linhaD3[NAVIO_TAM] = {0, 1, 2};
    int colunaD3[NAVIO_TAM] = {0, 1, 2};

    if (posicaoLivre(tabuleiro, linhaD3, colunaD3)) {
        posicionarNavio(tabuleiro, linhaD3, colunaD3);
    }

    // -------------------------------
    // NAVIO 4 - Diagonal ↙ (de cima para baixo, direita para esquerda)
    // Começa em (0, 9)
    // -------------------------------
    int linhaD4[NAVIO_TAM] = {0, 1, 2};
    int colunaD4[NAVIO_TAM] = {9, 8, 7};

    if (posicaoLivre(tabuleiro, linhaD4, colunaD4)) {
        posicionarNavio(tabuleiro, linhaD4, colunaD4);
    }

    // -------------------------------
    // Exibir o tabuleiro final
    // -------------------------------
    exibirTabuleiro(tabuleiro);

    return 0;
}
