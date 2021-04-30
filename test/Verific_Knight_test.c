#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_Knight_test, Verific_Knight)
{
    Board cl;
    char str[] = "Nd4-e6";
    ASSERT_TRUE(Verific_Knight(&cl, str, 3, 4, 4, 2));
    char str1[] = "Nd4-e2";
    ASSERT_TRUE(Verific_Knight(&cl, str1, 3, 4, 4, 6));
    char str2[] = "Nd4-c6";
    ASSERT_TRUE(Verific_Knight(&cl, str2, 3, 2, 4, 2));
    char str3[] = "Nd4-c2";
    ASSERT_TRUE(Verific_Knight(&cl, str3, 3, 2, 4, 6));
    char str4[] = "Nd4-b5";
    ASSERT_TRUE(Verific_Knight(&cl, str4, 3, 1, 4, 3));
    char str5[] = "Nd4-b3";
    ASSERT_TRUE(Verific_Knight(&cl, str5, 3, 1, 4, 5));
    char str6[] = "Nd4-f5";
    ASSERT_TRUE(Verific_Knight(&cl, str6, 3, 5, 4, 3));
    char str7[] = "Nd4-f3";
    ASSERT_TRUE(Verific_Knight(&cl, str7, 3, 5, 4, 5));
    char str8[] = "Nd4-d5";
    ASSERT_FALSE(Verific_Knight(&cl, str8, 3, 3, 4, 3));
    char str9[] = "Nb4-e4";
    ASSERT_FALSE(Verific_Knight(&cl, str9, 1, 4, 4, 4));
    char str10[] = "Bd4-e5";
    ASSERT_FALSE(Verific_Knight(&cl, str10, 3, 4, 4, 3));
    char str11[] = "Bd4-c5";
    ASSERT_FALSE(Verific_Knight(&cl, str11, 3, 2, 4, 3));
}