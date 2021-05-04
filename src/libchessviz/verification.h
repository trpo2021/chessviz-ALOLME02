#ifndef VERIFICATION_H
#define VERIFICATION_H

#define B_Y(x, y) x >= 'a' && x <= 'h' && y >= 'a' && y <= 'h'
#define B_X(x, y) x >= '1' && x <= '8' && y >= '1' && y <= '8'

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "board_type.h"
#include "board_type.h"
#include "board.h"

bool Verific_Bishop(Board* cl, char* str, int z, int w, int g, int q);
bool Verific_Rook(Board* cl, char* str, int z, int w, int g, int q);
bool Verific_King(Board* cl, char* str, int z, int w, int g, int q);
bool Verific_Queen(Board* cl, char* str, int z, int w, int g, int q);
bool Verific_Knight(Board* cl, char* str, int z, int w, int g, int q);
bool isempty(Board* cl, char* str);
bool check_border(char* str);
bool my_verific(Board* cl, char* str, int num);
bool whose(int num);
bool color_attack_Pawn_White(Board* cl, char* str);
bool color_attack_Pawn_Black(Board* cl, char* str);
int pawn_isfirstmove(Board* cl, char* str);
bool P_check_border(Board* cl, char* str);
bool Pawn_Walk(Board* cl, char* str, int z, int w, int g, int q);
bool attack_Pawn_Border_check(Board* cl, char* str, int z, int w, int g, int q);
bool check_border_piece(Board* cl, char* str);
bool input(Board* cl, char* str, int num);

#endif