#include "Move_King.h"

void King_Walk(Piece num, Board* cl, char* str)
{
    int x1;
    x1 = Seting_Field_x(str);
    int y1;
    y1 = Seting_Field_y(str);
    int x2;
    x2 = Seting_Field_x2(str);
    int y2;
    y2 = Seting_Field_y2(str);
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