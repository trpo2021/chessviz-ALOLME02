#ifndef MOVE_KNIGHT_H
#define MOVE_KNIGHT_H

#include "board.h"
#include "verification.h"

void Knight_Walk(Piece num, Board* cl, char* str);
void Knight_Attack(Piece num, Board* cl, char* str);
void Move_Knight(Board* cl, char* str, int num);

#endif