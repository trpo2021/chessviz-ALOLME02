#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_King_test, Verific_King)
{
    Board cl;
    char str[] = "Ka8-a2";
    ASSERT_FALSE(Verific_King(&cl, str, 0, 0, 0, 6));
    char str1[] = "Kd4-d5";
    ASSERT_TRUE(Verific_King(&cl, str1, 3, 3, 4, 3));
    char str2[] = "Kb4-e4";
    ASSERT_FALSE(Verific_King(&cl, str2, 1, 4, 4, 4));
    char str3[] = "Kd4-e5";
    ASSERT_TRUE(Verific_King(&cl, str3, 3, 4, 4, 3));
    char str4[] = "Kd4-a7";
    ASSERT_FALSE(Verific_King(&cl, str4, 3, 0, 4, 1));
    char str5[] = "Kd4-c3";
    ASSERT_TRUE(Verific_King(&cl, str5, 3, 2, 4, 5));
    char str6[] = "Kd4-e3";
    ASSERT_TRUE(Verific_King(&cl, str6, 3, 4, 4, 5));
    char str8[] = "Kd4-c5";
    ASSERT_TRUE(Verific_King(&cl, str8, 3, 2, 4, 3));
    char str7[] = "Kd4-c2";
    ASSERT_FALSE(Verific_King(&cl, str7, 3, 2, 4, 6));
    char str9[] = "Kd4-a1";
    ASSERT_FALSE(Verific_King(&cl, str9, 3, 0, 4, 7));
}