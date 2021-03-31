#include "OutputError.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OutputError()
{
    if (ErrorShape > 0) {
        printf("Shape - Error!\n");
    }
    if (ErrorX > 0) {
        printf("X - Error!\n");
    }
    if (ErrorY > 0) {
        printf("Y - Error!\n");
    }
    if (ErrorR > 0) {
        printf("R - Error!\n");
    }
}