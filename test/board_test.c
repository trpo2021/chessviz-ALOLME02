#include <ctest.h>
#include <libchessviz/board.h>

CTEST(board_test, point_before_move)
{
    char str[] = "Re4-e5";
    Board cl;
    cl.board[4][4] = W_Rook;

    const Piece exp = W_Rook;
    const Piece real = point_before_move(&cl, str);

    ASSERT_EQUAL(exp, real);
}
CTEST(board_test, point_after_move)
{
    char str[] = "Re4-e5";
    Board cl;
    cl.board[3][4] = W_Rook;

    const Piece exp = W_Rook;
    const Piece real = point_after_move(&cl, str);

    ASSERT_EQUAL(exp, real);
}
