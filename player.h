#ifndef PLAYER_H
#define PLAYER_H

#include "gamestate.h"
#include "checkers.h"
#include <stdlib.h>

typedef enum {
    NOT_VALID,
    NORMAL_MOVE,
    CAPTURE_MOVE,
    KING_PROMOTION
} MoveType;

// Check the type of a move (normal, capture, king promotion)
MoveType checkMoveType(const GameState* state, int srcRow, int srcCol, int destRow, int destCol);

// Check if a piece can capture an opponent's piece
int canCapture(const GameState* state, int row, int col, Player player);

// Perform a piece capture
void performCapture(GameState* state, int srcRow, int srcCol, int destRow, int destCol);

// Check if a piece is eligible for king promotion
int canPromote(const GameState* state, int row, int col, Player player);

// Promote a piece to a king
void promoteToKing(GameState* state, int row, int col);

#endif // PLAYER_H
