

#include <stdio.h>


#define TAMANHO_TABULEIRO 10 
#define AGUA 0              
#define NAVIO 3              
#define HABILIDADE 5         


#define TAMANHO_HABILIDADE_LINHA 5
#define TAMANHO_HABILIDADE_COLUNA 5


void criarHabilidadeCone(int matriz[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE_LINHA; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE_COLUNA; j++) {
            matriz[i][j] = AGUA; // Inicializa com água
        }
    }
    
    matriz[0][2] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[2][0] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;
    matriz[2][3] = 1;
    matriz[2][4] = 1;
}


void criarHabilidadeCruz(int matriz[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE_LINHA; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE_COLUNA; j++) {
            matriz[i][j] = AGUA; // Inicializa com água
        }
    }
   
    matriz[0][2] = 1;
    matriz[1][0] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[1][4] = 1;
    matriz[2][2] = 1;
}


void criarHabilidadeOctaedro(int matriz[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA]) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE_LINHA; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE_COLUNA; j++) {
            matriz[i][j] = AGUA; // Inicializa com água
        }
    }
   
    matriz[0][2] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[2][2] = 1;
}


void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA],
                        int origem_linha, int origem_coluna) {
    int i, j;
    for (i = 0; i < TAMANHO_HABILIDADE_LINHA; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE_COLUNA; j++) {
            
            int tab_linha = origem_linha + i - (TAMANHO_HABILIDADE_LINHA / 2);
            int tab_coluna = origem_coluna + j - (TAMANHO_HABILIDADE_COLUNA / 2);

            
            if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1) {
                
                if (tabuleiro[tab_linha][tab_coluna] != NAVIO) {
                    tabuleiro[tab_linha][tab_coluna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    int i, j;

    
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            tabuleiro[i][j] = AGUA;
        }
    }

    
    int navio1_linha = 2;
    int navio1_coluna = 3;

    
    int navio2_linha = 5;
    int navio2_coluna = 1;

    
    if (navio1_coluna + 3 <= TAMANHO_TABULEIRO) { 
        for (i = 0; i < 3; i++) { 
            tabuleiro[navio1_linha][navio1_coluna + i] = NAVIO; 
        }
    }

    
   
    if (navio2_linha + 3 <= TAMANHO_TABULEIRO) { 
        for (i = 0; i < 3; i++) {
            
            if (tabuleiro[navio2_linha + i][navio2_coluna] == AGUA) {
                tabuleiro[navio2_linha + i][navio2_coluna] = NAVIO; 
            }
        }
    }

    
    int habilidadeCone[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA];
    int habilidadeCruz[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA];
    int habilidadeOctaedro[TAMANHO_HABILIDADE_LINHA][TAMANHO_HABILIDADE_COLUNA];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    
    int origem_cone_linha = 1;
    int origem_cone_coluna = 1;

    int origem_cruz_linha = 7;
    int origem_cruz_coluna = 7;

    int origem_octaedro_linha = 4;
    int origem_octaedro_coluna = 4;

    // Sobrepõe as habilidades no tabuleiro
    sobreporHabilidade(tabuleiro, habilidadeCone, origem_cone_linha, origem_cone_coluna);
    sobreporHabilidade(tabuleiro, habilidadeCruz, origem_cruz_linha, origem_cruz_coluna);
    sobreporHabilidade(tabuleiro, habilidadeOctaedro, origem_octaedro_linha, origem_octaedro_coluna);

    
    printf("Tabuleiro de Batalha Naval:\n"); 

    
    printf("  "); 
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        
        printf("%2d ", i + 1); 
        
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0; 
}


