#ifndef MOVE_ROOK_H
#define MOVE_ROOK_H

#include "board.h"
#include "verification.h"

void Rook_Walk(Piece num, Board* cl, char* str);
void Move_Rook(Board* cl, char* str, int num);

#endif