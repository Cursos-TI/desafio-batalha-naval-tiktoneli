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
    
    // Cria matrizes de habilidade (3x5 cada)
    int cone[3][5];
    int cruz[3][5];
    int octaedro[3][5];
    
    // Constrói matriz do Cone
    // Formato: pequeno no topo, expandindo para baixo
    // Matriz 3x5: centro na [linha 1, coluna 2]
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int centro_coluna = 2; // centro da coluna na matriz 3x5
            int distancia_centro = (j > centro_coluna) ? (j - centro_coluna) : (centro_coluna - j);
            
            // Cone: expande conforme a linha aumenta
            // Linha 0: apenas centro (distância 0)
            // Linha 1: centro ± 1
            // Linha 2: centro ± 2 (máximo para formar base do cone)
            if (distancia_centro <= i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
    
    // Constrói matriz da Cruz (origem no centro)
    // Centro na linha 1, coluna 2
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int centro_linha = 1; // centro da linha
            int centro_coluna = 2; // centro da coluna

            if (i == centro_linha || j == centro_coluna) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
    
    // Constrói matriz do Octaedro (losango)
    // Formato: linha 0: apenas centro, linha 1: centro ± 1, linha 2: apenas centro
    // Centro na linha 1, coluna 2
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int centro_linha = 1;
            int centro_coluna = 2;
            int distancia_centro_linha = (i > centro_linha) ? (i - centro_linha) : (centro_linha - i);
            int distancia_centro_coluna = (j > centro_coluna) ? (j - centro_coluna) : (centro_coluna - j);
            int distancia_centro = distancia_centro_linha + distancia_centro_coluna;
            
            // Losango: distância <= 1 (forma losango menor)
            // Linha 0: distância <= 1 (mas só centro, então <= 0)
            // Linha 1: distância <= 1 (colunas 1, 2, 3)
            // Linha 2: distância <= 1 (mas só centro, então <= 0)
            if (distancia_centro <= 1) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
    
    // Cria matriz separada para exibir as habilidades
    int tabuleiro_habilidades[10][10];
    
    // Inicializa a matriz de habilidades com 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro_habilidades[i][j] = 0;
        }
    }
    
    // Define pontos de origem para cada habilidade no tabuleiro
    int cone_origem_linha = 1;
    int cone_origem_coluna = 2;
    
    int cruz_origem_linha = 4;
    int cruz_origem_coluna = 4;
    
    int octaedro_origem_linha = 7;
    int octaedro_origem_coluna = 6;
    
    // Aplica habilidade Cone na matriz de habilidades
    // Centro da matriz de habilidade (1,2) é posicionado na origem
    int offset_linha, offset_coluna;
    int tab_linha, tab_coluna;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                // Calcula offset relativo ao centro da matriz (1,2)
                offset_linha = i - 1;
                offset_coluna = j - 2;
                
                // Calcula posição no tabuleiro
                tab_linha = cone_origem_linha + offset_linha;
                tab_coluna = cone_origem_coluna + offset_coluna;
                
                // Verifica se está dentro dos limites do tabuleiro
                if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                    tabuleiro_habilidades[tab_linha][tab_coluna] = 1; // Cone = 1
                }
            }
        }
    }
    
    // Aplica habilidade Cruz na matriz de habilidades
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                offset_linha = i - 1;
                offset_coluna = j - 2;
                
                tab_linha = cruz_origem_linha + offset_linha;
                tab_coluna = cruz_origem_coluna + offset_coluna;
                
                if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                    tabuleiro_habilidades[tab_linha][tab_coluna] = 2; // Cruz = 2
                }
            }
        }
    }
    
    // Aplica habilidade Octaedro na matriz de habilidades
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                offset_linha = i - 1;
                offset_coluna = j - 2;
                
                tab_linha = octaedro_origem_linha + offset_linha;
                tab_coluna = octaedro_origem_coluna + offset_coluna;
                
                if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                    tabuleiro_habilidades[tab_linha][tab_coluna] = 3; // Octaedro = 3
                }
            }
        }
    }
    
    // Exibe o tabuleiro com navios
    printf("Tabuleiro com Navios (0 = agua, 3 = navio):\n");
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
    
    // Exibe o tabuleiro com habilidades
    printf("\nTabuleiro com Habilidades (0 = agua, 1 = Cone, 2 = Cruz, 3 = Octaedro):\n");
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%2d ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro_habilidades[i][j]);
        }
        printf("\n");
    }

    return 0;
}
