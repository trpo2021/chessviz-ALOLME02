#include "Move_pawn.h"
void assigment(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Setting_Field_x(str, 2);
    y1 = Setting_Field_y(str, 1);
    x2 = Setting_Field_x(str, 5);
    y2 = Setting_Field_y(str, 4);

    if (Pawn_Walk(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that\n Try again\n\n");
}

void attack_Pawn(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Setting_Field_x(str, 2);
    y1 = Setting_Field_y(str, 1);
    x2 = Setting_Field_x(str, 5);
    y2 = Setting_Field_y(str, 4);

    if (attack_Pawn_Border_check(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}

void Move_Pawn(Board* cl, char* str, int num)
{
    switch (str[3]) {
    case '-':
        if (whose(num)) {
            assigment(W_Pawn, cl, str);
        }
        if (!whose(num)) {
            assigment(B_Pawn, cl, str);
        }
        break;
    case '#':
        if (whose(num)) {
            if (color_attack_Pawn_White(cl, str)) {
                attack_Pawn(W_Pawn, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        if (!whose(num)) {
            if (color_attack_Pawn_Black(cl, str)) {
                attack_Pawn(B_Pawn, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        break;
    }
}