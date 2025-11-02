#include <stdio.h>

int main() {
    // matriz 10x10 para representar o tabuleiro
    int tabuleiro[10][10];
    int i, j;
    
    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Declaração de vetores para representar os navios
    int navio1[3];
    int navio2[3];
    
    // Inicializa os vetores (atribui o valor 3 para cada posição)
    for (i = 0; i < 3; i++) {
        navio1[i] = 3;
        navio2[i] = 3;
    }
    
    // Coordenadas dos navios
    // Navio 1: Horizontal na linha 2, colunas 1, 2, 3
    int navio1_linha = 2;
    int navio1_coluna = 1;
    
    // Navio 2: Vertical nas linhas 5, 6, 7, coluna 7
    int navio2_linha = 5;
    int navio2_coluna = 7;
    
    // verifica se os navios estão dentro dos limites
    // Navio horizontal: verifica se coluna final está dentro do limite
    if (navio1_linha < 0 || navio1_linha >= 10 || navio1_coluna < 0 || navio1_coluna + 2 >= 10) {
        printf("ERRO: Navio 1 esta fora dos limites do tabuleiro!\n");
        return 1;
    }
    
    // Navio 2 vertical: verifica se linha final está dentro do limite
    if (navio2_linha < 0 || navio2_linha + 2 >= 10 || navio2_coluna < 0 || navio2_coluna >= 10) {
        printf("ERRO: Navio 2 esta fora dos limites do tabuleiro!\n");
        return 1;
    }
    
    // Posiciona o navio 1 horizontalmente no tabuleiro
    for (i = 0; i < 3; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = navio1[i];
    }
    
    // Posiciona o navio 2 verticalmente no tabuleiro
    for (i = 0; i < 3; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = navio2[i];
    }
    
    // Exibe o tabuleiro no console
    printf("Tabuleiro (0 = agua, 3 = navio):\n");
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%2d ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
