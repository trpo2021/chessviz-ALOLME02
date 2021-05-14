#ifndef MOVE_H
#define MOVE_H

#include "Move_Bishop.h"
#include "Move_King.h"
#include "Move_Knight.h"
#include "Move_Queen.h"
#include "Move_Rook.h"
#include "Move_pawn.h"
#include "verification.h"

void Figure_Select_Move(Board* cl, char* str, int s);
void Move(Board* cl);

#endif