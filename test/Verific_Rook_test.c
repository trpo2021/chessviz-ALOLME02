#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_Rook_test, Verific_Rook)
{
    Board cl;
    char str[] = "Ra8-a2";
    ASSERT_TRUE(Verific_Rook(&cl, str, 0, 0, 0, 6));
    char str1[] = "Rd4-d5";
    ASSERT_TRUE(Verific_Rook(&cl, str1, 3, 3, 4, 3));
    char str2[] = "Rb4-e4";
    ASSERT_TRUE(Verific_Rook(&cl, str2, 1, 4, 4, 4));
    char str3[] = "Rd4-e5";
    ASSERT_FALSE(Verific_Rook(&cl, str3, 1, 4, 4, 3));
    char str4[] = "Rd4-a7";
    ASSERT_FALSE(Verific_Rook(&cl, str4, 3, 0, 4, 1));
    char str5[] = "Rd4-c3";
    ASSERT_FALSE(Verific_Rook(&cl, str5, 3, 2, 4, 5));
}
