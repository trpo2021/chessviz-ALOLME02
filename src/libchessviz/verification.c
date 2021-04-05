#include "verification.h"

bool isempty(Board* cl, char* str)
{
    if(str[3] == '-') {
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
bool my_figure(Board* cl, char* str, int num)
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
bool color_attack_Pawn_White(Board* cl,char* str)
{
    if(islower(point_after_move(cl, str))) {
        return true;

    } 
}
bool color_attack_Pawn_Black(Board* cl, char* str)
{
    if(isupper(point_after_move(cl, str))) {
        return true;
    }
}
int pawn_isfirstmove(Board* cl, char* str)
{
    if ((str[2] == '2' &&  islower(point_before_move(cl, str))) || (str[2] == '7'
        && isupper(point_before_move(cl, str)))) {
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
bool Pawn_Walk(Board* cl, char* str,int z, int w, int g,int q)
{
    if((abs(z - w) == 0) && (abs(g - q) <= 2)) {
        return true;
    } 
    return false;
}
bool attack_Pawn_Border_check(Board* cl, char* str,int z, int w, int g,int q)
{
    if ((abs(z-w)==1) &&(abs(g-q)==1))
    {
        return true;
    }
    return false;
}
bool check_border_piece(Board* cl, char* str)
{
    int x1;
    int y1;
    if (str[1] == 'a') y1 = 0;
    if (str[1] == 'b') y1 = 1;
	if (str[1] == 'c') y1 = 2;
	if (str[1] == 'd') y1 = 3;
	if (str[1] == 'e') y1 = 4;
	if (str[1] == 'f') y1 = 5;
	if (str[1] == 'g') y1 = 6;
	if (str[1] == 'h') y1 = 7;

    if (str[2] == '1') x1 = 7;
    if (str[2] == '2') x1 = 6;
	if (str[2] == '3') x1 = 5;
	if (str[2] == '4') x1 = 4;
	if (str[2] == '5') x1 = 3;
	if (str[2] == '6') x1 = 2;
	if (str[2] == '7') x1 = 1;
	if (str[2] == '8') x1 = 0;
    

    int x2;
    int y2;
    if (str[4] == 'a') y2 = 0;
    if (str[4] == 'b') y2 = 1;
	if (str[4] == 'c') y2 = 2;
	if (str[4] == 'd') y2 = 3;
	if (str[4] == 'e') y2 = 4;
	if (str[4] == 'f') y2 = 5;
	if (str[4] == 'g') y2 = 6;
	if (str[4] == 'h') y2 = 7;

    if (str[5] == '1') x2 = 7;
    if (str[5] == '2') x2 = 6;
	if (str[5] == '3') x2 = 5;
	if (str[5] == '4') x2 = 4;
	if (str[5] == '5') x2 = 3;
	if (str[5] == '6') x2 = 2;
	if (str[5] == '7') x2 = 1;
	if (str[5] == '8') x2 = 0;
    switch (str[0]) {
    case ' ':
        if (!P_check_border(cl, str)) {
            return false;
        } switch (str[3])
        {
        case '-': 
            if(!Pawn_Walk(cl, str, y1, y2, x1, x2 )) 
            return false;
            break;
        
        case '#':
            if(!attack_Pawn_Border_check(cl, str, y1, y2, x1, x2) )
            return false;
            break;
        }
        break;
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
    if (!my_figure(cl, str, num)) {
        printf("You are not walking with your shapes.\nTry again.\n\n");
        return false;
    }
    if (!check_border_piece(cl, str)) {
        printf("Incorrect move.\nTry again.\n\n");
        return false;
    }
    return true;
}