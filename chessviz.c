#include <stdio.h>
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

void Visual_Board(Board *cl) 
{
    cl->board[0][0] = W_Rook;
    cl->board[0][1] = W_Knight;
    cl->board[0][2] = W_Bishop;
    cl->board[0][3] = W_Queen;
    cl->board[0][4] = W_King;
    cl->board[0][5] = W_Bishop;
    cl->board[0][6] = W_Knight;
    cl->board[0][7] = W_Rook;
    for (int i = 0; i < 8; ++i) {
        cl->board[1][i] = W_Pawn;
  }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; ++j)
            cl->board[i][j] = None;
  }
    for (int i = 0; i < 8; ++i) {
        cl->board[6][i] = B_Pawn;
  }

    cl->board[7][0] = B_Rook;
    cl->board[7][1] = B_Knight;
    cl->board[7][2] = B_Bishop;
    cl->board[7][3] = B_Queen;
    cl->board[7][4] = B_King;
    cl->board[7][5] = B_Bishop;
    cl->board[7][6] = B_Knight;
    cl->board[7][7] = B_Rook;
}
void Print_Board(Board *cl) 
{ 
    int count = 9;
    for (int i = 0; i < 8; ++i, putchar('\n')) {
        printf("%d", count - 1);
            for (int j = 0; j < 8; ++j) {
                printf("%c", cl->board[i][j]);
    }
            count--;
  }
    printf(" abcdefgh\t");
}


int main() 
{
    Board Board;
    Visual_Board(&Board);
    Print_Board(&Board);
    return 0;
}

