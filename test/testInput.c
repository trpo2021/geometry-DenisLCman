#include "CheckInjectSpace.h"
#include <ctest.h>

CTEST(error_suite, error_not)
{
    const int errX = 0;
    const int errY = 0;
    const int errR = 0;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_TRUE(result);
}

CTEST(error_suite, error_x)
{
    const int errX = 1;
    const int errY = 0;
    const int errR = 0;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_y)
{
    const int errX = 0;
    const int errY = 1;
    const int errR = 0;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_r)
{
    const int errX = 0;
    const int errY = 0;
    const int errR = 1;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_shape)
{
    const int errX = 0;
    const int errY = 0;
    const int errR = 0;
    const int errShape = 1;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_x_y)
{
    const int errX = 1;
    const int errY = 1;
    const int errR = 0;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_x_r)
{
    const int errX = 1;
    const int errY = 0;
    const int errR = 1;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_x_shape)
{
    const int errX = 1;
    const int errY = 0;
    const int errR = 0;
    const int errShape = 1;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_y_r)
{
    const int errX = 0;
    const int errY = 1;
    const int errR = 1;
    const int errShape = 0;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_y_shape)
{
    const int errX = 0;
    const int errY = 1;
    const int errR = 0;
    const int errShape = 1;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}

CTEST(error_suite, error_r_shape)
{
    const int errX = 0;
    const int errY = 0;
    const int errR = 1;
    const int errShape = 1;
    const _Bool result = FormatCheck(errX, errY, errR, errShape);
    ASSERT_FALSE(result);
}
