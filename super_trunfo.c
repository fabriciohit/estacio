#include <stdio.h>
#include <string.h>

int main() {
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // Leitura dos dados da Carta 1
    printf("\n=== Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("C\u00f3digo (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^"]", nomeCidade1);

    printf("Popula\u00e7\u00e3o: ");
    scanf("%lu", &populacao1);

    printf("\u00c1rea (em km\u00b2): ");
    scanf("%f", &area1);

    printf("PIB (em bilh\u00f5es): ");
    scanf("%f", &pib1);

    printf("N\u00famero de Pontos Tur\u00edsticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura dos dados da Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("C\u00f3digo (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^"]", nomeCidade2);

    printf("Popula\u00e7\u00e3o: ");
    scanf("%lu", &populacao2);

    printf("\u00c1rea (em km\u00b2): ");
    scanf("%f", &area2);

    printf("PIB (em bilh\u00f5es): ");
    scanf("%f", &pib2);

    printf("N\u00famero de Pontos Tur\u00edsticos: ");
    scanf("%d", &pontosTuristicos2);

    // C\u00e1lculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Menu de sele\u00e7\u00e3o de dois atributos
    int opcao1, opcao2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2, soma1, soma2;

    printf("\n=== Escolha dois atributos para comparar ===\n");
    printf("1 - Popula\u00e7\u00e3o\n");
    printf("2 - \u00c1rea\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Tur\u00edsticos\n");
    printf("5 - Densidade Demogr\u00e1fica\n");
    printf("6 - PIB per Capita\n");

    printf("Digite o n\u00famero do primeiro atributo: ");
    scanf("%d", &opcao1);

    do {
        printf("Digite o n\u00famero do segundo atributo (diferente do primeiro): ");
        scanf("%d", &opcao2);
        if (opcao2 == opcao1) printf("Atributo repetido. Escolha outro.\n");
    } while (opcao2 == opcao1);

    printf("\nComparando: %s (%c) vs %s (%c)\n", nomeCidade1, estado1, nomeCidade2, estado2);

    // Fun\u00e7\u00e3o auxiliar para extrair valor com base na op\u00e7\u00e3o
    auto get_valor = [&](int opcao, float *v1, float *v2) {
        switch (opcao) {
            case 1: *v1 = populacao1; *v2 = populacao2; break;
            case 2: *v1 = area1; *v2 = area2; break;
            case 3: *v1 = pib1; *v2 = pib2; break;
            case 4: *v1 = pontosTuristicos1; *v2 = pontosTuristicos2; break;
            case 5: *v1 = densidade1; *v2 = densidade2; break;
            case 6: *v1 = pibPerCapita1; *v2 = pibPerCapita2; break;
        }
    };

    get_valor(opcao1, &valor1_c1, &valor1_c2);
    get_valor(opcao2, &valor2_c1, &valor2_c2);

    // Impress\u00e3o dos atributos
    printf("\nAtributo 1: ");
    switch (opcao1) {
        case 1: printf("Popula\u00e7\u00e3o\n"); break;
        case 2: printf("\u00c1rea\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Tur\u00edsticos\n"); break;
        case 5: printf("Densidade Demogr\u00e1fica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%.2f vs %.2f\n", valor1_c1, valor1_c2);

    printf("Atributo 2: ");
    switch (opcao2) {
        case 1: printf("Popula\u00e7\u00e3o\n"); break;
        case 2: printf("\u00c1rea\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Tur\u00edsticos\n"); break;
        case 5: printf("Densidade Demogr\u00e1fica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%.2f vs %.2f\n", valor2_c1, valor2_c2);

    // Ajustar invers\u00e3o para densidade (menor \u00e9 melhor)
    valor1_c1 = (opcao1 == 5) ? -valor1_c1 : valor1_c1;
    valor1_c2 = (opcao1 == 5) ? -valor1_c2 : valor1_c2;
    valor2_c1 = (opcao2 == 5) ? -valor2_c1 : valor2_c1;
    valor2_c2 = (opcao2 == 5) ? -valor2_c2 : valor2_c2;

    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n%.2f (%s) vs %.2f (%s)\n", soma1, nomeCidade1, soma2, nomeCidade2);
    (soma1 > soma2) ? printf("%s venceu!\n", nomeCidade1) :
    (soma2 > soma1) ? printf("%s venceu!\n", nomeCidade2) :
                      printf("Empate!\n");

    return 0;
}
