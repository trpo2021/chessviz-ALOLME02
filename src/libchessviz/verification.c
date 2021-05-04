#include "verification.h"

bool isempty(Board* cl, char* str)
{
    if (str[3] == '-') {
        if (point_before_move(cl, str) == None) {
            return false;
        }
    }

    return true;
}
bool check_border(char* str)
{
    if (B_X(str[2], str[5]) && B_Y(str[1], str[4])) {
        return true;
    }
    return false;
}
bool my_verific(Board* cl, char* str, int num)
{
    if (num % 2 == 1 && isupper(point_before_move(cl, str))) {
        return true;
    }
    if (num % 2 == 0 && islower(point_before_move(cl, str))) {
        return true;
    }
    return false;
}

bool whose(int num)
{
    if (num % 2 == 1) {
        return true;
    } else {
        return false;
    }
}
bool color_attack_Pawn_White(Board* cl, char* str)
{
    if (islower(point_after_move(cl, str))) {
        return true;
    }
    return false;
}
bool color_attack_Pawn_Black(Board* cl, char* str)
{
    if (isupper(point_after_move(cl, str))) {
        return true;
    }
    return false;
}
int pawn_isfirstmove(Board* cl, char* str)
{
    if ((str[2] == '2' && islower(point_before_move(cl, str)))
        || (str[2] == '7' && isupper(point_before_move(cl, str)))) {
        return 2;
    }
    return 1;
}
bool P_check_border(Board* cl, char* str)
{
    if (abs(str[2] - str[5]) <= pawn_isfirstmove(cl, str)
        && abs(str[2] - str[5]) >= 1) {
        return true;
    }
    return false;
}
bool Pawn_Walk(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w) == 0) && (g - q <= 2)) {
        return true;
    }
    return false;
}
bool attack_Pawn_Border_check(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w) == 1) && (g - q == 1)) {
        return true;
    }
    return false;
}
bool Verific_Bishop(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w) == 1 && abs(g - q) == 1)
        || (abs(z - w) == 2 && abs(g - q) == 2)
        || (abs(z - w) == 3 && abs(g - q) == 3)
        || (abs(z - w) == 4 && abs(g - q) == 4)
        || (abs(z - w) == 5 && abs(g - q) == 5)
        || (abs(z - w) == 6 && abs(g - q) == 6)
        || (abs(z - w) == 7 && abs(g - q) == 7)
        || (abs(z - w) == 8 && abs(g - q) == 8)) {
        return true;
    }
    return false;
}
bool Verific_Rook(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w <= 8) && abs(q - g) == 0)
        || (abs(z - w == 0) && abs(q - g) <= 8)) {
        return true;
    }
    return false;
}
bool Verific_King(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w) == 1 && abs(q - g) == 0)
        || (abs(z - w) == 0 && abs(q - g) == 1)
        || (abs(z - w) == 1 && abs(g - q) == 1)) {
        return true;
    }
    return false;
}
bool Verific_Queen(Board* cl, char* str, int z, int w, int g, int q)
{
    if ((abs(z - w) == 1 && abs(g - q) == 1)
        || (abs(z - w) == 2 && abs(g - q) == 2)
        || (abs(z - w) == 3 && abs(g - q) == 3)
        || (abs(z - w) == 4 && abs(g - q) == 4)
        || (abs(z - w) == 5 && abs(g - q) == 5)
        || (abs(z - w) == 6 && abs(g - q) == 6)
        || (abs(z - w) == 7 && abs(g - q) == 7)
        || (abs(z - w) == 8 && abs(g - q) == 8)
        || (abs(z - w <= 8) && abs(q - g) == 0)
        || (abs(z - w == 0) && abs(q - g) <= 8)) {
        return true;
    }
    return false;
}
bool Verific_Knight(Board* cl, char* str, int z, int w, int g, int q)
{
    if (((abs(z - w) == 1) && (abs(g - q) == 2))
        || ((abs(z - w) == 2) && (abs(g - q) == 1))) {
        return true;
    }
    return false;
}
bool check_border_piece(Board* cl, char* str)
{
    int x1;
    int y1;
    int x2;
    int y2;
    x1 = Seting_Field_x(str);
    y1 = Seting_Field_y(str);
    x2 = Seting_Field_x2(str);
    y2 = Seting_Field_y2(str);
    switch (str[0]) {
    case ' ': {
        if (!P_check_border(cl, str)) {
            return false;
        }
        switch (str[3]) {
        case '-':
            if (!Pawn_Walk(cl, str, y1, y2, x1, x2))
                return false;
            break;

        case '#':
            if (!attack_Pawn_Border_check(cl, str, y1, y2, x1, x2))
                return false;
            break;
        }
        break;
    }
    case 'N': {
        if (!Verific_Knight(cl, str, y1, y2, x1, x2))
            return false;
        break;
    }
    case 'R': {
        if (!Verific_Rook(cl, str, y1, y2, x1, x2))
            return false;
        break;
    }
    case 'B': {
        if (!Verific_Bishop(cl, str, y1, y2, x1, x2))
            return false;
        break;
    }
    case 'K': {
        if (!Verific_King(cl, str, y1, y2, x1, x2))
            return false;
        break;
    }
    case 'Q': {
        if (!Verific_Queen(cl, str, y1, y2, x1, x2))
            return false;
        break;
    }
    }
    return true;
}
bool input(Board* cl, char* str, int num)
{
    if (!check_border(str)) {
        printf("Going beyond the board. \n Please try again. \n\n");
        return false;
    }
    if (!isempty(cl, str)) {
        printf("The first field is worthless. \n Try again. \n\n");
        return false;
    }
    if (!my_verific(cl, str, num)) {
        printf("You are not walking with your shapes.\nTry again.\n\n");
        return false;
    }
    if (!check_border_piece(cl, str)) {
        printf("Incorrect move.\nTry again.\n\n");
        return false;
    }
    return true;
}