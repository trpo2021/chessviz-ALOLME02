#include <libchessviz/board.h>
#include <libchessviz/move.h>
int main()
{
    Board Board;
    Visual_Board(&Board);
    Print_Board(&Board);
    Move(&Board);
    return 0;
}