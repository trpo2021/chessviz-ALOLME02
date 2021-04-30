#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_Pawn_test, Pawn_Walk)
{
    Board cl;
    char str[] = " a2-a4";
    ASSERT_TRUE(Pawn_Walk(&cl, str, 0, 0, 6, 4));
    char str1[] = " a2-a3";
    ASSERT_TRUE(Pawn_Walk(&cl, str1, 0, 0, 6, 5));

    char str3[] = " a1-b2";
    ASSERT_FALSE(Pawn_Walk(&cl, str3, 0, 1, 7, 6));
    char str4[] = " a1-b1";
    ASSERT_FALSE(Pawn_Walk(&cl, str4, 0, 1, 7, 7));
    char str5[] = " a1-c3";
    ASSERT_FALSE(Pawn_Walk(&cl, str5, 0, 2, 7, 5));
}

CTEST(Verific_Pawn_test, attack_Pawn_Border_check)
{
    Board cl;
    char str[] = " a2#a4";
    ASSERT_FALSE(attack_Pawn_Border_check(&cl, str, 0, 0, 6, 4));
    char str1[] = " a2#a3";
    ASSERT_FALSE(attack_Pawn_Border_check(&cl, str1, 0, 0, 6, 5));

    char str3[] = " a1#b2";
    ASSERT_TRUE(attack_Pawn_Border_check(&cl, str3, 0, 1, 7, 6));
    char str4[] = " a1#b1";
    ASSERT_FALSE(attack_Pawn_Border_check(&cl, str4, 0, 1, 7, 7));
    char str5[] = " a1#c3";
    ASSERT_FALSE(attack_Pawn_Border_check(&cl, str5, 0, 2, 7, 5));
    char str6[] = " a1#b3";
    ASSERT_FALSE(attack_Pawn_Border_check(&cl, str6, 0, 1, 7, 5));
}