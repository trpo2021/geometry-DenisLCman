#include "Calc_Sq_Perim.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Calc_Sq_Perim(double RShape, int type)
{
    if (type == 1) {
        return PI * RShape * RShape;
    } else {
        return PI * 2 * RShape;
    }
}