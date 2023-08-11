#ifndef CHECKERS_H
#define CHECKERS_H

#include "gamestate.h"
#include <omp.h>

typedef enum {
    VALID_MOVE,
    INVALID_MOVE
} MoveResult;

MoveResult isValidMove(const GameState* state, Player player, int srcRow, int srcCol, int destRow, int destCol);
void makeMove(GameState* state, int srcRow, int srcCol, int destRow, int destCol);
void printBoard(Piece **board);
Player checkWinner(const GameState* state);

// Other game logic functions

#endif // CHECKERS_H
