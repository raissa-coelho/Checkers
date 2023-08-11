//
// Created by Matheus S. Menezes on 10/08/2023.
//

#include "gamelogic.h"

MoveInput getAIMoveInput(const GameState* state, Player player) {
    MoveInput move;

    do {
        // Generate random moves within the board boundaries
        move.src.row = rand() % BOARD_SIZE;
        move.src.col = rand() % BOARD_SIZE;
        move.dest.row = rand() % BOARD_SIZE;
        move.dest.col = rand() % BOARD_SIZE;
    } while (!isValidMove(state, player, move.src.row, move.src.col, move.dest.row, move.dest.col));

    return move;
}


MoveInput getPlayerMoveInput(const GameState* state, Player player) {
    MoveInput move;

    do {
        printf("Player %c's turn.\n", (player == BLACK_PLAYER) ? 'B' : 'W');
        printf("Enter source position (row col): ");
        scanf("%d %d", &move.src.row, &move.src.col);

        printf("Enter destination position (row col): ");
        scanf("%d %d", &move.dest.row, &move.dest.col);
    } while (!isValidMove(state, player, move.src.row, move.src.col, move.dest.row, move.dest.col));

    return move;
}

