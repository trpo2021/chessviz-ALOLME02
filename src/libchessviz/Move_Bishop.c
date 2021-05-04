#include "Move_Bishop.h"

void Bishop_Walk(Piece num, Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Setting_Field_x(str);
    y1 = Setting_Field_y(str);
    x2 = Setting_Field_x2(str);
    y2 = Setting_Field_y2(str);
    if (Verific_Bishop(cl, str, y1, y2, x1, x2)) {
        cl->board[x1][y1] = None;
        cl->board[x2][y2] = num;
    } else
        printf("Your figure cannot walk like that");
}
void Move_Bishop(Board* cl, char* str, int num)
{
    switch (str[3]) {
    case '-':
        if (whose(num)) {
            Bishop_Walk(W_Bishop, cl, str);
        }
        if (!whose(num)) {
            Bishop_Walk(B_Bishop, cl, str);
        }
        break;
    case '#':
        if (whose(num)) {
            if (color_attack_Pawn_White(cl, str)) {
                Bishop_Walk(W_Rook, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        if (!whose(num)) {
            if (color_attack_Pawn_Black(cl, str)) {
                Bishop_Walk(B_Rook, cl, str);
            } else
                printf("You can't cut a piece of your color\nTry again\n\n");
        }
        break;
    }
}