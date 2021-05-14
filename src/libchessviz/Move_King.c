#include "Move_King.h"

void King_Walk(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Setting_Field_x(str, 2);
    y1 = Setting_Field_y(str, 1);
    x2 = Setting_Field_x(str, 5);
    y2 = Setting_Field_y(str, 4);
    if (Verific_King(cl, str, y1, y2, x1, x2)) {
        if ((cl->board[x2][y2] != B_King) && (cl->board[x2][y2] != W_King))
            cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}

void Move_King(Board* cl, char* str, int num)
{
    switch (str[3]) {
    case '-':
        if (whose(num)) {
            King_Walk(W_King, cl, str);
        }
        if (!whose(num)) {
            King_Walk(B_King, cl, str);
        }
        break;
    case '#':
        if (whose(num)) {
            if (color_attack_Pawn_White(cl, str)) {
                King_Walk(W_King, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        if (!whose(num)) {
            if (color_attack_Pawn_Black(cl, str)) {
                King_Walk(B_King, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        break;
    }
}