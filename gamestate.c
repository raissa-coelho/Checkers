//
// Created by Matheus S. Menezes on 10/08/2023.
//

#include "gamestate.h"

void initializeGameState(GameState* state, Player initial_player) {
    // Clear the board and set initial positions
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                state->board[i][j] = EMPTY;
            } else if (i < 3) {
                state->board[i][j] = BLACK_PIECE;
            } else if (i > 4) {
                state->board[i][j] = WHITE_PIECE;
            } else {
                state->board[i][j] = EMPTY;
            }
        }
    }

    // Set player turns
    state->currentPlayer = initial_player;

    // Initialize other fields
    state->selectedPiece.row = -1;
    state->selectedPiece.col = -1;
    state->numBlackKings = 0;
    state->numWhiteKings = 0;
    state->numCapturedBlackPieces = 0;
    state->numCapturedWhitePieces = 0;
    state->gameOver = 0;
    state->winner = TEAPOT;
    state->actionList = NULL;
}