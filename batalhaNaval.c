#include <stdio.h>

int main() {
    // declara amatriz 10x10 para representar o tabuleiro
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
    int navio3[3];
    int navio4[3];
    
    // Inicializa os vetores (atribui o valor 3 para cada posição)
    for (i = 0; i < 3; i++) {
        navio1[i] = 3;
        navio2[i] = 3;
        navio3[i] = 3;
        navio4[i] = 3;
    }
    
    // Coordenadas dos navios
    // Navio 1: Horizontal na linha 3, colunas 4, 5, 6
    int navio1_linha = 3;
    int navio1_coluna = 4;
    
    // Navio 2: Vertical nas linhas 3, 4, 5, coluna 7
    int navio2_linha = 3;
    int navio2_coluna = 7;
    
    // Navio 3: Diagonal principal (linha e coluna aumentam juntos)
    // Posições: (1,1), (2,2), (3,3)
    int navio3_linha = 1;
    int navio3_coluna = 1;
    
    // Navio 4: Diagonal secundária (linha aumenta, coluna diminui)
    // Posições: (6,8), (7,7), (8,6)
    int navio4_linha = 6;
    int navio4_coluna = 8;
    
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
    
    // Navio 3 diagonal principal: verifica se linha e coluna finais estão dentro do limite
    if (navio3_linha < 0 || navio3_linha + 2 >= 10 || navio3_coluna < 0 || navio3_coluna + 2 >= 10) {
        printf("ERRO: Navio 3 esta fora dos limites do tabuleiro!\n");
        return 1;
    }
    
    // Navio 4 diagonal secundária: verifica se linha final e coluna final estão dentro do limite
    if (navio4_linha < 0 || navio4_linha + 2 >= 10 || navio4_coluna < 2 || navio4_coluna >= 10) {
        printf("ERRO: Navio 4 esta fora dos limites do tabuleiro!\n");
        return 1;
    }
    
    // Verifica sobreposição entre todos os navios
    // Compara diretamente as posições de cada par de navios
    // TODO: melhorar a lógica de verificação de sobreposição
    int linha_a, coluna_a, linha_b, coluna_b;
    
    // Navio 1 vs Navio 2
    for (i = 0; i < 3; i++) {
        linha_a = navio1_linha;
        coluna_a = navio1_coluna + i;
        for (j = 0; j < 3; j++) {
            linha_b = navio2_linha + j;
            coluna_b = navio2_coluna;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 1 e Navio 2 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Navio 1 vs Navio 3
    for (i = 0; i < 3; i++) {
        linha_a = navio1_linha;
        coluna_a = navio1_coluna + i;
        for (j = 0; j < 3; j++) {
            linha_b = navio3_linha + j;
            coluna_b = navio3_coluna + j;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 1 e Navio 3 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Navio 1 vs Navio 4
    for (i = 0; i < 3; i++) {
        linha_a = navio1_linha;
        coluna_a = navio1_coluna + i;
        for (j = 0; j < 3; j++) {
            linha_b = navio4_linha + j;
            coluna_b = navio4_coluna - j;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 1 e Navio 4 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Navio 2 vs Navio 3
    for (i = 0; i < 3; i++) {
        linha_a = navio2_linha + i;
        coluna_a = navio2_coluna;
        for (j = 0; j < 3; j++) {
            linha_b = navio3_linha + j;
            coluna_b = navio3_coluna + j;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 2 e Navio 3 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Navio 2 vs Navio 4
    for (i = 0; i < 3; i++) {
        linha_a = navio2_linha + i;
        coluna_a = navio2_coluna;
        for (j = 0; j < 3; j++) {
            linha_b = navio4_linha + j;
            coluna_b = navio4_coluna - j;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 2 e Navio 4 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Navio 3 vs Navio 4
    for (i = 0; i < 3; i++) {
        linha_a = navio3_linha + i;
        coluna_a = navio3_coluna + i;
        for (j = 0; j < 3; j++) {
            linha_b = navio4_linha + j;
            coluna_b = navio4_coluna - j;
            if (linha_a == linha_b && coluna_a == coluna_b) {
                printf("ERRO: Navio 3 e Navio 4 se sobrepoem!\n");
                return 1;
            }
        }
    }
    
    // Posiciona o navio 1 horizontalmente no tabuleiro
    for (i = 0; i < 3; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = navio1[i];
    }
    
    // Posiciona o navio 2 verticalmente no tabuleiro
    for (i = 0; i < 3; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = navio2[i];
    }
    
    // Posiciona o navio 3 diagonalmente
    for (i = 0; i < 3; i++) {
        tabuleiro[navio3_linha + i][navio3_coluna + i] = navio3[i];
    }
    
    // Posiciona o navio 4 diagonalmente (diagonal secundária)
    for (i = 0; i < 3; i++) {
        tabuleiro[navio4_linha + i][navio4_coluna - i] = navio4[i];
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
