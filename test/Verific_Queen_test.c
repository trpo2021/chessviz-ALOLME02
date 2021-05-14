#include <libchessviz/verification.h>

#include <ctest.h>
CTEST(Verific_Queen_test, Verific_Queen)
{
    Board cl;
    char str[] = "Qa8-a2";
    ASSERT_TRUE(Verific_Queen(&cl, str, 0, 0, 0, 6));
    char str1[] = "Qd4-d5";
    ASSERT_TRUE(Verific_Queen(&cl, str1, 3, 3, 4, 3));
    char str2[] = "Qb4-e4";
    ASSERT_TRUE(Verific_Queen(&cl, str2, 1, 4, 4, 4));
    char str3[] = "Qd4-e5";
    ASSERT_TRUE(Verific_Queen(&cl, str3, 3, 4, 4, 3));
    char str4[] = "Qd4-c5";
    ASSERT_TRUE(Verific_Queen(&cl, str4, 3, 2, 4, 3));
    char str5[] = "Qd4-c3";
    ASSERT_TRUE(Verific_Queen(&cl, str5, 3, 2, 4, 5));
    char str6[] = "Qd4-e3";
    ASSERT_TRUE(Verific_Queen(&cl, str6, 3, 4, 4, 5));
    char str7[] = "Qa1-h8";
    ASSERT_TRUE(Verific_Queen(&cl, str7, 0, 7, 7, 0));
    char str8[] = "Qd4-b3";
    ASSERT_FALSE(Verific_Queen(&cl, str8, 3, 1, 4, 5));
    char str9[] = "Qd4-b5";
    ASSERT_FALSE(Verific_Queen(&cl, str9, 3, 1, 4, 3));
    char str10[] = "Qd4-f5";
    ASSERT_FALSE(Verific_Queen(&cl, str10, 3, 5, 4, 3));
    char str11[] = "Qd4-b3";
    ASSERT_FALSE(Verific_Queen(&cl, str11, 3, 5, 4, 5));
    char str12[] = "Qd4-e2";
    ASSERT_FALSE(Verific_Queen(&cl, str12, 3, 4, 4, 6));
    char str13[] = "Qd4-e6";
    ASSERT_FALSE(Verific_Queen(&cl, str13, 3, 4, 4, 2));
    char str14[] = "Qd4-c2";
    ASSERT_FALSE(Verific_Queen(&cl, str14, 3, 2, 4, 6));
    char str15[] = "Qd4-c6";
    ASSERT_FALSE(Verific_Queen(&cl, str15, 3, 2, 4, 2));
}