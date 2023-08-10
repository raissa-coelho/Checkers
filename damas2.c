#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 8

struct Estado
{
    int board[SIZE][SIZE];
};

struct JogadaAI
{
    int linha;
    int coluna;
};

void makeBoard(struct Estado estado){
    int i,j;

    for ( i = 0; i < SIZE; i++){
        for(j =0; j < SIZE; j++){
            if((i+j)%2 == 0){
                if(i < 3){
                    estado.board[i][j] = 1;
                }else if(i > 4){
                    estado.board[i][j] = 2;
                }else{
                    estado.board[i][j] = 0;
                }
            }else{
                estado.board[i][j] = 0;
            }
        }
    }
    
}

void printBoard(struct Estado estado){
    int i,j;

    for ( i = 0; i < SIZE; i++){
        for(j =0; j < SIZE; j++){
            printf("%d", estado.board[i][j]);
            if (j != SIZE-1){
                printf("|");
            }
        }
        printf("\n");
    }
}

int jogadaPlayer(struct Estado jogo, int linha, int coluna, int paraLinha, int paraColuna){
    int i, j;
    if(paraLinha < 0 || paraColuna < 0 || paraLinha > SIZE || paraColuna > SIZE){
        return 0;
    }

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(jogo.board[linha][coluna] == 1 && jogo.board[paraLinha][paraColuna] == 0){
                if(jogo.board[linha+2][coluna+2] == 2 && linha+2 < 8 && coluna+2 < 8){
                    jogo.board[linha][coluna] == 0;
                    jogo.board[linha+2][coluna+2] == 0;
                    jogo.board[paraLinha][paraColuna] == 1;
                }else if(jogo.board[linha-2][coluna-2] == 2 && linha-2 > -1 && coluna-2 > -1){
                    jogo.board[linha][coluna] == 0;
                    jogo.board[linha-2][coluna-2] == 0;
                    jogo.board[paraLinha][paraColuna] == 1;
                }else if(jogo.board[paraLinha][paraColuna] == 0 && linha+1 == paraLinha && coluna+1 == paraColuna){
                    jogo.board[paraLinha][paraColuna] = 1;
                    jogo.board[linha][coluna] = 0;
                }else if(jogo.board[paraLinha][paraColuna] == 0 && linha+1 == paraLinha && coluna+1 == paraColuna){
                    jogo.board[paraLinha][paraColuna] = 1;
                    jogo.board[linha][coluna] = 0;
                }
            }
        }
    }
}

bool valido(struct Estado jogo, int linha, int coluna, int paraLinha, int paraColuna){
    int i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(jogo.board[linha][coluna] == 2 && jogo.board[paraLinha][paraColuna] == 0){
                if(jogo.board[linha+2][coluna+2] == 1 && linha+2 < 8 && coluna+2 < 8){
                   return true;
                }else if(jogo.board[linha-2][coluna-2] == 1 && linha-2 > -1 && coluna-2 > -1){
                    return true;
                }else if(jogo.board[paraLinha][paraColuna] == 0 && linha+1 == paraLinha && coluna+1 == paraColuna){
                    return true;
                }else if(jogo.board[paraLinha][paraColuna] == 0 && linha+1 == paraLinha && coluna+1 == paraColuna){
                    return true;
                }
            }
        }
    }
}

bool checkWinner(struct Estado jogo){
    int i, j;
    int count1, count2 = 0;
    bool win;

    for(i = 0; i < SIZE; i++){
        for(j = 0; j< SIZE; j++){
            if(jogo.board[i][j] == 1){
                count1++;
            }else if(jogo.board[i][j] == 2){
                count2++;
            }
        }
    }

    if(count1 == 0){
        win = true;
        printf("Player B has won.");
    }else if(count2 == 0){
        win = true;
        printf("Player A has won.");
    }else{
        win = false;
    }

    return win;
}

struct S achaMovimento(struct Estado jogo){
    int score = -9999;
    int aval;
    int i,j;
    int paraColuna, paraLinha;
    struct JogadaAI move;
    move.coluna = -1;
    move.linha = -1;

    for ( i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            for(paraLinha = 0; paraLinha < SIZE; paraLinha++){
                for(paraColuna = 0; paraColuna < SIZE; paraColuna++){
                    if(valido(jogo,i,j,paraLinha,paraColuna) == true){
                        struct Estado novo = jogo;
                        novo.board[i][j] = novo.board[paraLinha][paraColuna];
                        novo.board[paraLinha][paraColuna] = 0;
                        aval = minimax(novo);

                        if(aval > score){
                            score = aval;
                            move.linha = paraLinha;
                            move.coluna = paraColuna;
                        }
                    }
                }
            }
        }
    }
    
    return move;
}

int minimax(struct Estado jogo, int depth, ){

}

void main()
{
    struct Estado jogo;
    makeBoard(jogo);

    int linha,coluna, linha2,coluna2;
    bool win = false;
    int player = 2;

    do{    
        if(player == 1){
            scanf(" Peça Linha: %d\n", &linha);
            scanf(" Peça Coluna: %d\n", &coluna);
            scanf(" Para Linha: %d\n", &linha2);
            scanf(" Para Coluna: %d\n", &coluna2);
            jogadaPlayer(jogo,linha,coluna, linha2, coluna2);
            printBoard(jogo);
            win = checkWinner(jogo);
            if(win == true){
                player = 0;
            }else{
                player = 2;
            }
       }else{
            struct JogadaAI jogada;
            printf("Hello");
            jogada = achaMovimento(jogo);
            win = checkWinner(jogo);
            if(win == true){
                player = 0;
            }else{
                player = 1;
            }
        }
    }while(player != 0);

}