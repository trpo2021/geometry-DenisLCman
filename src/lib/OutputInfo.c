#include "OutputInfo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OutputInfo(
        char* shape,
        double xShape,
        double yShape,
        double RShape,
        double squarShape,
        double perimShape)
{
    printf("Figure - ");
    puts(shape);
    printf("X Figure - %f\n", xShape);
    printf("Y Figure - %f\n", yShape);
    printf("Radius Figure - %f\n", RShape);
    printf("Square Figure - %f\n", squarShape);
    printf("Perimetr Figure - %f\n", perimShape);
}