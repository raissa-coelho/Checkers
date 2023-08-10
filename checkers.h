#ifndef CHECKERS_H
#define CHECKERS_H

#include "gamestate.h"

typedef enum {
    VALID_MOVE,
    INVALID_MOVE
} MoveResult;

MoveResult isValidMove(const GameState* state, Player player, int srcRow, int srcCol, int destRow, int destCol);
void makeMove(GameState* state, int srcRow, int srcCol, int destRow, int destCol);
void printBoard(Piece **board);
// Other game logic functions

#endif // CHECKERS_H
