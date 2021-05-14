#include <ctest.h>
#include <libchessviz/Move_Bishop.h>
#include <libchessviz/Move_King.h>
#include <libchessviz/Move_Knight.h>
#include <libchessviz/Move_Queen.h>
#include <libchessviz/Move_Rook.h>
#include <libchessviz/Move_pawn.h>

CTEST(move_test, King_Walk)
{
    Board cl;
    cl.board[0][4] = W_King;
    char str[] = "Ke8-e7";

    King_Walk(W_King, &cl, str);

    const Piece real = cl.board[0][4];
    const Piece real2 = cl.board[1][4];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_King, real2);
}
CTEST(move_test, Rook_Walk)
{
    Board cl;
    cl.board[0][0] = W_Rook;
    char str[] = "Ra8-a2";

    Rook_Walk(W_Rook, &cl, str);

    const Piece real = cl.board[0][0];
    const Piece real2 = cl.board[6][0];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_Rook, real2);
}
CTEST(move_test, Queen_Walk)
{
    Board cl;
    cl.board[0][3] = W_Queen;
    char str[] = "Qd8-f6";

    Queen_Walk(W_Queen, &cl, str);

    const Piece real = cl.board[0][3];
    const Piece real2 = cl.board[2][5];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_Queen, real2);
}
CTEST(move_test, Bishop_Walk)
{
    Board cl;
    cl.board[0][3] = W_Bishop;
    char str[] = "Bd8-f6";

    Bishop_Walk(W_Bishop, &cl, str);

    const Piece real = cl.board[0][3];
    const Piece real2 = cl.board[2][5];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_Bishop, real2);
}
CTEST(move_test, assigment)
{
    Board cl;
    cl.board[1][0] = W_Pawn;
    char str[] = " a7-a6";

    assigment(W_Pawn, &cl, str);

    const Piece real = cl.board[1][0];
    const Piece real2 = cl.board[2][0];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_Pawn, real2);
}
CTEST(move_test, Knight_Walk)
{
    Board cl;
    cl.board[0][6] = W_Knight;
    char str[] = "Ng8-f6";

    Knight_Walk(W_Knight, &cl, str);

    const Piece real = cl.board[0][6];
    const Piece real2 = cl.board[2][5];

    ASSERT_EQUAL(None, real);
    ASSERT_EQUAL(W_Knight, real2);
}