#include <stdio.h>

int main() {
    int tabuleiro[10][10];  
    int i, j;

   
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

   
    int linhaNavioH = 2, colunaNavioH = 4; 
    int linhaNavioV = 5, colunaNavioV = 7; 
    int tamanhoNavio = 3;

   
    if (colunaNavioH + tamanhoNavio <= 10) {
        for (j = colunaNavioH; j < colunaNavioH + tamanhoNavio; j++) {
            tabuleiro[linhaNavioH][j] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

   
    if (linhaNavioV + tamanhoNavio <= 10) {
        for (i = linhaNavioV; i < linhaNavioV + tamanhoNavio; i++) {
            if (tabuleiro[i][colunaNavioV] == 3) {
                printf("Erro: sobreposição detectada no navio vertical!\n");
                return 1;
            }
        }
        for (i = linhaNavioV; i < linhaNavioV + tamanhoNavio; i++) {
            tabuleiro[i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");


    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
