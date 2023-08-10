//
// Created by Matheus S. Menezes on 10/08/2023.
//

#include "checkers.h"


void printBoard(Piece **board) {
    static const char pieceSymbols[] = " bBwW ";
    static const char separator[] = "----";

    printf("   ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%c%s", 'A' + j, separator);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char p = pieceSymbols[board[i][j]];
            printf("| %c ", p);
        }
        printf("|\n");
        printf("   ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%s", separator);
        }
        printf("\n");
    }
}

void makeMove(GameState* state, int srcRow, int srcCol, int destRow, int destCol) {
    Piece (*board)[BOARD_SIZE] = state->board;

    // Get the type of move
    MoveType moveType = checkMoveType(state, srcRow, srcCol, destRow, destCol);

    if (moveType == CAPTURE_MOVE) {
        // Perform piece capture
        performCapture(state, srcRow, srcCol, destRow, destCol);
    } else {
        // Perform a normal move
        board[destRow][destCol] = board[srcRow][srcCol];
        board[srcRow][srcCol] = EMPTY;
    }

    // Check for king promotion
    int player = (board[destRow][destCol] == BLACK_PIECE || board[destRow][destCol] == BLACK_KING)
                 ? BLACK_PLAYER
                 : WHITE_PLAYER;

    if (canPromote(state, destRow, destCol, player)) {
        promoteToKing(state, destRow, destCol);
    }

    // Update player turn
    state->currentPlayer = (state->currentPlayer == BLACK_PLAYER) ? WHITE_PLAYER : BLACK_PLAYER;

    // Create a new action node
    ActionNode* newAction = (ActionNode*)malloc(sizeof(ActionNode));
    newAction->player = state->currentPlayer;
    newAction->moveType = moveType;
    newAction->srcPosition.row = srcRow;
    newAction->srcPosition.col = srcCol;
    newAction->destPosition.row = destRow;
    newAction->destPosition.col = destCol;
    newAction->next = NULL;

    // Append the new action node to the action list
    if (state->actionList == NULL) {
        state->actionList = newAction;
    } else {
        ActionNode* current = state->actionList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAction;
    }
}


