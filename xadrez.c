// xadrez.c
// Simulação dos movimentos das peças de xadrez
// Nível Mestre - Recursividade e Loops Aninhados Complexos

#include <stdio.h>

// Função recursiva para mover a Torre para a direita
void moverTorre(int passos) {
    if (passos == 0) return;
    printf("Direita\n");
    moverTorre(passos - 1);
}

// Função recursiva para mover a Rainha para a esquerda
void moverRainha(int passos) {
    if (passos == 0) return;
    printf("Esquerda\n");
    moverRainha(passos - 1);
}

// Função recursiva para movimentar o Bispo
void moverBispoRecursivo(int passos) {
    if (passos == 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(passos - 1);
}

// Movimento do Cavalo com loops complexos
void moverCavalo() {
    printf("\nMovimento do Cavalo:\n");

    // O cavalo se move em "L": 2 para cima, 1 para direita
    int movimentosFeitos = 0;
    for (int i = 0; i < 3; i++) { // loop externo para simular múltiplas tentativas
        for (int j = 0; j < 3; j++) { // loop interno
            if (i == 0 && j == 1) {
                // Simula o movimento correto: 2 cima, 1 direita
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                movimentosFeitos++;
                break; // sai do loop interno após um movimento completo
            }
            // Se não for a condição certa, ignora com continue
            continue;
        }

        if (movimentosFeitos > 0) {
            break; // se já fez um movimento, não precisa continuar
        }
    }
}

// Movimento do Bispo com loops aninhados (além da recursão)
void moverBispoComLoops(int casas) {
    printf("\nMovimento do Bispo (usando loops aninhados):\n");
    for (int linha = 1; linha <= casas; linha++) {
        for (int coluna = 1; coluna <= 1; coluna++) {
            printf("Cima Direita\n");
        }
    }
}

int main() {
    // Quantidade de passos de cada peça
    int passosTorre = 5;
    int passosBispo = 5;
    int passosRainha = 8;

    // -------------------------------
    // Movimento da Torre (recursivo)
    // -------------------------------
    printf("Movimento da Torre:\n");
    moverTorre(passosTorre);

    // -------------------------------
    // Movimento do Bispo (recursivo)
    // -------------------------------
    printf("\nMovimento do Bispo:\n");
    moverBispoRecursivo(passosBispo);

    // -------------------------------
    // Movimento da
