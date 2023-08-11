#ifndef INPUT_H
#define INPUT_H

#include "gamestate.h"
#include "player.h"

typedef struct {
    int row;
    int col;
} BoardPosition;

typedef struct {
    BoardPosition src;
    BoardPosition dest;
} MoveInput;

MoveInput getPlayerMoveInput(const GameState* state, Player player);
MoveInput getAIMoveInput(const GameState* state, Player player);
MoveInput getNetworkMoveInput(const GameState* state, Player player);
MoveInput getGraphicalMoveInput(const GameState* state, Player player);
// Other input functions for different modes

#endif // INPUT_H
