

#include <stdio.h>


#define TAMANHO_TABULEIRO 10 
#define AGUA 0               
#define NAVIO 3              

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


