// xadrez.c
// Simulação dos movimentos da Torre, Bispo e Rainha
// Desafio de programação iniciante

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

    return 0;
}
