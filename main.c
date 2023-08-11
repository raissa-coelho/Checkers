#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamelogic.h"

int main() {
    srand(time(NULL)); // Seed the random number generator

    GameState gameState;
    initializeGameState(&gameState, BLACK_PLAYER);

    Player winner = TEAPOT; // Initialize winner to an initial value

    while (winner == TEAPOT) {
        printBoard(gameState.board);

        if (gameState.currentPlayer == BLACK_PLAYER) {
            MoveInput move = getPlayerMoveInput(&gameState, BLACK_PLAYER);
            makeMove(&gameState, move.src.row, move.src.col, move.dest.row, move.dest.col);
        } else {
            MoveInput move = getAIMoveInput(&gameState, WHITE_PLAYER);
            makeMove(&gameState, move.src.row, move.src.col, move.dest.row, move.dest.col);
        }

        winner = checkWinner(&gameState);
    }

    if (winner == BLACK_PLAYER) {
        printf("Black player wins!\n");
    } else if (winner == WHITE_PLAYER) {
        printf("White player wins!\n");
    }

    return 0;
}
