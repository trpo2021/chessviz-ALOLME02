#include "Move_Knight.h"

void Knight_Walk(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Seting_Field_x(str);
    y1 = Seting_Field_y(str);
    x2 = Seting_Field_x2(str);
    y2 = Seting_Field_y2(str);
    if (Verific_Knight(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}
void Knight_Attack(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Seting_Field_x(str);
    y1 = Seting_Field_y(str);
    x2 = Seting_Field_x2(str);
    y2 = Seting_Field_y2(str);
    if (Verific_Knight(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}
void Move_Knight(Board* cl, char* str, int num)
{
    switch (str[3]) {
    case '-':
        if (whose(num)) {
            Knight_Walk(W_Knight, cl, str);
        }
        if (!whose(num)) {
            Knight_Walk(B_Knight, cl, str);
        }
        break;
    case '#':
        if (whose(num)) {
            if (color_attack_Pawn_White(cl, str)) {
                Knight_Attack(W_Knight, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        if (!whose(num)) {
            if (color_attack_Pawn_Black(cl, str)) {
                Knight_Attack(B_Knight, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        break;
    }
}