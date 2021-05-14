#include <libchessviz/verification.h>

#include <ctest.h>

CTEST(verification_test, check_border)
{
    ASSERT_TRUE(check_border(" a2-a7"));
    ASSERT_TRUE(check_border(" b5-c1"));
    ASSERT_TRUE(check_border(" a4-h4"));
    ASSERT_TRUE(check_border(" a5-c2"));
    ASSERT_TRUE(check_border(" b1-c2"));
    ASSERT_TRUE(check_border(" h8-h8"));
    ASSERT_TRUE(check_border(" h4-h8"));
    ASSERT_TRUE(check_border(" e6-h8"));
    ASSERT_TRUE(check_border(" d8-g8"));
    ASSERT_TRUE(check_border(" f8-h7"));
    ASSERT_FALSE(check_border(" -1-a1"));
    ASSERT_FALSE(check_border(" a0-a1"));
    ASSERT_FALSE(check_border("&a1--1"));
    ASSERT_FALSE(check_border(" a0-a6"));
    ASSERT_FALSE(check_border(" i4-h3"));
    ASSERT_FALSE(check_border(" h9-h3"));
    ASSERT_FALSE(check_border(" h9-i8"));
}

CTEST(verification_test, isempty)
{
    Board cl;
    cl.board[3][4] = None;
    cl.board[4][3] = W_Pawn;

    ASSERT_TRUE(isempty(&cl, "Bd4-2f"));
    ASSERT_FALSE(isempty(&cl, "Be5-e4"));
}
CTEST(verification_test, pawn_isfirstmove)
{
    Board cl;
    cl.board[6][0] = B_Pawn;
    cl.board[5][0] = B_Pawn;
    cl.board[5][0] = B_Pawn;

    ASSERT_EQUAL(2, pawn_isfirstmove(&cl, " a2"));
    ASSERT_EQUAL(1, pawn_isfirstmove(&cl, " a3"));
    ASSERT_EQUAL(1, pawn_isfirstmove(&cl, " a5"));

    cl.board[1][0] = W_Pawn;
    cl.board[3][0] = W_Pawn;
    cl.board[5][0] = W_Pawn;

    ASSERT_EQUAL(2, pawn_isfirstmove(&cl, " a7"));
    ASSERT_EQUAL(1, pawn_isfirstmove(&cl, " a5"));
    ASSERT_EQUAL(1, pawn_isfirstmove(&cl, " a4"));
}
