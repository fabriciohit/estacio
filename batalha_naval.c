#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define EFEITO 5

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Sobrepõe a área de efeito no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - 2 + i;
                int colunaTab = origemColuna - 2 + j;

                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    if (tabuleiro[linhaTab][colunaTab] == 0) {
                        tabuleiro[linhaTab][colunaTab] = EFEITO;
                    }
                }
            }
        }
    }
}

// Gera matriz de habilidade em forma de cone apontando para baixo
void gerarCone(int cone[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
            // Condições para formar o cone
            if (i == 0 && j == 2) cone[i][j] = 1;
            if (i == 1 && (j >= 1 && j <= 3)) cone[i][j] = 1;
            if (i == 2) cone[i][j] = 1;
        }
    }
}

// Gera matriz de habilidade em forma de cruz
void gerarCruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
}

// Gera matriz de habilidade em forma de octaedro (losango)
void gerarOctaedro(int octaedro[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            octaedro[i][j] = 0;
            if (i + j >= 2 && i + j <= 6 && i - j <= 2 && j - i <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    inicializarTabuleiro(tabuleiro);

    // Exemplo de navios posicionados manualmente
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    tabuleiro[4][6] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;

    // Geração das matrizes de habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);      // Cone no centro superior
    aplicarHabilidade(tabuleiro, cruz, 6, 6);      // Cruz na parte inferior
    aplicarHabilidade(tabuleiro, octaedro, 5, 2);  // Octaedro no canto esquerdo

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
