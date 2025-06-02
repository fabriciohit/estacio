// xadrez.c (continuando no mesmo arquivo)
// Adicionando desafio Batalha Naval - Nível Novato

#include <stdio.h>

#define TAMANHO 10  // tamanho fixo do tabuleiro
#define NAVIO_TAM 3 // tamanho fixo dos navios

int main() {
    // -------------------------
    // INICIALIZAÇÃO DO TABULEIRO
    // -------------------------
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Preenche o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------
    // POSICIONAMENTO DOS NAVIOS
    // -------------------------

    // Navio horizontal
    int navioH[NAVIO_TAM] = {3, 3, 3}; // representa o navio com três partes
    int linhaH = 2; // linha inicial
    int colunaH = 4; // coluna inicial

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + NAVIO_TAM <= TAMANHO) {
        for (int i = 0; i < NAVIO_TAM; i++) {
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    }

    // Navio vertical
    int navioV[NAVIO_TAM] = {3, 3, 3};
    int linhaV = 5;
    int colunaV = 7;

    // Verifica se o navio vertical cabe no tabuleiro e não sobrepõe o horizontal
    if (linhaV + NAVIO_TAM <= TAMANHO) {
        int podePosicionar = 1;

        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                podePosicionar = 0; // já tem navio nessa posição
                break;
            }
        }

        if (podePosicionar) {
            for (int i = 0; i < NAVIO_TAM; i++) {
                tabuleiro[linhaV + i][colunaV] = navioV[i];
            }
        } else {
            printf("Erro: sobreposição de navios detectada!\n");
        }
    }

    // -------------------------
    // EXIBINDO O TABULEIRO
    // -------------------------
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
