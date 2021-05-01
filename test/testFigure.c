#include "FigureSection.h"
#include <ctest.h>

CTEST(intersection_suite, section_check1)
{
    struct Shape circle1;
    circle1.x = 3;
    circle1.y = 4;
    circle1.r = 5;
    struct Shape circle2;
    circle2.x = 3;
    circle2.y = 4;
    circle2.r = 5;
    const _Bool result = FigureSection(circle1, circle2);
    ASSERT_TRUE(result);
}

CTEST(intersection_suite, section_check2)
{
    struct Shape circle1;
    circle1.x = 4;
    circle1.y = 3;
    circle1.r = 3;
    struct Shape circle2;
    circle2.x = -3;
    circle2.y = 3;
    circle2.r = 3;
    const _Bool result = FigureSection(circle1, circle2);
    ASSERT_FALSE(result);
}

CTEST(intersection_suite, section_check3)
{
    struct Shape circle1;
    circle1.x = 4;
    circle1.y = 3;
    circle1.r = 1;
    struct Shape circle2;
    circle2.x = -3;
    circle2.y = 3;
    circle2.r = 1;
    const _Bool result = FigureSection(circle1, circle2);
    ASSERT_FALSE(result);
}

CTEST(intersection_suite, section_check4)
{
    struct Shape circle1;
    circle1.x = 100;
    circle1.y = 100;
    circle1.r = 3;
    struct Shape circle2;
    circle2.x = -100;
    circle2.y = -100;
    circle2.r = 3;
    const _Bool result = FigureSection(circle1, circle2);
    ASSERT_FALSE(result);
}
