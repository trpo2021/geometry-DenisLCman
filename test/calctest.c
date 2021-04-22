#include "Calc_Sq_Perim.h"
#include <ctest.h>

CTEST(calculations_suite, circle_square1)
{
    const double radius = 17.5;
    const double expected = radius * radius * PI;
    const double result = Calc_Sq_Perim(radius, 1);
    ASSERT_EQUAL(result, expected);
}
CTEST(calculations_suite, circle_square2)
{
    const double radius = 10.5;
    const double expected = radius * radius * PI;
    const double result = Calc_Sq_Perim(radius, 1);
    ASSERT_EQUAL(result, expected);
}
CTEST(calculatuin_suite, circle_perimeter1)
{
    const double radius = 17.5;
    const double expected = 2 * PI * radius;
    const double result = Calc_Sq_Perim(radius, 2);
    ASSERT_EQUAL(result, expected);
}
CTEST(calculatuin_suite, circle_perimeter2)
{
    const double radius = 5.5;
    const double expected = 2 * PI * radius;
    const double result = Calc_Sq_Perim(radius, 2);
    ASSERT_EQUAL(result, expected);
}
