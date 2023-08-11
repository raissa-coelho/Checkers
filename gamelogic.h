//
// Created by Matheus S. Menezes on 10/08/2023.
//

#ifndef CHECKERS_GAMELOGIC_H
#define CHECKERS_GAMELOGIC_H

#define BOARD_SIZE 8
#define MAX_KINGS 12
#define MAX_CAPTURED_PIECES 12

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    VALID_MOVE,
    INVALID_MOVE
} MoveResult;

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

typedef struct {
    int row;
    int col;
} BoardPosition;

typedef struct {
    BoardPosition src;
    BoardPosition dest;
} MoveInput;

typedef enum {
    NOT_VALID,
    NORMAL_MOVE,
    CAPTURE_MOVE,
    KING_PROMOTION
} MoveType;

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
    Piece **board;
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

MoveResult isValidMove(const GameState* state, Player player, int srcRow, int srcCol, int destRow, int destCol);
void makeMove(GameState* state, int srcRow, int srcCol, int destRow, int destCol);
void printBoard(Piece **board);
Player checkWinner(const GameState* state);

MoveInput getPlayerMoveInput(const GameState* state, Player player);
MoveInput getAIMoveInput(const GameState* state, Player player);
MoveInput getNetworkMoveInput(const GameState* state, Player player);
MoveInput getGraphicalMoveInput(const GameState* state, Player player);
// Other input functions for different modes

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

#endif //CHECKERS_GAMELOGIC_H
