#include "move.h"

void Figure_Select_Move(Board* cl, char* str, int s)
{
    switch (str[0]) {
    case ' ':
        Move_Pawn(cl, str, s);
        break;
    case 'N':
        Move_Knight(cl, str, s);
        break;
    case 'R':
        Move_Rook(cl, str, s);
        break;
    case 'B':
        Move_Bishop(cl, str, s);
        break;
    case 'K':
        Move_King(cl, str, s);
        break;
    case 'Q':
        Move_Queen(cl, str, s);
        break;
    }
}

void Move(Board* cl)
{
    char str[MAX];
    int End = 0;
    int First_Count = 1, Second_Count = 0;
    while (End == 0) {
        ++Second_Count;
        printf("%d. ", First_Count);
        do {
            fgets(str, 21, stdin);
        } while (!input(cl, str, Second_Count));
        Figure_Select_Move(cl, str, Second_Count);
        if (First_Count * 2 == Second_Count) {
            ++First_Count;
        }
        Print_Board(cl);
    }
}
