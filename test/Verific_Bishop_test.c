#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_Bishop_test, Verific_Bishop)
{
    Board cl;
    char str[] = "Bd4-e5";
    ASSERT_TRUE(Verific_Bishop(&cl, str, 3, 4, 4, 3));
    char str1[] = "Bd4-c5";
    ASSERT_TRUE(Verific_Bishop(&cl, str1, 3, 2, 4, 3));
    char str2[] = "Bd4-c3";
    ASSERT_TRUE(Verific_Bishop(&cl, str2, 3, 2, 4, 5));
    char str3[] = "Bd4-d5";
    ASSERT_FALSE(Verific_Bishop(&cl, str3, 3, 3, 4, 3));
    char str4[] = "Bd4-b5";
    ASSERT_FALSE(Verific_Bishop(&cl, str4, 3, 1, 4, 3));
    char str5[] = "Bd4-c4";
    ASSERT_FALSE(Verific_Bishop(&cl, str5, 3, 2, 4, 4));
    char str6[] = "Bd4-e3";
    ASSERT_TRUE(Verific_Bishop(&cl, str6, 3, 4, 4, 5));
    char str7[] = "Ba1-h8";
    ASSERT_TRUE(Verific_Bishop(&cl, str7, 0, 7, 7, 0));
}