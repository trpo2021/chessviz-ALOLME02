#ifndef BOARD_H
#define BOARD_H

#define MAX 21

#include "board_type.h"

#include <stdio.h>
#include <string.h>
void Visual_Board(Board* cl);
void Print_Board(Board* cl);
int Setting_Field_x(char* str, int number_str);
int Setting_Field_y(char* str, int number_str);
Piece point_before_move(Board* cl, char* str);
Piece point_after_move(Board* cl, char* str);
#endif