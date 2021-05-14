#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

typedef enum {
    None = ' ',
    W_King = 'K',
    W_Queen = 'Q',
    W_Rook = 'R',
    W_Knight = 'K',
    W_Bishop = 'B',
    W_Pawn = 'P',
    B_King = 'k',
    B_Queen = 'q',
    B_Rook = 'r',
    B_Knight = 'n',
    B_Bishop = 'b',
    B_Pawn = 'p'
} Piece;

typedef struct {
    Piece board[8][8];
} Board;
#endif