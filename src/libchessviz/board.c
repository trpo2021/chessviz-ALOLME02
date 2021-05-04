#include "board.h"
void Visual_Board(Board* cl)
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
void Print_Board(Board* cl)
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
int Setting_Field_x(char* str)
{
    int x1;
    if (str[2] == '1')
        x1 = 7;
    if (str[2] == '2')
        x1 = 6;
    if (str[2] == '3')
        x1 = 5;
    if (str[2] == '4')
        x1 = 4;
    if (str[2] == '5')
        x1 = 3;
    if (str[2] == '6')
        x1 = 2;
    if (str[2] == '7')
        x1 = 1;
    if (str[2] == '8')
        x1 = 0;
    return x1;
}
int Setting_Field_y(char* str)
{
    int y1;
    if (str[1] == 'a')
        y1 = 0;
    if (str[1] == 'b')
        y1 = 1;
    if (str[1] == 'c')
        y1 = 2;
    if (str[1] == 'd')
        y1 = 3;
    if (str[1] == 'e')
        y1 = 4;
    if (str[1] == 'f')
        y1 = 5;
    if (str[1] == 'g')
        y1 = 6;
    if (str[1] == 'h')
        y1 = 7;
    return y1;
}
int Setting_Field_x2(char* str)
{
    int x2;
    if (str[2] == '1')
        x2 = 7;
    if (str[2] == '2')
        x2 = 6;
    if (str[2] == '3')
        x2 = 5;
    if (str[2] == '4')
        x2 = 4;
    if (str[2] == '5')
        x2 = 3;
    if (str[2] == '6')
        x2 = 2;
    if (str[2] == '7')
        x2 = 1;
    if (str[2] == '8')
        x2 = 0;
    return x2;
}
int Setting_Field_y2(char* str)
{
    int y2;
    if (str[1] == 'a')
        y2 = 0;
    if (str[1] == 'b')
        y2 = 1;
    if (str[1] == 'c')
        y2 = 2;
    if (str[1] == 'd')
        y2 = 3;
    if (str[1] == 'e')
        y2 = 4;
    if (str[1] == 'f')
        y2 = 5;
    if (str[1] == 'g')
        y2 = 6;
    if (str[1] == 'h')
        y2 = 7;
    return y2;
}
Piece point_before_move(Board* cl, char* str)
{
    int x1;
    x1 = Setting_Field_x(str);
    int y1;
    y1 = Setting_Field_y(str);

    return cl->board[x1][y1];
}
Piece point_after_move(Board* cl, char* str)
{
    int x2;
    x2 = Setting_Field_x2(str);
    int y2;
    y2 = Setting_Field_y2(str);

    return cl->board[x2][y2];
}