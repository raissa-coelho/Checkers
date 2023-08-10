#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "player.h"
#include <stdio.h>

#define BOARD_SIZE 8
#define MAX_KINGS 12
#define MAX_CAPTURED_PIECES 12

typedef enum {
    EMPTY,
    BLACK_PIECE,
    WHITE_PIECE,
    BLACK_KING,
    WHITE_KING
} Piece;

typedef enum {
    BLACK_PLAYER,
    WHITE_PLAYER,
    TEAPOT
} Player;

typedef struct {
    int row;
    int col;
} PiecePosition;

typedef struct ActionNode {
    int player;  // Player making the move (BLACK_PLAYER or WHITE_PLAYER)
    MoveType moveType;  // Type of move (NORMAL_MOVE, CAPTURE_MOVE, KING_PROMOTION)
    PiecePosition srcPosition;  // Source position of the move
    PiecePosition destPosition;  // Destination position of the move
    struct ActionNode* next;  // Pointer to the next action in the linked list
} ActionNode;

typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    Player currentPlayer;
    PiecePosition selectedPiece;
    PiecePosition blackKings[MAX_KINGS];
    PiecePosition whiteKings[MAX_KINGS];
    int numBlackKings;
    int numWhiteKings;
    PiecePosition capturedBlackPieces[MAX_CAPTURED_PIECES];
    PiecePosition capturedWhitePieces[MAX_CAPTURED_PIECES];
    int numCapturedBlackPieces;
    int numCapturedWhitePieces;
    int gameOver;
    Player winner;
    ActionNode* actionList;  // Pointer to the head of the action linked list
} GameState;

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


#endif // GAMESTATE_H
