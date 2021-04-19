#include "Move_Rook.h"
void Rook_Walk(Piece num, Board* cl, char* str)
{
    int x1;
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

    int x2;
    int y2;
    if (str[4] == 'a')
        y2 = 0;
    if (str[4] == 'b')
        y2 = 1;
    if (str[4] == 'c')
        y2 = 2;
    if (str[4] == 'd')
        y2 = 3;
    if (str[4] == 'e')
        y2 = 4;
    if (str[4] == 'f')
        y2 = 5;
    if (str[4] == 'g')
        y2 = 6;
    if (str[4] == 'h')
        y2 = 7;

    if (str[5] == '1')
        x2 = 7;
    if (str[5] == '2')
        x2 = 6;
    if (str[5] == '3')
        x2 = 5;
    if (str[5] == '4')
        x2 = 4;
    if (str[5] == '5')
        x2 = 3;
    if (str[5] == '6')
        x2 = 2;
    if (str[5] == '7')
        x2 = 1;
    if (str[5] == '8')
        x2 = 0;
    if (Verific_Rook(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}
void Move_Rook(Board* cl, char* str, int num)
{
    switch (str[3]) {
    case '-':
        if (whose(num)) {
            Rook_Walk(W_Rook, cl, str);
        }
        if (!whose(num)) {
            Rook_Walk(B_Rook, cl, str);
        }
        break;
    case '#':
        if (whose(num)) {
            if (color_attack_Pawn_White(cl, str)) {
                Rook_Walk(W_Rook, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        if (!whose(num)) {
            if (color_attack_Pawn_Black(cl, str)) {
                Rook_Walk(B_Rook, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        break;
    }
}