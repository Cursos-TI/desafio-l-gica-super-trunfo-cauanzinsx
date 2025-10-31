#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[50];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePop;
    float pibPerCapita;
} Carta;

// Função para calcular os atributos derivados
void calcularAtributos(Carta *carta) {
    carta->densidadePop = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta) {
    printf("\n--- Carta %s (%s) ---\n", carta.cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidadePop);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
}

// Função para comparar um único atributo (nível novato)
void compararAtributoUnico(Carta c1, Carta c2) {
    printf("\n===== COMPARAÇÃO (Nível Novato) =====\n");
    printf("Atributo escolhido: População\n");

    printf("%s: %d habitantes\n", c1.cidade, c1.populacao);
    printf("%s: %d habitantes\n", c2.cidade, c2.populacao);

    if (c1.populacao > c2.populacao)
        printf("Resultado: %s venceu!\n", c1.cidade);
    else if (c2.populacao > c1.populacao)
        printf("Resultado: %s venceu!\n", c2.cidade);
    else
        printf("Resultado: Empate!\n");
}

// Função para exibir o menu e retornar a escolha do atributo
int menuAtributos(int ignorar) {
    int opcao;
    printf("\nEscolha um atributo para comparação:\n");
    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Densidade Populacional\n");
    if (ignorar != 5) printf("5 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para obter o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidadePop;
        case 5: return c.pibPerCapita;
        default: return 0;
    }
}

// Função principal de comparação (nível mestre)
void compararDoisAtributos(Carta c1, Carta c2) {
    int atr1, atr2;
    printf("\n===== COMPARAÇÃO (Nível Mestre) =====\n");

    atr1 = menuAtributos(0);
    atr2 = menuAtributos(atr1);

    float valor1A1 = obterValorAtributo(c1, atr1);
    float valor1A2 = obterValorAtributo(c1, atr2);
    float valor2A1 = obterValorAtributo(c2, atr1);
    float valor2A2 = obterValorAtributo(c2, atr2);

    // Regra da densidade: menor vence
    int resultado1 = (atr1 == 4) ? (valor1A1 < valor2A1) : (valor1A1 > valor2A1);
    int resultado2 = (atr2 == 4) ? (valor1A2 < valor2A2) : (valor1A2 > valor2A2);

    float soma1 = valor1A1 + valor1A2;
    float soma2 = valor2A1 + valor2A2;

    printf("\nAtributo 1: ");
    switch (atr1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Populacional\n"); break;
        case 5: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", c1.cidade, valor1A1, c2.cidade, valor2A1);

    printf("\nAtributo 2: ");
    switch (atr2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Populacional\n"); break;
        case 5: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", c1.cidade, valor1A2, c2.cidade, valor2A2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", c1.cidade, soma1);
    printf("%s: %.2f\n", c2.cidade, soma2);

    if (soma1 > soma2)
        printf("\nResultado Final: %s venceu!\n", c1.cidade);
    else if (soma2 > soma1)
        printf("\nResultado Final: %s venceu!\n", c2.cidade);
    else
        printf("\nResultado Final: Empate!\n");
}

int main() {
    // Cadastro das cartas
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.0, 699.0, 50};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6748000, 1182.0, 364.0, 40};

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    printf("===== SUPER TRUNFO - BRASIL =====\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Nível Novato
    compararAtributoUnico(carta1, carta2);

    // Nível Mestre
    compararDoisAtributos(carta1, carta2);

    return 0;
}
