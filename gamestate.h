#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "player.h"
#include <stdio.h>

#define BOARD_SIZE 8
#define MAX_KINGS 12
#define MAX_CAPTURED_PIECES 12

// Enumeration of possible piece types on the board
typedef enum {
    EMPTY,
    BLACK_PIECE,
    WHITE_PIECE,
    BLACK_KING,
    WHITE_KING
} Piece;

// Enumeration of possible players
typedef enum {
    BLACK_PLAYER,
    WHITE_PLAYER,
    TEAPOT
} Player;

// Structure to represent the position of a piece on the board
typedef struct {
    int row;
    int col;
} PiecePosition;

// Structure to represent an action node in the linked list of actions
typedef struct ActionNode {
    int player;  // Player making the move (BLACK_PLAYER or WHITE_PLAYER)
    MoveType moveType;  // Type of move (NORMAL_MOVE, CAPTURE_MOVE, KING_PROMOTION)
    PiecePosition srcPosition;  // Source position of the move
    PiecePosition destPosition;  // Destination position of the move
    struct ActionNode* next;  // Pointer to the next action in the linked list
} ActionNode;

// Structure to represent the game state
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

// Initialize the game state with initial player and setup the board
void initializeGameState(GameState* state, Player initial_player);

#endif // GAMESTATE_H
