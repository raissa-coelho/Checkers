//
// Created by Matheus S. Menezes on 10/08/2023.
//

#include "player.h"

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

MoveType checkMoveType(const GameState* state, int srcRow, int srcCol, int destRow, int destCol) {
    // Determine move type based on the move's validity
    MoveResult result = isValidMove(state, state->currentPlayer, srcRow, srcCol, destRow, destCol);
    if (result == INVALID_MOVE) {
        return NOT_VALID;
    }

    int rowDiff = abs(destRow - srcRow);

    if (rowDiff == 2) {
        return CAPTURE_MOVE;
    } else if (canPromote(state, srcRow, srcCol, state->currentPlayer)) {
        return KING_PROMOTION;
    } else {
        return NORMAL_MOVE;
    }
}

int canCapture(const GameState* state, int row, int col, Player player) {
    // Check if the given piece can capture an opponent's piece
    Piece opponentPiece = (player == BLACK_PLAYER) ? WHITE_PIECE : BLACK_PIECE;

    // Check if there's an opponent's piece diagonally in the forward direction
    int forwardDir = (player == BLACK_PLAYER) ? 1 : -1;
    if (row + forwardDir < 0 || row + forwardDir >= BOARD_SIZE ||
        col - 1 < 0 || col + 1 >= BOARD_SIZE) {
        return 0;
    }

    if (state->board[row + forwardDir][col - 1] == opponentPiece ||
        state->board[row + forwardDir][col + 1] == opponentPiece) {
        return 1;
    }

    return 0;
}

void performCapture(GameState* state, int srcRow, int srcCol, int destRow, int destCol) {
    // Perform the capture by removing the opponent's piece
    int midRow = (srcRow + destRow) / 2;
    int midCol = (srcCol + destCol) / 2;
    state->board[midRow][midCol] = EMPTY;
}

int canPromote(const GameState* state, int row, int col, Player player) {
    // Check if the piece is eligible for king promotion
    if (player == BLACK_PLAYER && row == BOARD_SIZE - 1) {
        return 1;
    } else if (player == WHITE_PLAYER && row == 0) {
        return 1;
    }
    return 0;
}

void promoteToKing(GameState* state, int row, int col) {
    // Promote the piece to a king
    if (state->board[row][col] == BLACK_PIECE) {
        state->board[row][col] = BLACK_KING;
    } else if (state->board[row][col] == WHITE_PIECE) {
        state->board[row][col] = WHITE_KING;
    }
}

void movePiece(GameState* state, int srcRow, int srcCol, int destRow, int destCol) {
    // Move the piece to the destination and handle promotions and captures
    state->board[destRow][destCol] = state->board[srcRow][srcCol];
    state->board[srcRow][srcCol] = EMPTY;

    // Handle capture if applicable
    if (abs(destRow - srcRow) == 2) {
        int midRow = (srcRow + destRow) / 2;
        int midCol = (srcCol + destCol) / 2;
        state->board[midRow][midCol] = EMPTY;
    }

    // Handle promotions if applicable
    if (canPromote(state, destRow, destCol, state->currentPlayer)) {
        promoteToKing(state, destRow, destCol);
    }

    // Update the current player
    state->currentPlayer = (state->currentPlayer == BLACK_PLAYER) ? WHITE_PLAYER : BLACK_PLAYER;
}

int playerMove(GameState* state, int line, int column, int destLine, int destCol) {
    if (destLine < 0 || destCol < 0 || destLine >= BOARD_SIZE || destCol >= BOARD_SIZE) {
        return 0;
    }

    MoveResult moveResult = isValidMove(state, state->currentPlayer, line, column, destLine, destCol);

    if (moveResult == VALID_MOVE) {
        makeMove(state, line, column, destLine, destCol);
        return 1;
    }


    return 0;
}
