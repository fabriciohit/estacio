// xadrez.c
// Simulação dos movimentos das peças de xadrez: Torre, Bispo, Rainha e Cavalo

#include <stdio.h>

int main() {
    // -------------------------
    // Movimento da TORRE
    // -------------------------
    // A torre vai andar 5 casas para a direita usando o laço FOR
    int i;
    printf("Movimento da Torre:\n");
    for (i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // -------------------------
    // Movimento do BISPO
    // -------------------------
    // O bispo vai andar 5 casas na diagonal para cima e para a direita
    // usando o laço WHILE
    int contadorBispo = 1;
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo <= 5) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // -------------------------
    // Movimento da RAINHA
    // -------------------------
    // A rainha vai andar 8 casas para a esquerda usando o laço DO-WHILE
    int contadorRainha = 1;
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= 8);

    // -------------------------
    // Movimento do CAVALO
    // -------------------------
    // O cavalo vai fazer o movimento em L:
    // 2 casas para baixo + 1 casa para a esquerda
    // Usando loops aninhados (for e while)

    printf("\nMovimento do Cavalo:\n");

    // Primeiro FOR para controlar a quantidade de movimentos "L"
    // Aqui simulamos só 1 movimento em L
    for (int movimentoL = 1; movimentoL <= 1; movimentoL++) {
        // Movimento para baixo (2 vezes)
        int passosParaBaixo = 1;
        while (passosParaBaixo <= 2) {
            printf("Baixo\n");
            passosParaBaixo++;
        }

        // Movimento para esquerda (1 vez)
        printf("Esquerda\n");
    }

    return 0;
}
