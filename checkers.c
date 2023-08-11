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

Player checkWinner(const GameState* state) {
    int blackCount = 0;
    int whiteCount = 0;

#pragma omp parallel for reduction(+:blackCount, whiteCount)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == BLACK_PIECE || state->board[i][j] == BLACK_KING) {
                blackCount++;
            } else if (state->board[i][j] == WHITE_PIECE || state->board[i][j] == WHITE_KING) {
                whiteCount++;
            }
        }
    }

    if (blackCount == 0) {
        return WHITE_PLAYER; // White player wins
    } else if (whiteCount == 0) {
        return BLACK_PLAYER; // Black player wins
    }

    return TEAPOT; // No winner yet
}


MoveResult isValidMove(const GameState* state, Player player, int srcRow, int srcCol, int destRow, int destCol) {
    // Check if the source and destination are within bounds
    if (srcRow < 0 || srcRow >= BOARD_SIZE || srcCol < 0 || srcCol >= BOARD_SIZE ||
        destRow < 0 || destRow >= BOARD_SIZE || destCol < 0 || destCol >= BOARD_SIZE) {
        return INVALID_MOVE;
    }

    // Check if the destination is a valid empty tile
    if (state->board[destRow][destCol] != EMPTY) {
        return INVALID_MOVE;
    }

    // Check if the move is diagonal (abs value of row and col difference should be equal)
    int rowDiff = abs(destRow - srcRow);
    int colDiff = abs(destCol - srcCol);
    if (rowDiff != colDiff) {
        return INVALID_MOVE;
    }

    // Check if the piece being moved belongs to the current player
    Piece playerPiece = (player == BLACK_PLAYER) ? BLACK_PIECE : WHITE_PIECE;
    if (state->board[srcRow][srcCol] != playerPiece) {
        return INVALID_MOVE;
    }

    // Check if the move direction is correct based on player
    if (rowDiff != 1 && rowDiff != 2) {
        return INVALID_MOVE;
    }
    if (rowDiff == 2 && colDiff == 2) {
        // Capture move, check if there's an opponent's piece in between
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        Piece opponentPiece = (player == BLACK_PLAYER) ? WHITE_PIECE : BLACK_PIECE;
        if (state->board[midRow][midCol] != opponentPiece) {
            return INVALID_MOVE;
        }
    }

    return VALID_MOVE;
}




